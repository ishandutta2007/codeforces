#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <queue>
#define MAXN 2010
#define MAXM 10000100
#define MAXP 10000100

using namespace std;

int n, ns;
int ls[MAXN], *pt[MAXN];
int g[MAXN][MAXN];
int removed[MAXN];
int p[MAXN][2], np;

namespace ACAM {
	int size=1;
	int ch[MAXP][2],pre[MAXP],last[MAXP];
	bool tag[MAXP];
	int visit[MAXP];

	void build() {
		static int q[MAXP];
		int head = 1, tail = 0;
		q[0] = 1;
		if (!ch[1][0]) ch[1][0] = 1;
		else q[++tail] = ch[1][0],pre[ch[1][0]] = 1;
		if (!ch[1][1]) ch[1][1] = 1;
		else q[++tail] = ch[1][1],pre[ch[1][1]] = 1;
		while (head <= tail) {
			int x = q[head++];
			last[x] = tag[x] ? x : last[pre[x]];
			if (!ch[x][0]) ch[x][0] = ch[pre[x]][0];
			else q[++tail] = ch[x][0], pre[ch[x][0]] = ch[pre[x]][0];
			if (!ch[x][1]) ch[x][1] = ch[pre[x]][1];
			else q[++tail] = ch[x][1], pre[ch[x][1]] = ch[pre[x]][1];
		}
	}
}

namespace Graph {
	struct edge {
		int to, next, w;
		edge(int _to = 0, int _next = 0, int _w = 0) :to(_to), next(_next), w(_w) {}
	}e[MAXM];

	int n, S, T;
	int g[MAXN], ne;
	int level[MAXN], cur[MAXN];
	int visit[MAXN];
	int r[MAXN],e2[MAXN][MAXN];
	int tag[MAXN];

	void addEdge(int u, int v, int w) {
		e[ne] = edge(v, g[u], w);
		g[u] = ne++;
		e[ne] = edge(u, g[v], 0);
		g[v] = ne++;
	}

	bool bfs() {
		for (int i = 1;i <= n;i++)
			cur[i] = g[i], level[i] = -1;
		static queue<int> Q;
		Q.push(S);
		level[S] = 0;
		while (!Q.empty()) {
			int x = Q.front(); Q.pop();
			for (int i = g[x];~i;i = e[i].next)
				if (e[i].w && level[e[i].to] == -1) {
					level[e[i].to] = level[x] + 1;
					Q.push(e[i].to);
				}
		}
		return level[T] != -1;
	}

	int dfs(int x, int delta) {
		if (x == T) return delta;
		int res = 0;
		for (int &i = cur[x];~i;i = e[i].next)
			if (e[i].w && level[e[i].to] == level[x] + 1) {
				int temp = dfs(e[i].to, min(delta, e[i].w));
				res += temp;
				delta -= temp;
				e[i].w -= temp;
				e[i ^ 1].w += temp;
				if (!delta) return res;
			}
		return res;
	}

	bool check(int x) {
		for (int i = g[x * 2];~i;i = e[i].next)
			if (e[i].to < S && e[i].w)
				return 0;
		return 1;
	}

	void dfs2(int x, int d){
		visit[x]=d;
		if(d==1){
			dfs2(r[x], 2);
			return;
		}
		for(int i=1;i<S;i++)
			if(e2[x][i]  && !visit[i]) 
				dfs2(i, 3-d);
	}

	int gao(){
		for(int i=1;i<S;i+=2)
			for(int j=g[i];~j;j=e[j].next)
				if(e[j].to<S){
					e2[i][e[j].to]=e2[e[j].to][i]=1;
					if(!e[j].w) r[i]=e[j].to, r[e[j].to]=i;
				}
		for(int i=1;i<S;i++){
			if(!visit[i] && !r[i])
				dfs2(i, 2);
		}
		for(int i=1;i<S;i++)
			if(!visit[i])
				dfs2(i, 1);
		int cnt=0;
		for(int i=1;i<S;i++){
			if(r[i])
				cnt++;
		}
		return cnt/2;
	}
}

bool cmp(int x, int y) {
	return pt[x][0] < pt[y][0];
}

int main() {
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		int x = 1;
		char c;
		static int tp[MAXP];
		int len = 0;
		while ((c = getchar()) != 'a' && c != 'b');
		do{
			if (!ACAM::ch[x][c - 'a'])
				ACAM::ch[x][c - 'a'] = ++ACAM::size;
			tp[++len] = x = ACAM::ch[x][c - 'a'];
		} while ((c = getchar()) == 'a' || c == 'b');
		pt[i] = new int[len + 1];
		pt[i][0] = len;
		for (int j = 1;j <= len;j++) pt[i][j] = tp[j];
		ACAM::tag[x] = 1;
		ls[i] = i;
	}
	sort(ls + 1, ls + n + 1, cmp);
	ACAM::build();
	for (int i = 1;i <= n;i++) p[i][0] = ++np, p[i][1] = ++np;
	Graph::S = ++np; Graph::n = Graph::T = ++np;
	memset(Graph::g, -1, sizeof Graph::g);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= pt[i][0];j++)
			if (ACAM::last[pt[i][j]])
				ACAM::visit[ACAM::last[pt[i][j]]] = i;
		for (int j = n;j >= 1;j--) {
			int x = ls[j], y = pt[x][pt[x][0]];
			if (ACAM::visit[y] == i) {
				if (i != x) {
					Graph::addEdge(p[i][0], p[x][1], 1);
					g[i][x] = 1;
				}
				if (ACAM::last[ACAM::pre[y]]) ACAM::visit[ACAM::last[ACAM::pre[y]]] = i;
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		Graph::addEdge(Graph::S, p[i][0], 1);
		Graph::addEdge(p[i][1], Graph::T, 1);
	}
	int flow = 0;
	while (Graph::bfs())
		flow += Graph::dfs(Graph::S, 1 << 30);
	int temp = Graph::gao();
	if(temp!=flow) printf("%d %d\n", temp, flow);
	printf("%d\n", n-flow);
	for(int i=1;i<=n;i++)
		if(Graph::visit[i*2-1]==2 && Graph::visit[i*2]==2)
			printf("%d\n", i);
	return 0;
}