/* Sara Hautamäki, Harjoitustyö
Yritän 2-3 pisteen ohjelmaa  */


#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

int lisaaHuoneenvaraus(vector<int>& huoneetTaulukko, int maxHuoneita) {
	
	while (true) {

		// Arvotaan huoneen numero
		int huoneNro = 1 + (rand() % maxHuoneita);
		// Jos arvottu huoneen numero ei löydy taulukosta se lisätään sinne. Näin varatut huonenumerot ovat uniikkeja
		if (find(huoneetTaulukko.begin(), huoneetTaulukko.end(), huoneNro) == huoneetTaulukko.end()) {

			// Aliohjelma lisää huonenumeron taulukkoon
			// Aliohjelma laajennettavissa myös asiakkaan nimen ja tilausnumeron lisäämiseksi
			huoneetTaulukko.push_back(huoneNro);
			return huoneNro;
		}
	}
}


int main() {

	setlocale(LC_ALL, "FI_fi");

	int kaikkiHuoneet;		// Arvottujen huoneiden määrä väliltä 30-70
	int hintaPerYo;			// Arvottu yön hinta 80-100 e väliltä
	int huoneidenMaara;		// Kuinka monta huonetta varaaja haluaa
	int vierailunKesto;		// Kuinka monta yötä vierailu kestää
	int lasku;				// Huoneiden määrä * öiden määrä * yön hinta
	string varaajanNimi;	// Millä nimellä varaus tehdään
	int huoneNro;			// Huoneen arrvottu numero
	string varataan;



	// Arvotaan huoneiden lukumäärä 30-70 väliltä
	srand(time(0));
	kaikkiHuoneet = 30 + (rand() % 41);
	
	// Luodaan vektori, johon aliohjelmassa laitetaan huoneen numerot
	vector<int>huoneetTaulukko;

	// Menu
	cout << "Tervetuloa!\n";

	cout << "Hotellissa on " << kaikkiHuoneet << " huonetta\n\n";

	cout << "Millä nimellä varaus tehdään: ";
	 getline(cin, varaajanNimi);
	
	cout << "Kuinka monta yötä haluatte viipyä: ";
	//virheen tarkistus, idea kopioitu w3school "c++ input validation" toteutuksesta
	while (!(cin >> vierailunKesto)) {
		cout << "syötä vain numeroita:";
		cin.clear();
		cin.ignore(10000, '\n');
	}

	// Huoneita voi varata, kunnes hotelli on täynnä
	while (huoneetTaulukko.size() < kaikkiHuoneet) {
		
		int huoneNro = lisaaHuoneenvaraus(huoneetTaulukko, kaikkiHuoneet);

		// Lasketaan vapaana olevien huoneiden määrä
		int tyhjatAlkiot = kaikkiHuoneet - huoneetTaulukko.size();

		cout << "\nHuoneenne numero on: " << huoneNro << "\n\n" << "Tyhjiä huoneita on jäljellä " << tyhjatAlkiot << " kappaletta\n";
	
		// Haluaako käyttäjä lisää huoneita. Syötteen tarkistus jälleen löydetty netistä keskustelupalstalta
		while (true) {
			cout << "Haluatko varata lisää huoneita? ( K / E ): ";
			cin >> varataan;

			for (char& c : varataan) c = tolower(c);
			if (varataan == "k" || varataan == "e") {
				break;
			}
			else {
				cout << "Vastus väärässä muodossa\n";
			}
			
		}

		if (varataan != "k")
			break;
	}

	// Loppukoonti varauksesta
	cout << "\n\nVaraajan nimi: " << varaajanNimi << "\n"
		<< "Olet varannut huoneet: ";
	for (int huoneet : huoneetTaulukko)
		cout << huoneet << " ";
		
	cout << "\nViipymisen kesto: " << vierailunKesto << " yötä\n";

	//Arvotaan yön hinta 80-100 väliltä
	hintaPerYo = 80 + (rand() % 21);

	//lasketaan loppulasku
	lasku = hintaPerYo * vierailunKesto * huoneetTaulukko.size();

	cout << "Yhden huoneen hinta on: " << hintaPerYo << " euroa/yö\n";

	cout << "\nKokonaishinta vierailulle on: " << lasku << " euroa\n";


	return 0;
}