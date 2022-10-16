/*input
3 15

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, a;
	cin >> n >> a;
	int ats = 3;

	long double x = 180.0 * (n - 2) / n;

	int i = max(round(-2.0 * a / (180 - x)) + n,2.0l);

	cout << n << " " << 1 << " " << (i==n?n-1:i);

	return 0;
}