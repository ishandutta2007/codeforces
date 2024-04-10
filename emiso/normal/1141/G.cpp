#include <bits/stdc++.h>

using namespace std;

int n, k, ans[200020];
vector<pair<int, int> > adj[200020];
//set<int> used[200020];
//map<pair<int, int>, int> id;

int dfs(int u, int r, int pai, int forbid) {
	int ret = 0;
	
	if((int)adj[u].size() <= r) {
		int c = 1;
		for(auto tt : adj[u]) {
			int v = tt.first, idx = tt.second;
			if(v == pai && ans[idx]) continue;
			if(c == forbid) c++;
			ans[idx] = c++;
		}
	}
	else ret++;
	
	for(auto tt : adj[u]) {
		int v = tt.first;
		if(v != pai)
			ret += dfs(v, r, u, ans[tt.second]);
	}
	
	return ret;
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].emplace_back(b, i);
		adj[b].emplace_back(a, i);
		//id[{a, b}] = id[{b, a}] = i;
	}
	
	int l = 1, r = n-1, m;
	while(l < r) {
		m = (l + r) / 2;
		
		memset(ans, 0, sizeof ans);
		//for(int i = 1; i <= n; i++)  used[i].clear();
		
		if(dfs(1, m, -1, 0) <= k) r = m;
		else l = m + 1;
	}
	
	memset(ans, 0, sizeof ans);
	dfs(1, l, -1, 0);
	
	printf("%d\n", l);
	for(int i = 1; i < n; i++) printf("%d ", ans[i] ? ans[i] : 1);
	
	return 0;
}