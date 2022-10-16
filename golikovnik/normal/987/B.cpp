#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(12); cout << fixed;
	long double x, y;
	cin >> x >> y;
	long double x1 = y * logl(x), y1 = x * logl(y);
	if (fabsl(x1 - y1) < 1e-9) {
		cout << "=";
	} else if (x1 < y1) {
		cout << "<";
	} else {
		cout << ">";
	}
	cout << "\n";
	return 0;
}