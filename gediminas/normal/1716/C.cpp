#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
4
3
0 0 1
4 3 2
5
0 4 8 12 16
2 6 10 14 18
4
0 10 10 10
10 10 10 10
2
0 0
0 0
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;

	for (int TESTT = 0; TESTT < TESTS; ++TESTT) {
		long long n;
		cin >> n;
		long long a[2][n];
		long long va[n] = {}, sp[n] = {};

		for (int t = 0; t < 2; ++t) {
			for (int i = 0; i < n; ++i) {
				cin >> a[t][i];

				if (i + t > 0) {
					a[t][i]++;
				}
			}
		}

		va[n - 1] = max(a[0][n - 1], a[1][n - 1] - 1);
		sp[n - 1] = max(a[1][n - 1], a[0][n - 1] - 1);

		for (int i = n - 2; i >= 0; --i) {
			va[i] = max(max(a[0][i], va[i + 1] - 1), a[1][i] - 2 * (n - 1 - i) - 1);
			sp[i] = max(max(a[1][i], sp[i + 1] - 1), a[0][i] - 2 * (n - 1 - i) - 1);
		}

		debug(dbgarr(va, n));
		debug(dbgarr(sp, n));

		long long ans = n + n - 1 + va[0];
		long long dab = 0;
		long long vis = 0;

		debug(ans);

		for (int i = 0; i < n; ++i) {
			vector<int> T = {i % 2, 1 - i % 2};

			for (auto &&t : T) {
				dab = max(dab, a[t][i] - vis);

				if (i != n - 1) {
					long long cur = ans;

					if (i % 2 != t) {
						cur = max(dab + vis, (t == 0 ? va[i + 1] : sp[i + 1]) - 1) + 2 * (n - 1 - i);
					}
					else {
						debug(dab + vis, (t == 0 ? va[i + 1] : sp[i + 1]), a[1 - t][i]);
						cur = max(dab + vis, max((t == 0 ? va[i + 1] : sp[i + 1]), a[1 - t][i]) - 1) + 2 * (n - 1 - i) + 1;
					}

					ans = min(ans, cur);
					debug(dab, ans, cur);
				}

				vis++;
			}
		}

		debug(dab);

		ans = min(ans, dab + n + n - 1);


		cout << ans << "\n";
	}
}