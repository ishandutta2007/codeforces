#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

int n, m;
vector<int> g[111111], ans;
bool x[111111], used[111111];

void dfs(int v) {
	used[v]=true;
	for (int i=0; i<g[v].size(); i++) if (!used[g[v][i]]){
		x[g[v][i]]^=1;
		ans.push_back(g[v][i]);
		dfs(g[v][i]);
		x[v]^=1;
		ans.push_back(v);
		if (x[g[v][i]]) ans.push_back(g[v][i]), ans.push_back(v), x[g[v][i]]=0, x[v]^=1;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i=1; i<=n; i++) cin >> x[i];
	int mini=0;
	for (int i=1; i<=n; i++) if (x[i]) mini=i;
	dfs(mini);
	if (x[mini]) {
		if (ans.size())ans.pop_back(), x[mini]=0;
		else ans.push_back(mini), x[mini]=0;
	}
	for (int i=1; i<=n; i++) if (x[i]) {
		cout << -1;
		return 0;
	}
	cout << ans.size() << endl;
	for (int i=0; i<ans.size(); i++) cout << ans[i] << ' ';
    return 0;
}