#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
namespace MCMF{
    const int N = 1e6;
    const long long inf = 1e18;
    struct node{
        int to, next, v, cap;
    }edge[N];
    int st[2000], cnt, S, T, n;
    int d[N], from[2000];
    int can_flow[2000];
    long long dis[2000];
    bool bz[N];
    void init(int s, int t, int nn) {
        cnt = 1;
        n = nn;
        S = s, T = t;
        for (int i = 0; i <= n; i ++)st[i] = 0;
    }
    void add_edge(int x, int y, int v, int cap){
        edge[++cnt].to = y;
        edge[cnt].next = st[x];
        edge[cnt].v = v;
        edge[cnt].cap = cap;
        st[x] = cnt;
        edge[++cnt].to = x;
        edge[cnt].next = st[y];
        edge[cnt].v = -v;
        edge[cnt].cap = 0;
        st[y] = cnt;
    }
    bool spfa() {
        for (int i = 0; i <= n; i ++) dis[i] =-inf;
        dis[S] = 0;
        d[1] = S;
        bz[S] = 1;
        can_flow[S] = 1e9;
        int l = 0, r = 1;
        while (l != r) {
            int x = d[l = l % n + 1];
            for (int i = st[x]; i; i = edge[i].next)
                if (dis[edge[i].to] < dis[x] +edge[i].v && edge[i].cap) {
                    dis[edge[i].to] = dis[x] + edge[i].v;
                    from[edge[i].to] = i;
                    can_flow[edge[i].to] = min(can_flow[x], edge[i].cap);
                    if (!bz[edge[i].to])
                        bz[d[r = r % n + 1] = edge[i].to] = 1;
                }
            bz[d[l]] = 0;
        }
        return dis[T] != -inf;
    }
    pair<long long, int> gao() {
        long long v = 0;
        int flow = 0;
        while (spfa()) {
            int x = T;
            int tmp = can_flow[T];
            flow += tmp;
            v += 1ll *dis[T] * tmp;
            while (x != S) {
                edge[from[x]].cap -=tmp;
                edge[from[x]^1].cap +=tmp;
                x = edge[from[x]^1].to;
            }
        }
        return make_pair(v, flow);
    }
}
const int N = 2000;
int n, rot1, rot2, s, ss, t, tt;
vector<int>g1[N], g2[N];
int v[N], lim1[N], lim2[N];
void dfs1(int x, int fa) {
    if (lim1[x]) {
        MCMF::add_edge(ss, x, 0, lim1[x]);
        MCMF::add_edge(fa, tt, 0, lim1[x]);
    } else {
        MCMF::add_edge(fa, x, 0, 1e9);
    }
    for (auto u:g1[x])
        if (u != fa)
            dfs1(u, x);
}
void dfs2(int x, int fa) {
    if (fa == t) fa -= n;
    if (lim2[x]) {
        MCMF::add_edge(ss, fa +n, 0, lim2[x]);
        MCMF::add_edge(x+n, tt, 0, lim2[x]);
    } else {
        MCMF::add_edge(x+n, fa+n, 0, 1e9);
    }
    for (auto u:g2[x])
        if (u != fa)
            dfs2(u, x);
}
int main() {
    scanf("%d %d %d", &n, &rot1, &rot2);
    s = n * 2 + 1, t = n * 2 + 2, ss = n * 2 + 3, tt = n * 2 + 4;
    MCMF::init(ss, tt, tt);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &v[i]), MCMF::add_edge(i, i +n, v[i], 1);
    for (int i = 1; i < n; i ++ ) {
        int x, y;
        scanf("%d%d", &x, &y);
        g1[x].push_back(y);
        g1[y].push_back(x);
    }
    for (int i = 1; i < n; i ++ ) {
        int x, y;
        scanf("%d%d", &x, &y);
        g2[x].push_back(y);
        g2[y].push_back(x);
    }
    int q1;
    scanf("%d", &q1);
    while (q1 --) {
        int x, k;
        scanf("%d %d", &x, &k);
        lim1[x] = k;
    }
    int q2;
    scanf("%d", &q2);
    while (q2 --) {
        int x, k;
        scanf("%d %d", &x, &k);
        lim2[x] = k;
    }
    dfs1(rot1, s);
    dfs2(rot2, t);

    MCMF::add_edge(t, s, 0, 1e9);
    long long ans = MCMF::gao().first;
    for (int i= MCMF::st[ss]; i; i = MCMF::edge[i].next )
        if (MCMF::edge[i].cap) {
            printf("-1");
            return 0;
        }
    MCMF::S = s;
    MCMF::T = t;
    MCMF::st[s] = MCMF::edge[MCMF::st[s]].next;
    MCMF::st[t] = MCMF::edge[MCMF::st[t]].next;
    ans += MCMF::gao().first;
    printf("%lld\n", ans);
    return 0;
}