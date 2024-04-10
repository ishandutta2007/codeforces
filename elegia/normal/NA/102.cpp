#include <cstdio>

#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;

struct Edge {
	int v;
	Edge* next;
};

const int N = 200010, X = 200000;

int n, cnt;
int a[N];
bool f[N];
ll ans[N];
vector<int> ia[N];
Edge* g[N];

void adde(int u, int v);
void dfs(int u);

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		ia[a[i]].push_back(i);
	}
	for (int rep = 1; rep < n; ++rep) {
		int u, v;
		scanf("%d%d", &u, &v);
		adde(u, v);
		adde(v, u);
	}
	for (int x = 1; x <= X; ++x) {
		for (int y = x; y <= X; y += x)
			for (int u : ia[y])
				f[u] = true;
		for (int y = x; y <= X; y += x)
			for (int u : ia[y]) {
				cnt = 0;
				dfs(u);
				ans[x] += cnt * (ll)(cnt + 1) / 2;
			}
	}
	for (int x = X; x; --x)
		for (int y = x * 2; y <= X; y += x)
			ans[x] -= ans[y];
	for (int i = 1; i <= X; ++i)
		if (ans[i])
			printf("%d %lld\n", i, ans[i]);
	return 0;
}

void dfs(int u) {
	if (f[u]) {
		f[u] = false;
		++cnt;
	} else
		return;
	for (Edge* p = g[u]; p; p = p->next)
		dfs(p->v);
}

void adde(int u, int v) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++p;
}