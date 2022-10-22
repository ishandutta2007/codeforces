#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG
//#define USE_MAGIC_IO

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
#define nl '\n'
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

void dfs(const vector<vector<int>>& g, int curr, int par, set<int>& left) {
	if (!left.count(par)) {
		left.insert(curr);
	}
	for (int neighbour: g[curr]) {
		if (neighbour != par) 
			dfs(g, neighbour, curr, left);
	}
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int a, b;
	int n;
	cin >> n;
	vector<vector<int>> graph(n+1);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	set<int> left;
	dfs(graph, 1, 0, left);
	int right = n-left.size();
	ll ans = 0;
	for (int it: left) {
		ans += right - graph[it].size();
	}
	cout << ans << nl;

	return 0;
}