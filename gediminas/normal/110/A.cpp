/*input
1000000000000000000

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	long long x;
	cin >> x;
	int c = 0;

	while (x > 0) {
		if (x % 10 == 4 or x % 10 == 7)
			c++;

		x /= 10;
	}

	if (c == 0) {
		cout << "NO";
		return 0;
	}

	while (c > 0) {
		if (c % 10 != 4 and c % 10 != 7) {
			cout << "NO";
			return 0;
		}

		c /= 10;
	}

	cout << "YES";

	return 0;
}