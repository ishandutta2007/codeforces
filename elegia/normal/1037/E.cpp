#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <random>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 200010;

int n, m, k;
int u[N], v[N], ans[N];
bool notrip[N];
set<int> g[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &u[i], &v[i]);
		g[u[i]].insert(v[i]);
		g[v[i]].insert(u[i]);
	}
	int cnt = n;
	queue<int> q;
	for (int i = 1; i <= n; ++i)
		if (g[i].size() < k) {
			q.push(i);
			notrip[i] = true;
		}
	while (!q.empty()) {
		--cnt;
		int u = q.front();
		q.pop();
		for (int v : g[u]) {
			g[v].erase(u);
			if (g[v].size() < k && !notrip[v]) {
				notrip[v] = true;
				q.push(v);
			}
		}
	}
	for (int i = m; i; --i) {
		ans[i] = cnt;
		if (notrip[u[i]] || notrip[v[i]])
			continue;
		g[u[i]].erase(v[i]);
		g[v[i]].erase(u[i]);
		if (g[u[i]].size() < k) {
			notrip[u[i]] = true;
			q.push(u[i]);
		}
		if (g[v[i]].size() < k) {
			notrip[v[i]] = true;
			q.push(v[i]);
		}
		while (!q.empty()) {
			--cnt;
			int u = q.front();
			q.pop();
			for (int v : g[u]) {
				g[v].erase(u);
				if (g[v].size() < k && !notrip[v]) {
					notrip[v] = true;
					q.push(v);
				}
			}
		}
	}
	for (int i = 1; i <= m; ++i)
		printf("%d\n", ans[i]);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}