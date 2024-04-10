#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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

struct Edge {
	int to;
	int cost;

	bool operator <(const Edge& ot) const {
		return make_pair(to, cost) < make_pair(ot.to, ot.cost);
	}
};

int main(){
	int n = nxt(), k = nxt();
	int m = nxt();
	vector<vector<Edge>> a(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1, c = nxt();
		a[u].push_back({v, c});
	}

	for (int i = 0; i < n; ++i) {
		sort(all(a[i]));
	}

	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 90000)));
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			for (int ij = i; ij <= j; ++ij) {
				dp[i][j][ij] = 0;
			}
		}
	}
	auto tmp = dp;

	while (--k) {
		for (int l = 0; l < n; ++l) {
			for (int r = l; r < n; ++r) {
				for (int i = l; i <= r; ++i) {
					tmp[l][r][i] = 90000;
				}
			}
		}
		for (int u = 0; u < n; ++u) {
			for (const Edge& ed : a[u]) {
				int v = ed.to;
				if (v < u) {
					for (int l = 0; l <= v; ++l) {
						for (int r = u; r < n; ++r) {
							tmp[l][r][u] = min(tmp[l][r][u], ed.cost + dp[l][u - 1][v]);
						}
					}
				} else {
					for (int l = 0; l <= u; ++l) {
						for (int r = v; r < n; ++r) {
							tmp[l][r][u] = min(tmp[l][r][u], ed.cost + dp[u + 1][r][v]);
						}
					}
				}
			}
		}
		tmp.swap(dp);
	}

	int ans = 90000;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			ans = min(ans, *min_element(all(dp[i][j])));
		}
	}
	if (ans == 90000) {
		puts("-1");
	} else {
		printf("%d\n", ans);
	}

	return 0;
}