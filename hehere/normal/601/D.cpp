#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

bool chmax(int &a, int b) { return a < b ? a = b, true : false; }

const int maxN = 300000 + 233;
int n;
int a[maxN];
int sz[maxN];
int c[maxN];
vector<int> G[maxN];

int ch[maxN][26];
bool mark[maxN];
int cnt = 0;

int ans[maxN];

void clear() {
	for(int i = 0; i <= cnt; ++i)
		for(int c = 0; c < 26; ++c)
			ch[i][c] = 0;
	for(int i = 0; i <= cnt; ++i) mark[i] = false;
	cnt = 0;
}
int add(int u, int fa, int &now) {
	if(now == 0) now = ++cnt;
	int tot = 0;
	if(!mark[now]) mark[now] = true, ++tot;
	for(int v : G[u]) if(v != fa) {
		tot += add(v, u, ch[now][c[v]]);
	}
	return tot;
}

void dfs_sz(int u, int fa) {
	sz[u] = 1;
	for(int v : G[u]) if(v != fa) {
		dfs_sz(v, u);
		sz[u] += sz[v];
	}
}

int dfs(int u, int fa) {
	sz[u] = 1;
	int best = 0;
	for(int v : G[u]) if(v != fa) {
		if(sz[v] > sz[best]) best = v;
	}
	for(int v : G[u]) if(v != fa && v != best) {
		dfs(v, u);
		clear();
	}
	int tot = 0;
	int now;
//	printf("%d -> %d : sz = %d\n", u, best, sz[best]);
	if(best) {
		int node = dfs(best, u);
		ch[now = ++cnt][c[best]] = node;
		tot += ans[best];
		mark[now] = true; ++tot;
		for(int v : G[u]) if(v != fa && v != best) {
			tot += add(v, u, ch[now][c[v]]);
		}
	} else {
		now = ++cnt;
		mark[now] = true;
		tot = 1;
	}
	ans[u] = tot;
	return now;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	static char s[maxN];
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i) c[i] = s[i] - 'a';
	for(int kase = 1; kase < n; ++kase) {
		int x, y; scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	memset(sz, 0, sizeof(sz));
	dfs_sz(1, -1);
	dfs(1, -1);
//	for(int u = 1; u <= n; ++u) printf("%d ", ans[u]); printf("\n");
	int best = 0, cnt_ans = 0;
	for(int u = 1; u <= n; ++u) {
		if(ans[u] + a[u] > best) best = ans[u] + a[u], cnt_ans = 1;
		else if(ans[u] + a[u] == best) ++cnt_ans;
	}
	cout << best << endl << cnt_ans << endl;
	return 0;
}