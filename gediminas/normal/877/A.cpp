/*input
Danil_and_Olya


*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	string names[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
	string prob;
	cin >> prob;
	int c = 0;

	for (int i = 0; i < prob.size(); i++) {
		for (int j = 0; j < 5; j++) {
			if (i + names[j].size() <= prob.size())
				c += prob.substr(i, names[j].size()) == names[j];
		}
	}

	cout << (c==1?"YES":"NO");


	return 0;
}