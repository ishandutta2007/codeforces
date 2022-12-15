#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int SIZE = 2e5+5;

vi g[SIZE];
bool vis[SIZE];

void dfs3(int pos) {
	vis[pos] = true;
	for(auto a : g[pos]) if(!vis[a]) dfs3(a);
}
bool dfs2(int pos, int prev, int start) {
	vis[pos] = true;
	bool ans = g[pos].size() == 2;
	if(ans) {
		for(auto a : g[pos]) {
			if(a == prev) continue;
			if(a == start) return true;
			if(vis[a]) return false;
			return dfs2(a, pos, start);
		}
	} else {
		for(auto a : g[pos]) dfs3(a);
		return false;
	}
}

bool dfs(int pos) {
	vis[pos] = true;
	bool ans = false;
	if(g[pos].size() == 2) ans = true;
	for(auto a : g[pos]) {
		if(!vis[a]) ans = dfs2(a, pos, pos) && ans;
	}
	return ans;
}



int main(){
	int n, m;
	cin >> n >> m;
	while(m--) {
		int i, j;
		cin >> i >> j;
		g[i].push_back(j);
		g[j].push_back(i);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) ans += dfs(i);
	}
	cout << ans << '\n';
	return 0;
}