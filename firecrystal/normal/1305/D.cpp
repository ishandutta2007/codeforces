#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1005;
int n, dis[N], cnt;
int head[N], pre[N], numE = 0;
bool ans[N];
struct Edge{
    int next, to, dis;
}e[N << 1];
void addEdge(int from, int to, int dis) {
    e[++numE].next = head[from];
    e[numE].to = to;
    e[numE].dis = dis;
    head[from] = numE;
}
int get() {
    int t = -1, res = -1;
    for (int i = 1; i <= n; i++) {
        if(dis[i] > res) {
            res = dis[i], t = i;
        }
    }
    return t;
}
void dfs(int u, int fa) {
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if(v == fa || ans[v]) continue;
        dis[v] = dis[u] + e[i].dis;
        pre[v] = u;
        dfs(v, u);
    }
}
void fill(int u, int l) {
	cnt--;
	ans[u] = true;
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].to;
		if (v == l || ans[v]) continue;
		fill(v, l);
	}
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v, 1); addEdge(v, u, 1);
    }
    cnt = n;
    while (cnt > 1) {
    	memset(dis, 0, sizeof dis);
    	int s = 1;
    	while (ans[s]) s++;
    	dfs(s, 0);
    	int t = get();
    	dis[t] = 0;
    	dfs(t, 0);
    	s = get();
    	printf("? %d %d\n", s, t);
    	fflush(stdout);
    	int x; scanf("%d", &x);
    	int p = s;
    	while (1) {
    		if (p != x && !ans[p]) fill(p, x);
    		if (p == t) break;
    		p = pre[p];
    	}
    }
    
    for (int i = 1; i <= n; i++)
    	if (!ans[i]) printf("! %d\n", i);
    return 0;
}