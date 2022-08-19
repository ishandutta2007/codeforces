#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}

set<int> eg[maxn]; // 
vi mx[maxn]; // 
int fl[maxn]; // 
int col[maxn];
int idcnt = 0;
void ins(int id, int num) {
	if (mx[id].size() >= 3) return ;
	mx[id].pb(num);
}

struct edge {
	int u, v, fl;
	edge *next;
	edge *rev;
}p[maxn << 1], *h[maxn];
int egcnt = 0;
void ade(int u, int v) {
	edge *n1 = &p[egcnt++];
	edge *n2 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->fl = 1;
	n2->u = v, n2->v = u, n2->fl = 1;
	n1->rev = n2, n2->rev = n1;
	n1->next = h[u], h[u] = n1;
	n2->next = h[v], h[v] = n2; 
}

int work(int l, int r) {
	if (l == r) {
		idcnt++;
		mx[idcnt].pb(l);
		return idcnt;
	}
	vector<pi> cur;
	cur.pb(mp(l + 1, 1)), cur.pb(mp(r, 1));
	set<int>::iterator g = eg[l].lower_bound(l);
	while (g != eg[l].end() && (*g) <= r) {
		cur.pb(mp(*g, 0));
		g++;
	}
	sort(cur.begin(), cur.end());
	vi id(cur.size());
	int rr = 0;
	for (int i = 0; i < cur.size() - 1; i++) {
		int j = work(cur[i].fi, cur[i + 1].fi);
		if (!fl[j]) {
			ins(j, l);
			if (cur[i + 1].se == 0) fl[j] = 1;
			else rr = j;
			id[i] = j;
		}
		if (i >= 1) ade(id[i], id[i - 1]);
	}
	return rr;
} 
bool cmp2(int a, int b) {
	for (int j = 0; j < 3; j++)
		if (mx[a][j] != mx[b][j])
			return mx[a][j] < mx[b][j];
	return 0;
}

int mxsz;
int ns, nans;
int sz[maxn], dep[maxn];
vi td[maxn], tf[maxn];
void dfs(int a, int fa, int tp) {
	// *** ed
	sz[a] = 1;
	int mr = 0;
	for (edge *p = h[a]; p; p = p->next) {
		if (!p->fl) continue;
		if (p->v == fa) continue;
		dep[p->v] = dep[a] + 1, dfs(p->v, a, tp);
		mr = max(mr, sz[p->v]);
		sz[a] += sz[p->v]; 
	} 
	if (tp) {
		int ra = max(mr, mxsz - sz[a]);
		if (ra < nans) nans = ra, ns = a;
	}
} 
void wo(int a, int rs) {
	col[a] = rs;
	dep[a] = 0, dfs(a, -1, 0);
	for (edge *p = h[a]; p; p = p->next) {
		if (!p->fl) continue;
		p->fl = p->rev->fl = 0;
		nans = maxn, mxsz = sz[p->v];
		dfs(p->v, -1, 1);
		wo(ns, rs + 1);
	}
}

int main() {
	const int test = 0;
	int n, m;
	if (test) n = 100000, m = 99997;
	else cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		if (test) u = 1, v = i + 2;
		else scanf("%d%d", &u, &v);
		eg[u].insert(v), eg[v].insert(u);
	}
	work(1, n);
/*	
	for (int i = 1; i <= idcnt; i++) {
		cout << i << endl;
		for (auto v : mx[i]) cout << v << ' ';
		cout << endl;
		for (auto v : seg[i]) cout << "ADE" << v << endl;
	}
*/	// 
	wo(1, 1);
	vi cur;
	for (int i = 1; i <= idcnt; i++) 
		cur.pb(i);
	sort(cur.begin(), cur.end(), cmp2);
	for (int i = 0; i < cur.size(); i++)
		printf("%d ", col[cur[i]]);
	return 0;
}
/*
8 4
3 8
4 6
6 8
2 8

*/