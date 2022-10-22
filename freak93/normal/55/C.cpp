#include <iostream>

using namespace std;

int n, i, m, k, x, y, rez;

int main() {
	cin >> n >> m >> k;
	rez = 5000;
	for (i = 1; i <= k; ++i)
		cin >> x >> y, rez = min(rez, x - 1), rez = min(rez, n - x), rez = min(rez, y - 1), rez = min(rez, m - y);

	if (rez <= 4)
		cout << "YES\n";
	else
		cout << "NO\n";
}