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

/*input
5
4
1 2 3 4
4
1 1 2 2
2
0 -1
6
3 -2 4 -1 -4 0
1
-100
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int tt;
	cin >> tt;

	while (tt--) {
		int n;
		cin >> n;
		vector<long long> a(n);

		for (auto &&x : a) {
			cin >> x;
		}

		long long ans = max(0, n - 2);

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				long long t = 0;

				for (int k = 0; k < n; ++k) {
					if ((a[k] - a[i]) * (j - i) != (a[j] - a[i]) * (k - i)) {
						t++;
					}
				}

				ans = min(ans, t);
			}
		}

		cout << ans << "\n";
	}

}