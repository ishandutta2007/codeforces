/*input
8
6 8 3 4 7 2 1 5

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	bool mas[n] = {};

	int poin = n - 1;
	cout << "1 ";

	for (int kiekis = 1; kiekis <= n; kiekis++) {
		int x;
		cin >> x;
		x--;
		mas[x] = true;

		while (poin >= 0 and mas[poin])
			poin--;

		cout << kiekis - (n - poin - 1) + 1 << " ";
	}


	return 0;
}