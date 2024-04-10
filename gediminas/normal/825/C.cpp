/*input
4 20
10 3 6 3

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, k;
	cin >> n >> k;
	int mas[n];

	for (int i = 0; i < n; i++)
		cin >> mas[i];

	sort(mas, mas + n);
	int ats = 0;

	for (int i = 0; i < n; i++) {
		while (k < mas[i] / 2 + mas[i] % 2) {
			ats++;
			k *= 2;
		}

		k = max(k, mas[i]);
	}

	cout << ats;
	return 0;
}