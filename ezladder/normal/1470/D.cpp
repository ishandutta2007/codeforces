#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
vector<int> g[300007];
bool was[300007];
int col[300007];
vector<int> ans;
int cc;

void dfs(int v) {
	++cc;
	int can = 1;
	was[v] = 1;
	for (int to : g[v]) {
		if (was[to]) {
			if (col[to] == 1) can = 0;
		}
	}
	col[v] = can;
	if (can) ans.pb(v);
	for (int to : g[v]) {
		if (!was[to]) {
			dfs(to);
		}
	}
}

void solve() {
	int m;
	cin >> n >> m;
	for (int i = 0; i <= n; ++i) was[i] = 0, g[i].clear();
	for (int i = 0; i < m; ++i) {
		int w1, w2;
		cin >> w1 >> w2;
		--w1; --w2;
		g[w1].pb(w2);
		g[w2].pb(w1);
	}

	cc = 0;
	ans.clear();
	dfs(0);
	sort(all(ans));
	if (cc != n) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cout << ans.size() << "\n";
	for (int v : ans) cout << v + 1 << ' ';
	cout << "\n";

}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}