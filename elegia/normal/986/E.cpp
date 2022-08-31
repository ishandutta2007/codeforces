#include <cstdio>

#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct Edge {
	int v;
	Edge* next;
};

const int N = 1e5 + 10, X = 1e7 + 10, P = 1e9 + 7;

int n, q, pc;
int pr[1000000], rid[X];
int qu[N], qv[N], ans[N], f[N], lca[N], l[N], r[N], prt[N], dep[N];
int cnt[N], sum[N];
int pfac[X], plog[X];
Edge* g[N];
vector<pair<int, int> > qry[N], modi[1000000];

int mpow(int x, int k);
void adde(int u, int v);
void euler();
void dfs(int u);
void change(int* fw, int k, int x);
int query(int* fw, int k);

int lowBit(int k) { return k & -k; }
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
	euler();
	scanf("%d", &n);
	for (int rep = 1; rep < n; ++rep) {
		int u, v;
		scanf("%d%d", &u, &v);
		adde(u, v);
		adde(v, u);
	}
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		while (a != 1) {
			modi[rid[pfac[a]]].emplace_back(plog[a], i);
			for (int rep = plog[a]; rep; --rep)
				a /= pfac[a];
		}
	}
	scanf("%d", &q);
	fill(ans + 1, ans + q + 1, 1);
	for (int i = 1; i <= q; ++i) {
		int x;
		scanf("%d%d%d", &qu[i], &qv[i], &x);
		qry[qu[i]].emplace_back(qv[i], i);
		qry[qv[i]].emplace_back(qu[i], i);
		while (x != 1) {
			modi[rid[pfac[x]]].emplace_back(plog[x], -i);
			for (int rep = plog[x]; rep; --rep)
				x /= pfac[x];
		}
	}
	dfs(1);
	for (int i = 1; i <= pc; ++i) {
		sort(modi[i].begin(), modi[i].end());
		for (pair<int, int> md : modi[i])
			if (md.second > 0) {
				int u = md.second;
				change(cnt, l[u], 1);
				change(cnt, r[u] + 1, -1);
			}
		for (pair<int, int> md : modi[i]) {
			if (md.second > 0) {
				int u = md.second;
				change(cnt, l[u], -1);
				change(cnt, r[u] + 1, 1);
				change(sum, l[u], md.first);
				change(sum, r[u] + 1, -md.first);
			} else {
				int qid = -md.second;
				int totc = query(cnt, l[qu[qid]]) + query(cnt, l[qv[qid]]) - query(cnt, l[lca[qid]]) -
				           query(cnt, l[prt[lca[qid]]]),
						tots = query(sum, l[qu[qid]]) + query(sum, l[qv[qid]]) - query(sum, l[lca[qid]]) -
						       query(sum, l[prt[lca[qid]]]);
				ans[qid] = ans[qid] * (ll) mpow(pr[i], totc * md.first + tots) % P;
			}
		}
		for (pair<int, int> md : modi[i])
			if (md.second > 0) {
				int u = md.second;
				change(sum, l[u], -md.first);
				change(sum, r[u] + 1, md.first);
			}
	}
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}

void change(int* fw, int k, int x) {
	for (; k <= n; k += lowBit(k))
		fw[k] += x;
}

int query(int* fw, int k) {
	int ret = 0;
	for (; k; k -= lowBit(k))
		ret += fw[k];
	return ret;
}

void dfs(int u) {
	static int t;
	f[u] = u;
	l[u] = ++t;
	for (Edge* p = g[u]; p; p = p->next)
		 if (!f[p->v]) {
			 prt[p->v] = u;
			 dep[p->v] = dep[u] + 1;
			 dfs(p->v);
			 f[p->v] = u;
		 }
	r[u] = t;
	for (pair<int, int> q : qry[u])
		if (f[q.first])
			lca[q.second] = find(q.first);
}

int mpow(int x, int k) {
	int ret = 1;
	while (k) {
		if (k & 1)
			ret = (ll)ret * x % P;
		x = x * (ll)x % P;
		k >>= 1;
	}
	return ret;
}

void adde(int u, int v) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++p;
}

void euler() {
	static bool vis[X];
	for (int x = 2; x < X; ++x) {
		if (!vis[x]) {
			pr[++pc] = x;
			pfac[x] = x;
			plog[x] = 1;
			rid[x] = pc;
		}
		for (int i = 1; x * pr[i] < X; ++i) {
			vis[x * pr[i]] = true;
			pfac[x * pr[i]] = pr[i];
			if (x % pr[i] == 0) {
				plog[x * pr[i]] = plog[x] + 1;
				break;
			} else
				plog[x * pr[i]] = 1;
		}
	}
}