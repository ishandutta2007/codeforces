#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int L, R; cin >> L >> R;
		ll dp[2][2][2][2]; // equal or not
		memset(dp, 0, sizeof(dp));
		dp[1][1][1][1] = 1;
		for (int i = 30; i >= 0; i--) {
			ll ndp[2][2][2][2];
			memset(ndp, 0, sizeof(ndp));
			int lv = bool(L & (1 << i));
			int rv = bool(R & (1 << i));
			for (int ael = 0; ael < 2; ael++) {
				for (int aer = 0; aer < 2; aer++) {
					for (int bel = 0; bel < 2; bel++) {
						for (int ber = 0; ber < 2; ber++) {
							for (int av = 0; av < 2; av++) {
								for (int bv = 0; bv < 2; bv++) {
									if (av && bv) continue;
									if (ael && av < lv) continue;
									if (aer && av > rv) continue;
									if (bel && bv < lv) continue;
									if (ber && bv > rv) continue;
									ndp[ael && av == lv][aer && av == rv][bel && bv == lv][ber && bv == rv] += dp[ael][aer][bel][ber];
								}
							}
						}
					}
				}
			}
			memcpy(dp, ndp, sizeof(dp));
		}
		ll ans = 0;
		for (int x = 0; x < 2; x++) {
			for (int y = 0; y < 2; y++) {
				for (int z = 0; z < 2; z++) {
					for (int w = 0; w < 2; w++) {
						ans += dp[x][y][z][w];
					}
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}