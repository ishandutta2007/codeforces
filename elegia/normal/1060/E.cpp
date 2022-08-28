#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Edge {
	int v;
	Edge* next;
};

const int N = 200010;

int n;
int dep[N], sub[N];
bool vis[N];
int cc;
ll ans;
Edge* g[N];

void adde(int u, int v);
void dfs(int u);

int main() {
	scanf("%d", &n);
	for (int rep = 1; rep < n; ++rep) {
		int u, v;
		scanf("%d%d", &u, &v);
		adde(u, v);
		adde(v, u);
	}
	dfs(1);
	ans += cc * (ll)(n - cc);
	ans /= 2;
	printf("%lld\n", ans);
	return 0;
}

void dfs(int u) {
	vis[u] = true;
	if (dep[u] & 1)
		++cc;
	sub[u] = 1;
	for (Edge* p = g[u]; p; p = p->next)
		if (!vis[p->v]) {
			dep[p->v] = dep[u] + 1;
			dfs(p->v);
			sub[u] += sub[p->v];
		}
	ans += sub[u] * (ll)(n - sub[u]);
}

void adde(int u, int v) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++p;
}