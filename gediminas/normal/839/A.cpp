/*input
1 9
10

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, k;
	cin >> n >> k;
	int tur = 0;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		tur += a;
		k -= min(8, tur);
		tur -= min(8, tur);

		if (k <= 0) {
			cout << i + 1;
			return 0;
		}
	}

	cout << -1;
	return 0;
}