#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define endl '\n'
#define X first
#define Y second

vector<vector<int>> g;
vector<int> color;
vector<char> used;
int ans;

void dfs(int v, int c) {
	used[v] = 1;
	if (c != color[v]) {
		++ans;
		c = color[v];		
	}
	for (int u: g[v]) {
		if (!used[u])
			dfs(u, c);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	g.resize(n);
	used.resize(n);
	for (int i = 0; i < n-1; ++i) {
		int x;
		cin >> x;
		--x;
		g[i + 1].push_back(x);
		g[x].push_back(i + 1);
	}
	color.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> color[i];
	}
	dfs(0, -1);
	cout << ans << endl;
	return 0;
}