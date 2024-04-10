#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(...) {\
    std::cout << "[" << __FUNCTION__ << ":" << __LINE__ << "] " << #__VA_ARGS__ << " "  << __VA_ARGS__ << std::endl;\
    }
#else
#define debug(...)
#endif
/*inpsut
1
*/
/*input
8
2
1 7
3
1 2 4
4
5 5 5 5
5
6 2 2 1 0
1
0
1
1
6
1 12 123 1234 12345 123456
5
536870912 536870911 1152921504606846975 1152921504606846974 1152921504606846973
*/
const long long mod = 1000000007;
#define MOD(x) ((x)%mod)
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		long long n;
		cin >> n;
		// n = 500000;
		vector<long long> x(n);
		long long kiek2[61][61][2] = {};
		long long kiek[61] = {};

		for (int o = 0; o < n; ++o) {
			cin >> x[o];
			// x[o] = (1ll << 61) - 1;

			for (int i = 0; i < 61; ++i) {
				long long dp = (1ll << i);

				if (x[o]&dp) {
					kiek[i]++;

					for (int j = 0; j < 61; ++j) {
						long long dpj = (1ll << j);

						if (x[o]&dpj) {
							kiek2[i][j][1]++;
						}
						else {
							kiek2[i][j][0]++;
						}
					}
				}
			}
		}

		long long ans = 0;

		for (int i = 0; i < 61; ++i) {
			long long dpi = MOD(1ll << i);

			for (int j = 0; j < 61; ++j) {
				long long dpj = MOD(1ll << j);
				long long dpvis = MOD(dpi * dpj);
				ans += MOD(MOD(MOD(kiek[i] * kiek2[i][j][1]) * n) * dpvis);
				ans += MOD(MOD(MOD(kiek[i] * kiek2[i][j][0]) * kiek[j]) * dpvis);
				ans = MOD(ans);
			}
		}

		cout << ans << "\n";
	}

}