/*input
2
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	string a;
	cin >> a;
	int mas[3] = {};

	for (auto && i : a) {
		if (i != '+')
			mas[i - '1']++;
	}

	bool ar = false;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < mas[i]; j++) {
			cout << (ar ? "+" : "") << i + 1;
			ar = true;
		}
	}


	return 0;
}