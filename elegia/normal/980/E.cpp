#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>

#define LOG(FMT...) fprintf(stderr, FMT)

typedef long long ll;

using namespace std;

struct Edge {
	int v;
	Edge* next;
};

const int N = 1000010;

int n;
int prt[N], dep[N], l[N], r[N], fw[N];
Edge* g[N];
bool safe[N];

void addEdge(int u, int v);
int lowBit(int x);
int query(int k);
void change(int k, int x);
void dfs(int u);

int main() {
	int k;
	scanf("%d%d", &n, &k);
	for (int rep = 1; rep < n; ++rep) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	dfs(n);
	safe[n] = true;
	k = n - k - 1;
	for (int i = n - 1; i; --i) {
		if (safe[i])
			continue;
		int need = dep[i] - query(l[i]);
		if (need <= k) {
			k -= need;
			int u = i;
			while (!safe[u]) {
				safe[u] = true;
				change(l[u], 1);
				change(r[u] + 1, -1);
				u = prt[u];
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		if (!safe[i])
			printf("%d ", i);
	return 0;
}

void dfs(int u) {
	static int t;
	l[u] = ++t;
	for (Edge* p = g[u]; p; p = p->next)
		if (!l[p->v]) {
			dep[p->v] = dep[u] + 1;
			prt[p->v] = u;
			dfs(p->v);
		}
	r[u] = t;
}

void addEdge(int u, int v) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++p;
}

int lowBit(int x) {
	return x & -x;
}

int query(int k) {
	int ret = 0;
	for (; k; k -= lowBit(k))
		ret += fw[k];
	return ret;
}

void change(int k, int x) {
	for (; k <= n; k += lowBit(k))
		fw[k] += x;
}