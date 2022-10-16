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
5
5
1 2 3 4 5
3
10 5 15
3
100 10 200
10
9 8 2 6 6 2 8 6 5 4
2
1 3
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

		long long tt = 0;

		for (int bb = 0; bb < 2; ++bb) {
			bool t = true;
			long long gc = a[bb];

			for (int i = bb; i < n; i += 2) {
				gc = gcd(gc, a[i]);
			}

			for (int i = 1 - bb; i < n; i += 2) {
				if (a[i] % gc == 0) {
					t = false;
					break;
				}
			}

			if (t) {
				tt = gc;
			}
		}

		cout << tt << "\n";
	}
}