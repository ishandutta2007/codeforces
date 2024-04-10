#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
using namespace std;


#define clr( a , x ) memset ( a , x , sizeof a )

const int MAXN = 1e6 + 10;
const int MAXE = 1e6 + 10;
const double pi = acos(-1.0);

struct Complex {
	double r, i;
	Complex() {}
	Complex(double r, double i) : r(r), i(i) {}
	Complex operator + (const Complex& t) const {
		return Complex(r + t.r, i + t.i);
	}
	Complex operator - (const Complex& t) const {
		return Complex(r - t.r, i - t.i);
	}
	Complex operator * (const Complex& t) const {
		return Complex(r * t.r - i * t.i, r * t.i + i * t.r);
	}
};

struct Edge {
	int v, n;
	Edge() {}
	Edge(int v, int n) : v(v), n(n) {}
};

Complex D[MAXE];
Edge E[MAXE];
int H[MAXN], cntE;

int Q[MAXN], head, tail;
int dep[MAXN];
int pre[MAXN];
int siz[MAXN];
int cnt[MAXN];
int vis[MAXN];

int pri[MAXN];
LL ans[MAXN];
int n;

void DFT(Complex y[], int n, int rev) {
	for (int i = 1, j, k, t; i < n; ++i) {
		for (j = 0, k = n >> 1, t = i; k; k >>= 1, t >>= 1) {
			j = j << 1 | t & 1;
		}
		if (i < j) swap(y[i], y[j]);
	}
	for (int s = 2, ds = 1; s <= n; ds = s, s <<= 1) {
		Complex wn(cos(rev * 2 * pi / s), sin(rev * 2 * pi / s));
		for (int k = 0; k < n; k += s) {
			Complex w(1, 0), t;
			for (int i = k; i < k + ds; ++i, w = w * wn) {
				y[i + ds] = y[i] - (t = w * y[i + ds]);
				y[i] = y[i] + t;
			}
		}
	}
}

void preprocess() {
	for (int i = 2; i < MAXN; ++i) pri[i] = 1;
	for (int i = 2; i < MAXN; ++i) if (pri[i]) {
		for (int j = i + i; j < MAXN; j += i) pri[j] = 0;
	}
}

void init() {
	cntE = 0;
	clr(H, -1);
	clr(vis, 0);
	clr(ans, 0);
}

void addedge(int u, int v) {
	E[cntE] = Edge(v, H[u]);
	H[u] = cntE++;
}

int get_root(int s) {
	head = tail = 0;
	Q[tail++] = s;
	pre[s] = 0;
	while (head != tail) {
		int u = Q[head++];
		siz[u] = 1;
		cnt[u] = 0;
		for (int i = H[u]; ~i; i = E[i].n) {
			int v = E[i].v;
			if (v == pre[u] || vis[v]) continue;
			pre[v] = u;
			Q[tail++] = v;
		}
	}
	int root = s, root_siz = tail;
	while (head) {
		int u = Q[--head], p = pre[u];
		cnt[u] = max(cnt[u], tail - siz[u]);
		if (cnt[u] < root_siz) {
			root = u;
			root_siz = cnt[u];
		}
		siz[p] += siz[u];
		if (siz[u] > cnt[p]) cnt[p] = siz[u];
	}
	return root;
}

void calc(int s, int init_dis, int f) {
	head = tail = 0;
	Q[tail++] = s;
	dep[s] = init_dis;
	pre[s] = 0;
	while (head != tail) {
		int u = Q[head++];
		for (int i = H[u]; ~i; i = E[i].n) {
			int v = E[i].v;
			if (vis[v] || v == pre[u]) continue;
			dep[v] = dep[u] + 1;
			pre[v] = u;
			Q[tail++] = v;
		}
	}
	int n1 = 1, len = (dep[Q[tail - 1]] + 1) * 2;
	while (n1 < len) n1 <<= 1;
	for (int i = 0; i < n1; ++i) D[i] = Complex(0.0, 0.0);
	while (head) D[dep[Q[--head]]].r += 1;
	DFT(D, n1, +1);
	for (int i = 0; i < n1; ++i) D[i] = D[i] * D[i];
	DFT(D, n1, -1);
	for (int i = 0; i < n1; ++i) D[i].r /= n1;
	int n2 = min(n, n1);
	for (int i = 1; i < n2; ++i) {
		LL tmp = (LL)(D[i].r + 0.5);
		ans[i] += f ? tmp : -tmp;
	}
}

void dfs(int u) {
	int root = get_root(u);
	vis[root] = 1;
	calc(root, 0, 1);
	for (int i = H[root]; ~i; i = E[i].n) if (!vis[E[i].v]) calc(E[i].v, 1, 0);
	for (int i = H[root]; ~i; i = E[i].n) if (!vis[E[i].v]) dfs(E[i].v);
}

void solve() {
	int u, v;
	init();
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs(1);
	LL res = 0;
	for (int i = 1; i < n; ++i) {
		res += (i + 1) / 2LL * ans[i];
	}
	printf("%lld\n", res/2);
}

int main() {
//	preprocess();
	while (~scanf("%d", &n)) solve();
	return 0;
}