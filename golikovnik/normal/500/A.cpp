#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

vector<vector<int>> g;
vector<char> used;
int t;

void dfs(int v) {
	if (v == t) {
		cout << "YES";
		exit(0);
	}
	if (v == g.size()) return;
	used[v] = 1;
	for (int &x: g[v]) {
		if (!used[x]) dfs(x);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n >> t;
	--t;
	g.resize(n - 1);
	used.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int x;
		cin >> x;
		g[i].pb(i + x);
	}       
	dfs(0);
	cout << "NO" << endl;
	return 0;
}