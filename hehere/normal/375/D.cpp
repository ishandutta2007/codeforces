#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::min; using std::max;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

const int maxN = 100000 + 233;
const int maxM = 100000 + 233;
int n, m, col[maxN];
vector<int> G[maxN];

int pre[maxN], post[maxN], euler[maxN], sz[maxN];
int dfs_clock = 0;
void pre_dfs(int u, int fa) {
	euler[pre[u] = ++dfs_clock] = u;
	sz[u] = 1;
	for(int v : G[u]) if(v != fa) {
		pre_dfs(v, u);
		sz[u] += sz[v];
	}
	post[u] = dfs_clock;
}

vector<int> Q[maxN];
int ans[maxM], qk[maxM];
int cnt[maxN], suf[maxN];

void inc(int c) {
	++suf[++cnt[c]];
}

void dec(int c) {
	--suf[cnt[c]--];
}

void dfs(int u, int fa) {
	int son = -1;
	for(int v : G[u]) if(v != fa) {
		if(son == -1 || sz[son] < sz[v]) son = v;
	}
	for(int v : G[u]) if(v != fa && v != son) {
		dfs(v, u);
		for(int i = pre[v]; i <= post[v]; ++i)
			dec(col[euler[i]]);
	}
	if(son != -1) dfs(son, u);
	for(int v : G[u]) if(v != fa && v != son) {
		for(int i = pre[v]; i <= post[v]; ++i)
			inc(col[euler[i]]);
	}
	inc(col[u]);
	for(int q : Q[u]) {
		ans[q] = suf[qk[q]];
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &col[i]);
	for(int i = 1; i < n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		G[x].push_back(y); G[y].push_back(x);
	}
	pre_dfs(1, -1);
	for(int i = 1; i <= m; ++i) {
		int u; scanf("%d%d", &u, &qk[i]);
		Q[u].push_back(i);
	}
	
	memset(cnt, 0, sizeof(cnt));
	memset(suf, 0, sizeof(suf));
	dfs(1, -1);

	for(int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
	return 0;
}