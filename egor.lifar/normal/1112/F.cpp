#include <bits/stdc++.h>

using namespace std;
template<class T1, class T2> inline void chkmin(T1 &x, T2 const &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, T2 const &y) {if (x < y) x = y;}
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define left left228
#define right right228
const int MAXN = 200228;


int n;
int c[MAXN];
vector<int> g[MAXN];
vector<int> who[MAXN];
vector<int> v[MAXN];

void dfs(int u, int pr, pair<int, vector<int> > &z) {
	int cnt = sz(g[u]) - (u == 0 ? 0: 1);
	//..cout << cnt << ' ' << u + 1 << endl;
	if (cnt == 0) {
		z.first = u;
		z.second.pb(u);
		return;
	}
	if (cnt != 1) {
		z.first=  u;
		z.second.pb(u);
	}
	for (auto h: g[u]) {
		if (h == pr) {
			continue;
		}
		if (cnt != 1) {
			pair<int, vector<int> > sek;
			dfs(h, u, sek);
			v[u].pb(sek.first);
			who[sek.first] = sek.second;
		} else {
			dfs(h, u, z);
			while (!z.second.empty() && c[z.second.back()] > c[u]) {
				z.second.pop_back();
			}
			if (!z.second.empty() && c[z.second.back()] == c[u]) {
				z.second.pb(u);
			} else {
				if (z.second.empty()) {
					z.second.pb(u);
				}
			}
		}
	}
}


long long dp[MAXN][2];

void dfscalc(int u) {
	for (auto x:  who[u]) {
		chkmin(c[u], c[x]);
	}
	if (v[u].empty()) {
		dp[u][0] = 1e18;
		dp[u][1] = c[u];
		return;
	}

	for (auto h: v[u]) {
	//	cout << u << ' ' << h << endl;
		dfscalc(h);
		dp[u][0] += min(dp[h][0], dp[h][1]);
	}
	dp[u][1] = 1e18;
	long long sum = 0;
	for (auto h: v[u]) {
		sum += min(dp[h][1], dp[h][0]);
	}
	for (auto h: v[u]) {
		chkmin(dp[u][1], sum - min(dp[h][1], dp[h][0]) + dp[h][1] - c[h] + c[u]);
	}
}

vector<int> ans;
bool bad[MAXN];

void restore(int u, long long opt, bool odin = false) {
	if (dp[u][1] != opt) {
		for (auto h: v[u]) {
			restore(h, min(dp[h][0], dp[h][1]));
		}
		return;
	}
	if (!bad[u]) {
	for (auto x: who[u]) {
		ans.pb(x + 1);
	}
	}
	if (dp[u][0] == opt && !odin) {
		for (auto h: v[u]) {
			restore(h, min(dp[h][0], dp[h][1]));
		}
		return;
	}
	int cnt = 0;
	for (auto h: v[u]) {
		if (dp[u][1] == dp[u][0] - min(dp[h][1], dp[h][0]) + dp[h][1] - c[h] + c[u]) {
			cnt++;
		}
	}
	if (cnt >= 2) {
		for (auto h: v[u]) {
			restore(h, min(dp[h][0], dp[h][1]));
		}
		return;
	}
	for (auto h: v[u]) {
		if (dp[u][1] == dp[u][0] - min(dp[h][1], dp[h][0]) + dp[h][1] - c[h] + c[u]) {
			bad[h] = true;
			restore(h, dp[h][1], true);
		} else {
			restore(h, min(dp[h][0], dp[h][1]));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	pair<int, vector<int> > z;
	dfs(0, -1, z);
	int root = z.first;
	who[root] = z.second;
	dfscalc(root);
	//cout << dp[root][0] << endl;
	restore(root, min(dp[root][0], dp[root][1]));
	
	sort(all(ans));
	cout << min(dp[root][0], dp[root][1]) << ' ' << sz(ans) << endl;
	for (auto x: ans) {
		cout << x << ' ';
	}
	cout << '\n';
	return 0; 
}