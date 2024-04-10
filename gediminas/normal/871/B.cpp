/*input
4

*/
#include <bits/stdc++.h>

using namespace std;

int uzkl(int i, int j) {
	cout << "? " << i << " " << j << "\n" << flush;
	int x;
	cin >> x;
	return x;
	/*int a[] = {0, 1, 2, 3};
	return a[i] ^ a[j];*/
}

int main () {
	int n;
	cin >> n;

	if (n == 1) {
		cout << "!\n1\n0\n" << flush;
		return 0;
	}

	int pild[n];

	for (int j = 0; j < n; j++)
		pild[j] = uzkl(0, j);

	int sav[n];

	for (int j = 0; j < n; j++)
		sav[j] = uzkl(j, j);

	int b[n];
	int p[n];
	int gal[n];
	int kie = 0;

	for (int x = 0; x < n; x++) {
		p[0] = x;

		bool ar = true;

		for (int i = 0; i < n and ar; i++) {
			b[i] = pild[i] ^ x;
			ar &= (0 <= b[i] and b[i] < n);
		}

		ar &= ((p[0] ^ b[0]) == pild[0]);

		for (int i = 0; i < n and ar; i++)
			p[b[i]] = i;

		ar &= (p[0] == x);

		for (int i = 0; i < n and ar; i++)
			ar &= ((p[i] ^ b[i]) == sav[i]);

		if (ar) {
			/*for (int i = 0; i < n; i++)
				cout << p[i] << " ";

			cout << endl;*/

			if (kie == 0) {
				for (int i = 0; i < n; i++)
					gal[i] = p[i];
			}

			kie++;
		}
	}

	cout << "!\n" << kie << "\n";

	for (int i = 0; i < n; i++)
		cout << gal[i] << " ";

	cout << flush;

	return 0;
}