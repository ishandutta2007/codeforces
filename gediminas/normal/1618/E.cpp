#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

const long long infty = 1000000000000000ll;

/*input
4
3
12 16 14
1
1
3
1 2 3
6
81 75 75 93 93 87
*/


int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		long long a[n];

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		long long dd[n];

		bool gal = true;

		for (int i = 0; i < n - 1; ++i) {
			dd[i] = a[(i - 1 + n) % n] + a[(i + 1) % n] - 2 * a[i];

			if (dd[i] % n != 0) {
				gal = false;
			}

			dd[i] /= -n;
		}

		long long tt = 0;

		for (int i = 1; i < n; ++i) {
			tt += (n - i) * (n - i + 3) / 2 * dd[i - 1];
		}

		long long mul = ((n + 1) * n / 2);

		if ((a[0] - tt) % mul != 0) {
			gal = false;
		}

		long long a1 = (a[0] - tt) / mul;

		if (a1 <= 0) {
			gal = false;
		}

		long long aa = a1;

		for (int i = 0; i < n - 1; ++i) {
			aa += dd[i];

			if (aa <= 0) {
				gal = false;
			}
		}

		if (gal) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
			continue;
		}

		cout << a1 << " ";

		for (int i = 0; i < n - 1; ++i) {
			a1 += dd[i];
			cout << a1 << " ";
		}

		cout << "\n";
	}
}