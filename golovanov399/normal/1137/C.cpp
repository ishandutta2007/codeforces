#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

struct Graph {
	int n;
	vector<vector<int>> g;
	vector<vector<int>> g_tr;

	Graph(int _n): n(_n), g(_n), g_tr(_n) {}

	void addEdge(int u, int v) {
		g[u].push_back(v);
		g_tr[v].push_back(u);
	}

	vector<char> used;
	vector<int> order;

	void dfs(int v) {
		used[v] = 1;
		for (int x : g[v]) {
			if (!used[x]) {
				dfs(x);
			}
		}
		order.push_back(v);
	}

	void backDfs(int v, vector<int>& comp) {
		used[v] = 1;
		comp.push_back(v);
		for (int x : g_tr[v]) {
			if (!used[x]) {
				backDfs(x, comp);
			}
		}
	}

	vector<vector<int>> getScc() {
		used.assign(n, false);
		order.clear();
		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				dfs(i);
			}
		}
		reverse(all(order));
		vector<vector<int>> comps;
		used.assign(n, false);
		for (int x : order) {
			if (!used[x]) {
				comps.push_back({});
				backDfs(x, comps.back());
			}
		}
		return comps;
	}
};

const int N = 111111;
const int D = 55;
char eused[N][D];
int dp[N][D];
char cur_work[N][D];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	cin.sync_with_stdio(0);

	int n = nxt(), m = nxt(), d = nxt();
	Graph ordinary(n), extended(n * d);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		ordinary.addEdge(u, v);
	}

	auto scc = ordinary.getScc();

	vector<int> ord_comp_num(n);
	for (int i = 0; i < (int)scc.size(); ++i) {
		for (int v : scc[i]) {
			ord_comp_num[v] = i;
		}
	}
	vector<int> smol(n);

	vector<string> work(n);
	for (int i = 0; i < n; ++i) {
		cin >> work[i];
	}

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	int ans = 0;

	for (const auto& comp : scc) {
		int escc = 0;
		vector<pair<int, int>> st = {{comp[0], 0}};
		eused[comp[0]][0] = 1;
		while (!st.empty()) {
			auto [v, i] = st.back();
			smol[v] = i;
			st.pop_back();
			++escc;
			int j = i + 1;
			if (j == d) {
				j = 0;
			}
			for (int x : ordinary.g[v]) {
				if (ord_comp_num[x] != ord_comp_num[v]) {
					continue;
				}
				if (!eused[x][j]) {
					eused[x][j] = 1;
					st.push_back({x, j});
				}
			}
		}
		assert(escc % comp.size() == 0);
		int p = escc / comp.size();
		p = d / p;
		for (int x : comp) {
			smol[x] %= p;
		}

		for (int x : comp) {
			for (int i = 0; i < d; ++i) {
				if (work[x][i] == '1') {
					cur_work[x][i % p] = 1;
				}
			}
		}

		vector<int> this_comp(p);
		for (int x : comp) {
			for (int i = 0; i < p; ++i) {
				int rem = i - smol[x];
				if (rem < 0) {
					rem += p;
				}
				this_comp[rem] += cur_work[x][i];
			}
		}

		vector<int> cur_dp(p, -1);
		for (int x : comp) {
			for (int i = 0; i < d; ++i) {
				if (dp[x][i] == -1) {
					continue;
				}
				int rem = i % p - smol[x];
				if (rem < 0) {
					rem += p;
				}
				cur_dp[rem] = max(cur_dp[rem], dp[x][i] + this_comp[rem]);
				ans = max(ans, cur_dp[rem]);
			}
		}

		for (int v : comp) {
			for (int x : ordinary.g[v]) {
				if (ord_comp_num[x] != ord_comp_num[v]) {
					for (int i = 0; i < d; ++i) {
						int rem = i % p - smol[v];
						if (rem < 0) {
							rem += p;
						}

						if (cur_dp[rem] > -1) {
							dp[x][(i + 1) % d] = max(dp[x][(i + 1) % d], cur_dp[rem]);
						}
					}
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}