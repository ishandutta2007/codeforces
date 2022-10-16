#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define X first
#define Y second
#define endl '\n'

typedef long long ll;
typedef long double ld;

vector<vector<int>> g;
vector<int> used;
vector<int> cnt(2);

void dfs(int v, int c = 0) {
	used[v] = 1;
	cnt[c]++;
	for (int u: g[v]) {
		if (!used[u]) {
			dfs(u, 1 - c);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	g.resize(n);
	used.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	cout << 1LL * cnt[0] * cnt[1] - (n - 1) << endl;
	return 0;
}