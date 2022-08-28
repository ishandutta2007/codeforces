#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <set>
#include <map>
#include <limits>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

struct Edge {
	int v;
	Edge* next;
};

const int N = 400000, P = 1000000007;

int n, cnt, ans = 1;
int mark[N], dis[N];
bool vis[N];
char s[10];
Edge *g[N], *rg[N];

map<int, int> mp;
set<int> cur;

void ins(int x);
void adde(Edge** gp, int u, int v);
void d1(int u);
void d2(int u);
void gg() {
	puts("0");
	exit(0);
}

int main() {
	scanf("%d", &n);
	ins(0);
	cur.insert(0);
	ins(numeric_limits<int>::max());
	cur.insert(numeric_limits<int>::max());
	adde(g, 1, 2);
	adde(rg, 2, 1);
	while (n--) {
		int p;
		scanf("%s%d", s, &p);
		ins(p);
		if (s[1] == 'D') {
			set<int>::iterator it = cur.insert(p).first;
			int lst = mp[*prev(it)], nxt = mp[*next(it)], cur = mp[*it];
			adde(g, lst, cur);
			adde(rg, cur, lst);
			adde(g, cur, nxt);
			adde(rg, nxt, cur);
		} else {
			set<int>::iterator it = cur.find(p);
			int lst = mp[*prev(it)], nxt = mp[*next(it)];
			if (mark[lst] == 2 || mark[nxt] == 1) {
				puts("0");
				return 0;
			}
			mark[lst] = 1;
			mark[nxt] = 2;
			cur.erase(it);
		}
	}
	d1(1);
	memset(vis, 0, sizeof(vis));
	d2(2);
	mark[1] = 1;
	mark[2] = 2;
	int dim = 0;
	for (int i = 1; i <= cnt; ++i)
		if (mark[i] == 0) {
			++dim;
		}
	int cnt = 0;
	for (pair<int, int> pr : mp) {
		if (cur.count(pr.first) && mark[pr.second] == 0) {
			++cnt;
			--dim;
		}
	}
	ans = cnt + 1;
	while (dim--)
		ans = ans * 2LL % P;
	printf("%d\n", ans);
	return 0;
}

void ins(int x) {
	if (!mp[x])
		mp[x] = ++cnt;
}

void adde(Edge** gp, int u, int v) {
	static Edge pool[N * 4];
	static Edge* p = pool;
	p->v = v;
	p->next = gp[u];
	gp[u] = p;
	++p;
}

void d1(int u) {
	vis[u] = true;
	for (Edge* p = g[u]; p; p = p->next) {
		if (!vis[p->v])
			d1(p->v);
		if (mark[p->v] == 1) {
			if (mark[u] == 2) {
				gg();
			} else
				mark[u] = 1;
		}
	}
}

void d2(int u) {
	vis[u] = true;
	for (Edge* p = rg[u]; p; p = p->next) {
		if (!vis[p->v])
			d2(p->v);
		if (mark[p->v] == 2) {
			if (mark[u] == 1) {
				gg();
			} else
				mark[u] = 2;
		}
	}
}