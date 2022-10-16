#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int naud[n]={};
	int prad[n];

	for (int i = 0; i < n; i++)
		cin >> prad[i];

	int d = 0;
	bool pirm = true;

	while (d != 0 or pirm) {
		pirm = false;

		for (int i = 0; i < n; i++) {
			if (d != 6)
				naud[i]++;

			d = (d + 1) % 7;
		}
	}

	int mi = 1000000000;

	for (int i = 0; i < n; i++) {
		if (naud[i] != 0)
			mi = min(mi, (prad[i] - 1) / naud[i]);
	}

	for (int i = 0; i < n; i++)
		prad[i] -= mi * naud[i];

	while (1) {
		for (int i = 0; i < n; i++) {
			if (d != 6)
				prad[i]--;

			if (prad[i] == 0) {
				cout << i+1;
				return 0;
			}

			d = (d + 1) % 7;
		}
	}

	return 0;
}