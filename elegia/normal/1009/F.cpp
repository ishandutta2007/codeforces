#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <functional>
#include <set>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

struct Edge {
	int v;
	Edge* next;
};

int lowBit(int x) { return x & -x; }

struct FW {
	int cur;
	vector<int> cnt;

	void change(int k, int x) {
		cnt[k] += x;
		if (cnt[k] > cnt[cur] || cnt[k] == cnt[cur] && k > cur)
			cur = k;
	}
};

const int N = 1000010;

int n;
int ans[N];
bool vis[N];
Edge* g[N];
FW fws[N];
FW* t[N];

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
	for (int i = 1; i <= n; ++i)
		printf("%d\n", ans[i]);
	return 0;
}

void adde(int u, int v) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++p;
}

void dfs(int u) {
	vis[u] = true;
	t[u] = fws + u;
	t[u]->cnt.resize(1);
	for (Edge* p = g[u]; p; p = p->next) {
		if (vis[p->v])
			continue;
		dfs(p->v);
		if (t[u]->cnt.size() < t[p->v]->cnt.size())
			swap(t[u], t[p->v]);
		for (int i = 1; i < t[p->v]->cnt.size(); ++i)
			t[u]->change(i + t[u]->cnt.size() - t[p->v]->cnt.size(), t[p->v]->cnt[i]);
	}
	int pos = t[u]->cnt.size();
	pos -= lowBit(pos);
	t[u]->cnt.push_back(0);
	t[u]->change(t[u]->cnt.size() - 1, 1);
	ans[u] = t[u]->cnt.size() - t[u]->cur - 1;
}