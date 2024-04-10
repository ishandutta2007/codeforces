#include <bits/stdc++.h>

#define maxn 100005

int n,k,u,v,d[maxn],dfn[maxn],ref[maxn],anc[maxn][19],idx;
std::vector<int>ch[maxn];

void dfs(int u,int f) {
	anc[u][0] = f; d[u] = d[f] + 1;
	dfn[u] = ++idx; ref[idx] = u;
	for (int i = 1; i <= 17; ++ i) anc[u][i] = anc[anc[u][i-1]][i-1];
	for (int v:ch[u]) {
		if (v == f) continue;
		dfs(v,u);
	}
}

int LCA(int u,int v) {
	if (d[u] < d[v]) std::swap(u,v);
	for (int i = 17; i >= 0; i --) if (d[anc[u][i]] >= d[v]) u = anc[u][i];
	if (u == v) return u;
	for (int i = 17; i >= 0; i --) if (anc[u][i] != anc[v][i]) { u = anc[u][i]; v = anc[v][i]; }
	return anc[u][0];
}

int dis(int u,int v) { return d[u] + d[v] - 2 * d[LCA(u,v)]; }

namespace VIRT {
	std::set<int>S;
	int size;
	void reset() { S.clear(); size = 0; }
	int get_dis(int x) {
		if (S.empty()) return 0;
		auto p = S.lower_bound(dfn[x]); auto q = p;
		if (p == S.end()) p = S.begin();
		if (q == S.begin()) q = S.end();
		q--;
		int u = ref[*p], v = ref[*q];
		return dis(u,x) + dis(x,v) - dis(u,v); 
	}
	void extend(int x) {
	//	printf("+ %d\n",x);
		int d = get_dis(x);
		size += d;
		S.insert(dfn[x]);
	}
	void erase(int x) {
	//	printf("- %d\n",x);
		S.erase(dfn[x]);
		int d = get_dis(x);
		size -= d;
	}
}

int check(int x) {
	VIRT::reset();
	for (int i = 1; i < x; ++ i) VIRT::extend(i);
	for (int i = x; i <= n; ++ i) {
		if (i - x) VIRT::erase(i - x);
		VIRT::extend(i);
		if (VIRT::size / 2 <= k) return 1;
	} return 0;
}

int main() {
	scanf("%d%d",&n,&k); k--;
	for (int i = 1; i < n; ++ i) {
		scanf("%d%d",&u,&v);
		ch[u].push_back(v);
		ch[v].push_back(u);
	} dfs(1,0);
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) { ans = mid; l = mid + 1; }
		else r = mid - 1;
	} printf("%d",ans);
	return 0;
}