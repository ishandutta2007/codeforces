#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 55;
const int M = 5050;

long long dp[2][N][M];

bool remin(long long& what, long long x) {
	if (what == -1 || what > x) {
		what = x;
		return true;
	} else {
		return false;
	}
}

int main() {
	int n = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].first = nxt();
	}
	for (int i = 0; i < n; ++i) {
		a[i].second = nxt();
	}

	sort(all(a));
	reverse(all(a));
	// for (int i = 0; i < n; ++i) {
	// 	a[i].second *= -1;
	// }

	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;

	vector<pair<int, vector<int>>> ar;
	for (int i = 0; i < n; ++i) {
		if (i && a[i].first == a[i - 1].first) {
			int x = ar.back().second.back();
			ar.back().second.push_back(x + a[i].second);
		} else {
			ar.push_back({a[i].first, {0, a[i].second}});
		}
	}

	int cnt_less = 0;
	int max_denom = 0;
	int cur_memset = 0;
	int _ = 0;
	#define dp1 dp[_]
	#define dp2 dp[_ ^ 1]
	for (auto v : ar) {
		memset(dp2, -1, sizeof(dp2));
		/*cerr << v.first << " {";
		for (int i = 0; i < (int)v.second.size(); ++i) {
			if (i) {
				cerr << ", ";
			}
			cerr << v.second[i];
		}
		cerr << "}\n";*/
		// (old_k + (i - cnt_less) + 1) * 2 >= i + 1
		// 2 * old_k + i - 2 * cnt_less + 1 >= 0
		// 2 * old_k >= 2 * cnt_less - i - 1

		for (int k = cnt_less; 2 * k >= cnt_less && 2 * (k + (int)v.second.size() - 1) >= cnt_less + (int)v.second.size() - 1; --k) {
			for (int denom = max_denom + v.second.back(); denom >= 0; --denom) {
				for (int i = 0; i < (int)v.second.size(); ++i) {
					int new_k = k + i;
					if (2 * k < cnt_less + (int)v.second.size() - 1 - i || 2 * new_k < cnt_less + (int)v.second.size() - 1 || denom < v.second[i]) {
						continue;
					}
					if (dp1[k][denom - v.second[i]] == -1) {
						continue;
					}
					remin(dp2[new_k][denom], dp1[k][denom - v.second[i]] + 1ll * v.first * i);
						// cerr << new_k << " " << denom << " -> " << dp[new_k][denom] << "\n";
					// }
				}
			}
		}

/*		for (int i = 0; i < (int)v.second.size(); ++i) {
			for (int k = cnt_less; k >= (cnt_less + 1) / 2 && 2 * (k + i + 1) >= cnt_less + (int)v.size(); --k) {
				// cerr << "[" << i << ", " << k + i - cnt_less << "]\n";
				for (int denom = max_denom; denom >= 0; --denom) {
					if (dp[k + i - cnt_less][denom] == -1) {
						continue;
					}
					auto old = dp[k + i - cnt_less + 1][denom + a[i].second];
					remin(dp[k + i - cnt_less + 1][denom + a[i].second], dp[k + i - cnt_less][denom] + a[i].first);
					if (dp[k + i - cnt_less + 1][denom + a[i].second] != old) {
						cerr << "(" << i << ", " << k << ", " << denom << ", " << cnt_less << "): " << old << " -> " << dp[k + i - cnt_less][denom] << " + " << a[i].first << " = " << dp[k + i - cnt_less + 1][denom + a[i].second] << "\n";
					}
				}
			}
		}
*/
		max_denom += v.second.back();
		cnt_less += (int)v.second.size() - 1;

		while (cur_memset * 2 < cnt_less) {
			memset(dp2[cur_memset], -1, sizeof(dp2[cur_memset]));
			++cur_memset;
		}
		_ ^= 1;
	}

	long long ans = LLONG_MAX;
	for (int d = 1; d <= max_denom; ++d) {
		for (int k = (n + 1) / 2; k <= n; ++k) {
			if (dp[_][k][d] == -1) {
				continue;
			}
			long long cand = (dp[_][k][d] * 1000 + d - 1) / d;
			ans = min(ans, cand);
		}
	}

	cout << ans << "\n";

	return 0;
}