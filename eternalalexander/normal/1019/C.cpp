#include <bits/stdc++.h>

const int maxn = 1e6 + 7;

int n,m,u,v,vis[maxn];
std::vector<int>in[maxn],out[maxn],ans;
std::unordered_set<int>S;

void solve() {
	if (S.empty()) return;
	int u = *S.begin(); S.erase(u);
	std::set<int>T = {u};
	for (int v:out[u]) {
		if (S.count(v)) {
			S.erase(v);
			T.insert(v);
		} 
	} solve();
	int flag = 0;
	for (int y:in[u]) {
		if (!S.count(y)) continue;
		flag |= vis[y];
	}
	if (!flag) { vis[u] = 1; ans.push_back(u); }
	for (int x:T) S.insert(x);
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++ i) S.insert(i);
	for (int i = 1; i <= m; ++ i) {
		scanf("%d%d",&u,&v);
		out[u].push_back(v);
		in[v].push_back(u);
	} solve();
	printf("%d\n",ans.size());
	for (int x:ans) printf("%d ",x);
	return 0;
}