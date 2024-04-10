#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, a, b, da, db;
vector<int> g[100007];

pair<int, int> dfs(int v, int p) {
	pair<int, int> ans = {0, v};
	for (auto to : g[v]) if (to != p) {
		auto [w1, w2] = dfs(to, v);
		++w1;
		if (ans.x < w1) {
			ans = {w1, w2};
		}
	}
	return ans;
}

int get_dist(int v, int p, int need, int len = 0) {
	if (v == need) return len;
	for (int to : g[v]) if (to != p) {
		auto now = get_dist(to, v, need, len + 1);
		if (now != -1) return now;
	}
	return -1;
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n >> a >> b >> da >> db;
		a--; b--;
		for (int i = 0; i < n; ++i) g[i].clear();
		for (int i = 1; i < n; ++i) {
			int w1, w2;
			cin >> w1 >> w2; --w1; --w2;
			g[w1].pb(w2);
			g[w2].pb(w1);
		}

		auto [w1, w2] = dfs(0, -1);
		auto [w3, w4] = dfs(w2, -1);

		if (db < 2 * da + 1 || w3 < 2 * da + 1 || get_dist(a, -1, b) <= da) cout << "Alice\n";
		else cout << "Bob\n";

	}
}