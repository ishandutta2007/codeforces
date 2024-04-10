#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 200005;
int n, siz[MAXN], fib[MAXN], nd;
vector<int> edge[MAXN];

void get_size(int u, int fa) {
	siz[u] = 1;
	for (int v : edge[u]) if (v != fa && v) {
		get_size(v, u);
		siz[u] += siz[v];
	}
}

struct P { int u, v; };
void dfs1(int u, int fa, int s, vector<P> &vec) {
	for (int v : edge[u]) if (v != fa && v) {
		dfs1(v, u, s + siz[u] - siz[v], vec);
	}
	if (s == nd) {
		vec.push_back(P { u, fa });
	}
	else if (siz[u] == nd) {
		vec.push_back(P { fa, u });
	}
}

void del(P p) {
	for (int &i : edge[p.u]) if (i == p.v) i = 0;
	for (int &i : edge[p.v]) if (i == p.u) i = 0;
}

void rus(P p) {
	for (int &i : edge[p.u]) if (i == 0) {
		i = p.v; break;
	}
	for (int &i : edge[p.v]) if (i == 0) {
		i = p.u; break;
	}
}

bool dfs(int u, int d) {
	get_size(u, 0);
	vector<P> vec;
	vec.clear();
	if (siz[u] <= 3) return true;
	nd = fib[d - 2];
	dfs1(u, 0, 0, vec);
	if (vec.empty()) return false;
	P p = vec[0];
	del(p);
	if (dfs(p.v, d - 2) && dfs(p.u, d - 1)) return true;
	rus(p);
//	if ((int)vec.size() == 1) return false;
//	p = vec[1];
//	del(p);
//	vec.clear();
//	nd = fib[d - 2];
//	get_size(p.u, 0);
//	dfs1(p.u, 0, 0, vec);
//	P q;
//	if ((int)vec.size() == 1) return false;
//	if (siz[vec[0].v] == nd) q = vec[1];
//	else q = vec[0];
//	del(q);
//	if (dfs(p.v, d - 2) && dfs(p.u, d - 2) && dfs(q.u, d - 3)) return true;
//	rus(q);
//	rus(p);
	return false;
}

int main() {
	fib[0] = fib[1] = 1;
	for (int i = 2; i <= 30; i++) fib[i] = fib[i - 1] + fib[i - 2];
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int k = -1;
	for (int i = 0; i <= 30; i++) if (fib[i] == n) {
		k = i; break;
	}
	puts(k >= 0 && dfs(1, k) ? "YES" : "NO");
	return 0;
}