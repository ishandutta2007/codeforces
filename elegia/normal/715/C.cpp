#include <cstdio>
#include <cstring>

#include <algorithm>
#include <map>

#define LOG(FMT...) // fprintf(stderr, "[LOG]: "FMT)

using namespace std;

typedef long long ll;
typedef map<int, int> map_t;
typedef map_t::iterator iter_t;

struct edge {
	int v, w;
	edge* next;
};

const int N = 100010;

int n, p, ordcnt;

bool vis[N], cut[N];
int ord[N], sum[N], mex[N], q[N], dep[N], digit[N], rdigit[N], rprod[N], prod[N];

edge* g[N];

void add_edge(int u, int v, int w);
void calc_order(int u);
void calc_sum(int u);
void dfs(int u);
ll calc(int u);
int rev(int a);
void ex_gcd(int a, int b, int& x, int& y);

int main() {
	ll ans = 0;
	scanf("%d%d", &n, &p);
	for (int rep = 1; rep < n; ++rep) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	prod[0] = 1;
	rprod[0] = 1;
	rprod[1] = rev(10);
	for (int i = 1; i <= n; ++i)
		prod[i] = 10LL * prod[i - 1] % p;
	for (int i = 2; i <= n; ++i)
		rprod[i] = (ll)rprod[1] * rprod[i - 1] % p;
	calc_order(0);
	memset(cut, 0, sizeof(cut));
	for (int i = 0; i < n; ++i) {
		int u = ord[i];
		dep[u] = 0;
		digit[u] = 0;
		rdigit[u] = 0;
		dfs(u);
		ans += calc(u);
		cut[u] = true;
		for (edge* p = g[u]; p; p = p->next)
			if (!cut[p->v])
				ans -= calc(p->v);
		ans -= 1;
		LOG("FINE %d: %lld\n", i, ans);
	}
	printf("%lld\n", ans);
	return 0;
}

int rev(int a) {
	int x, y;
	ex_gcd(a, p, x, y);
	if (x < 0)
		x += p;
	return x;
}

void ex_gcd(int a, int b, int&x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return;
	}
	ex_gcd(b, a % b, y, x);
	y -= a / b * x;
}

ll calc(int u) {
	int ql = 0, qr = 1;
	ll ret = 0;
	map_t mp;
	q[0] = u;
	while (ql < qr) {
		int v = q[ql++];
		vis[v] = true;
		iter_t it = mp.find(rdigit[v]);
		if (it != mp.end())
			++it->second;
		else
			mp.insert(make_pair(rdigit[v], 1));
		for (edge* p = g[v]; p; p = p->next)
			if (!vis[p->v] && !cut[p->v])
				q[qr++] = p->v;
	}
	for (int i = 0; i < qr; ++i)
		vis[q[i]] = false;
	for (int i = 0; i < qr; ++i) {
		int key = (ll)-digit[q[i]] * rprod[dep[q[i]]] % p;
		if (key < 0)
			key += p;
		iter_t it = mp.find(key);
		if (it != mp.end()) {
			LOG("%d FOUND %d WITH %d\n", q[i], it->second, it->first);
			ret += it->second;
		}
	}
	return ret;
}

void dfs(int u) {
	vis[u] = true;
	for (edge* p = g[u]; p; p = p->next)
		if (!vis[p->v] && !cut[p->v]) {
			dep[p->v] = dep[u] + 1;
			rdigit[p->v] = ((ll)prod[dep[u]] * p->w + rdigit[u]) % ::p;
			digit[p->v] = (digit[u] * 10LL + p->w) % ::p;
			dfs(p->v);
		}
	vis[u] = false;
}

void calc_order(int u) {
	calc_sum(u);
	int s = sum[u], ql = 0, qr = 1;
	q[0] = u;
	while (ql < qr) {
		int v = q[ql++];
		vis[v] = true;
		mex[v] = max(mex[v], s - sum[v]);
		if (mex[v] < mex[u])
			u = v;
		for (edge* p = g[v]; p; p = p->next)
			if (!vis[p->v] && !cut[p->v])
				q[qr++] = p->v;
	}
	for (int i = 0; i < qr; ++i)
		vis[q[i]] = false;
	ord[ordcnt++] = u;
	cut[u] = true;
	for (edge* p = g[u]; p; p = p->next)
		if (!cut[p->v])
			calc_order(p->v);
}

void calc_sum(int u) {
	vis[u] = true;
	mex[u] = 0;
	sum[u] = 1;
	for (edge* p = g[u]; p; p = p->next)
		if (!vis[p->v] && !cut[p->v]) {
			calc_sum(p->v);
			sum[u] += sum[p->v];
			mex[u] = max(mex[u], sum[p->v]);
		}
	vis[u] = false;
}

void add_edge(int u, int v, int w) {
	static edge pool[N * 2];
	static edge* p = pool;
	++p;
	p->v = v;
	p->w = w;
	p->next = g[u];
	g[u] = p;
}