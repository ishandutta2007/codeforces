/*input
5 10 1
1
1
1
1
1
1

*/
#include <bits/stdc++.h>

using namespace std;

bool geras(int *a, int *b) {
	int *c = a;

	while (c != b) {
		if (*c < 0)
			return false;

		c++;
	}

	return is_sorted(a, b);
}

int main () {
	int n, m, c;
	cin >> n >> m >> c;

	/*if (c == 1) {
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cout << i + 1 << "\n" << flush;
		}

		return 0;
	}*/

	int pild[c] = {};

	for (int i = 0; i < c / 2; i++)
		pild[i] = 0;

	for (int i = c / 2; i < c; i++)
		pild[i] = n - 1;

	int mas[n];

	for (int i = 0; i < n; i++)
		mas[i] = -1 - i;

	while (!geras(mas, mas + n)) {
		int x;
		cin >> x;
		x--;
		cout << pild[x] + 1 << "\n" << flush;
		mas[pild[x]] = x;

		if (x >= c / 2) {
			pild[x]--;

			for (int i = c / 2; i < x; i++)
				pild[i] = min(pild[x], pild[i]);
		}
		else {
			pild[x]++;

			for (int i = x; i < c / 2; i++)
				pild[i] = max(pild[x], pild[i]);
		}
	}


	return 0;
}