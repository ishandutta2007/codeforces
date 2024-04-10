/*input
5 2

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	long long n, m;
	cin >> n >> m;

	if (m > n) {
		cout << n;
		return 0;
	}

	long long x = ceil((sqrtl(8.0l * n - 8.0l * m + 1.0l) - 1.0l) / 2.0l);
	cout << x + m;

	return 0;
}