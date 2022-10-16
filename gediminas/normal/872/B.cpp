/*input
5 2
1 2 3 5 4

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, k;
	cin >> n >> k;

	if (k == 1) {
		int ats;
		cin >> ats;

		for (int i = 1; i < n; i++) {
			int x;
			cin >> x;
			ats = min(ats, x);
		}

		cout << ats;
	}
	else if (k >= 3) {
		int ats;
		cin >> ats;

		for (int i = 1; i < n; i++) {
			int x;
			cin >> x;
			ats = max(ats, x);
		}

		cout << ats;
	}
	else if (k == 2) {
		int mas[n];

		for (int i = 0; i < n; i++)
			cin >> mas[i];

		int ats = mas[0];
		int te = mas[0];

		for (int i = 0; i < n; i++) {
			te = min(mas[i], te);
			ats = max(ats, te);
		}

		te = mas[n - 1];

		for (int i = n - 1; i >= 0; i--) {
			te = min(mas[i], te);
			ats = max(ats, te);
		}

		cout << ats;
	}


	return 0;
}