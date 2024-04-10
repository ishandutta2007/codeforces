/*input
5
1
2
3
4
8
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		long long x;
		cin >> x;

		if (x % 4 == 0 and x >= 4)
			cout << x / 4 << "\n";
		else if (x % 4 == 1 and x >= 9)
			cout << 1 + (x - 9) / 4 << "\n";
		else if (x % 4 == 2 and x >= 6)
			cout << 1 + (x - 6) / 4 << "\n";
		else if (x % 4 == 3 and x >= 15)
			cout << 2 + (x - 15) / 4 << "\n";
		else
			cout << -1 << "\n";
	}

	return 0;
}