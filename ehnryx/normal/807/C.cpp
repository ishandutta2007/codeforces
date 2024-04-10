#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, x, y, p, q, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> p >> q;
		if (p == 0) {
			if (x == 0) cout << 0 << endl;
			else cout << -1 << endl;
		}
		else if (p == q) {
			if (x == y) cout << 0 << endl;
			else cout << -1 << endl;
		}
		else {
			a = max((y-x)/(q-p) + (((y-x)%(q-p)) ? 1 : 0), x/p + ((x%p) ? 1 : 0));
			cout << a*q-y << endl;
		}
	}
	return 0;
}