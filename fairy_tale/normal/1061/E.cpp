#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int MAXV = 1e4 + 5;
const int MAXE = 1e5 + 5;
const int INF = 0x3fffffff;
class mcf_graph {
  public:
    mcf_graph() {}
    void init(int n) {
        fill(head, head + n + 1, -1);
        cnt = 0;
        _n = n;
    }

    void add(int from, int to, int cap, int cost) {
        E[cnt].to = to;
		E[cnt].cap = cap;
		E[cnt].cost = cost;
		E[cnt].next = head[from];
		head[from] = cnt++;
    }

    void add_edge(int from, int to, int cap, int cost) {
        add(from, to, cap, cost);
        add(to, from, 0, -cost);
    }

    void spfa(int s, int t) {
        int u, v;
        fill(dep, dep + _n + 1, INF);
        fill(vis, vis + _n + 1, 0);
        dep[s] = 0;
        que.push_back(s);
        while (!que.empty()) {
            u = que.front();
            que.pop_front();
            vis[u] = 0;
            for (int i = head[u]; i != -1; i = E[i].next) {
                v = E[i].to;
                if (dep[u] + E[i].cost < dep[v] && E[i].cap) {
                    dep[v] = dep[u] + E[i].cost;
                    if (vis[v]) continue;
                    vis[v] = 1;
                    if (!que.empty() && dep[v] < dep[que.front()])que.push_front(v);
                    else que.push_back(v);
                }
            }
        }
    }

    struct mypair {
        int dis, id;
        bool operator<(const mypair& a) const { return dis > a.dis; }
        mypair(int d, int x) { dis = d, id = x; }
    };
    bool dijkstra(int s, int t) {
        priority_queue<mypair> q;
        fill(dis, dis + _n + 1, INF);
        fill(vis, vis + _n + 1, 0);
        dis[s] = 0;
        q.push(mypair(0, s));
        while (!q.empty()) {
            int u = q.top().id;
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (int i = head[u]; i != -1; i = E[i].next) {
                int v = E[i].to, nc = E[i].cost + dep[u] - dep[v];
                if (E[i].cap && dis[v] > dis[u] + nc) {
                    dis[v] = dis[u] + nc;
                    p[v].v = u;
                    p[v].e = i;
                    if (!vis[v]) q.push(mypair(dis[v], v));
                }
            }
        }
        return dis[t] != INF;
    }

    P PrimalDual(int s, int t) {
        sum = cost = 0;
        spfa(s, t);  // 

        while (dijkstra(s, t)) {
            int minf = INF;
            for (int i = 1; i <= _n; i++) dep[i] += dis[i];
            for (int i = t; i != s; i = p[i].v) minf = min(minf, E[p[i].e].cap);
            for (int i = t; i != s; i = p[i].v) {
                E[p[i].e].cap -= minf;
                E[p[i].e ^ 1].cap += minf;
            }
            sum += minf;
            cost += minf * dep[t];
        }
        return P(sum, cost);
    }

private:
    struct edge {
        int to, next;
        int cap, cost;
    };

    struct PD {
        int v, e;
    };

    int head[MAXV], cnt, _n;
    int sum, cost;
    int dep[MAXV], dis[MAXV];
    edge E[MAXE];
    PD p[MAXV];
    bool vis[MAXV];
    deque<int> que;
} graph;

const int N = 510;
struct tree
{
    struct node { int to, next; }e[N<<1];
    int head[N], cnt, fa[N], par[N], q[N];
    void init() { memset(head, -1, sizeof(head)); }
    void add(int x, int y) { e[cnt] = node{ y,head[x] }; head[x] = cnt++; }
    void dfs(int x, int from, int lst)
    {
        if (from && q[x]) q[lst] -= q[x], par[x] = lst = x;
        else par[x] = lst;
        for (int i = head[x]; i != -1; i = e[i].next)
        {
            int to1 = e[i].to;
            if (to1 != from) dfs(to1, x, lst);
        }
    }
    bool check(int n) { for (int i = 1; i <= n; ++i) if (q[i] < 0) return 0; return 1; }
}t[2];

int a[1010];

int main()
{
    int n, ro1,ro2;
    t[0].init(), t[1].init();
    scanf("%d%d%d", &n,&ro1,&ro2);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1, x, y; i < n; ++i) scanf("%d%d", &x, &y), t[0].add(x, y), t[0].add(y, x);
    for (int i = 1, x, y; i < n; ++i) scanf("%d%d", &x, &y), t[1].add(x, y), t[1].add(y, x);
    int q, sum = 0;
    scanf("%d", &q);
    for (int i = 1, x, k; i <= q; ++i) scanf("%d%d", &x, &k), t[0].q[x] = k;
    scanf("%d", &q);
    for (int i = 1, x, k; i <= q; ++i) scanf("%d%d", &x, &k), t[1].q[x] = k;
    if (t[0].q[ro1] != t[1].q[ro2]) return puts("-1"), 0;
    sum = t[0].q[ro1];
    t[0].dfs(ro1, 0, ro1); t[1].dfs(ro2, 0, ro2);
    if (!t[0].check(n) || !t[1].check(n)) return puts("-1"), 0;

    graph.init(1005);
    int ss = 1001, tt = 1002;

    for (int i = 1; i <= n; ++i) {
        graph.add_edge(t[0].par[i], t[1].par[i] + n, 1, 100000-a[i]);
        graph.add_edge(ss, i, t[0].q[i], 0);
        graph.add_edge(i + n, tt, t[1].q[i], 0);
    }
    auto tmp = graph.PrimalDual(ss, tt);

    if (tmp.fi != sum) return puts("-1"), 0;
    printf("%d\n", 100000 * tmp.fi-tmp.se);
    return 0;
}