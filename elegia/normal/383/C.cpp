#include <cstdio>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

struct edge {
	int v;
	edge* next;
};

const int N = 200010;

int n, m;
ll a[N];
ll fwt[2][N];
int l[N], r[N];
bool dep[N], vis[N];

edge* g[N];

int low_bit(int x);
void add_edge(int u, int v);
void change(ll fw[], int x, ll k);
ll query(ll fw[], int x);
void dfs(int u);

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	for (int rep = 1; rep < n; ++rep) {
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	dfs(1);
	while (m--) {
		int op, x;
		scanf("%d%d", &op, &x);
		if (op == 1) {
			ll y;
			scanf("%lld", &y);
			change(fwt[dep[x]], l[x], y);
			change(fwt[dep[x]], r[x] + 1, -y);
			change(fwt[!dep[x]], l[x], -y);
			change(fwt[!dep[x]], r[x] + 1, y);
		} else
			printf("%lld\n", a[x] + query(fwt[dep[x]], l[x]));
	}
	return 0;
}

void dfs(int u) {
	static int timer = 0;
	l[u] = ++timer;
	vis[u] = true;
	for (edge* p = g[u]; p; p = p->next)
		if (!vis[p->v]) {
			dep[p->v] = !dep[u];
			dfs(p->v);
		}
	r[u] = timer;
}

inline int low_bit(int x)
{ return x & -x; }

void change(ll fw[], int x, ll k) {
	for (; x <= n; x += low_bit(x))
		fw[x] += k;
}

ll query(ll fw[], int x) {
	ll ret = 0;
	for (; x; x -= low_bit(x))
		ret += fw[x];
	return ret;
}

inline void add_edge(int u, int v) {
	static edge pool[N << 1];
	static edge* p = pool;
	++p;
	p->v = v;
	p->next = g[u];
	g[u] = p;
}