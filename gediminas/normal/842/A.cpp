/*input

1 10 1 10 1

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	long long l, r, x, y, k;
	cin >> l >> r >> x >> y >> k;
	bool ar = false;

	for (long long i = l; i <= r; i++) {
		long long tur = i / k;

		if (x <= tur and tur <= y and i / tur == k and i % tur == 0 and i % k == 0) {
			ar = true;
			break;
		}
	}

	cout << (ar ? "YES" : "NO");


	return 0;
}