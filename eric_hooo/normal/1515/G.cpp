#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <pii> from[200010];
int dfn[200010], low[200010], ins[200010];
long long dep[200010];
int scc[200010], TOT, ALL;
long long val[200010], dp[200010];
int in[200010];
vector <int> G[200010];
vector <int> S;
set <int> has[200010];
int id[200010], ID, isp[200010];

long long gcd(long long x, long long y) {
	return !y ? x : gcd(y, x % y);
}

long long Solve(int x) {
	long long tmp = 0;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i].fi, d = from[x][i].se;
		if (scc[v] != scc[x]) continue;
		if (dep[v] == -1) dep[v] = dep[x] + d, tmp = gcd(tmp, Solve(v));
		else tmp = gcd(tmp, abs(dep[x] - dep[v] + d));
	}
	dp[x] = tmp;
	return tmp;
}

void Tarjan(int x) {
	dfn[x] = low[x] = ++TOT, ins[x] = 1, S.push_back(x);
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i].fi;
		if (!dfn[v]) Tarjan(v), low[x] = min(low[x], low[v]);
		else if (ins[v]) low[x] = min(low[x], dfn[v]);
	}
	if (dfn[x] != low[x]) return ;
	while (1) {
		int v = S.back(); S.pop_back(), ins[v] = 0;
		scc[v] = ALL;
		if (v == x) break;
	}
	dep[x] = 0, val[ALL] = Solve(x);
	ALL++;
}

vector <int> ord;

int main() {
	memset(dep, -1, sizeof(dep));
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y, l; scanf("%d%d%d", &x, &y, &l);
		from[x].push_back(mp(y, l));
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) Tarjan(i);
	}
/*	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < from[i].size(); j++) {
			int v = from[i][j].fi;
			if (scc[i] != scc[v]) in[v]++, G[i].push_back(v);
		}
	}
	for (int i = 0; i < ALL; i++) {
		if (!in[i]) ord.push_back(i);
	}
	for (int i = 0; i < ord.size(); i++) {
		int x = ord[i];
		for (int j = 0; j < G[x].size(); j++) {
			int v = G[x][j];
			in[v]--;
			if (!v) ord.push_back(v);
		}
	}
	for (int i = (int)ord.size() - 1; i >= 0; i--) {
		int x = ord[i];
		has[x].insert(val[x]);
		sort(G[x].begin(), G[x].end()), G[x].resize(unique(G[x].begin(), G[x].end()) - G[x].begin());
		for (int j = 0; j < G[x].size(); j++) {
			int v = G[x][j];
			for (auto it : has[v]) has[x].insert(gcd(val[x], it));
		}
	}*/
	int q; scanf("%d", &q);
	while (q--) {
		int x, s, t; scanf("%d%d%d", &x, &s, &t);
		int tmp = gcd(val[scc[x]], t);
		if (s % tmp == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}