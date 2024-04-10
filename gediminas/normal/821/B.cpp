/*input
6 3
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	long long m, b;
	cin >> m >> b;
	long long ats = 0;
	long long x = 0;

	while (-x / m - (x % m > 0) + b >= 0) {
		long long y = -x / m - (x % m > 0) + b;
		ats = max(ats, (x + y) * (y + 1) * (x + 1) / 2);
		//cout << x << " " << y << " " << ((x + y) * (y + 1) * (x + 1)) / 2 << endl;
		x++;
	}

	cout << ats << endl;
	return 0;
}