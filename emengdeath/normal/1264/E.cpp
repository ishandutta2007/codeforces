#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
namespace MCMF{
    const int N = 1e6;
    const long long inf = 1e18;
    struct node{
        int to, next, v, cap;
    }edge[N];
    int st[N], cnt, S, T, n;
    int from[N];
    int can_flow[N];
    long long dis[N], po[N];//dis0
    priority_queue<pair<long long, int> > h;
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
    bool dij() {
        for (int i = 0; i <= n; i ++) dis[i] =inf;
        while (!h.empty()) h.pop();
        dis[S] = 0;
        can_flow[S] = 1e9;
        h.push(make_pair(0, S));
        while (!h.empty()) {
            auto u = h.top();
            h.pop();
            if (-u.first != dis[u.second]) continue;
            int x = u.second;
            for (int i = st[x]; i; i = edge[i].next)
                if (dis[edge[i].to] > dis[x] + edge[i].v - po[edge[i].to] + po[x] && edge[i].cap) {
                    dis[edge[i].to] = dis[x] + edge[i].v - po[edge[i].to] + po[x];
                    from[edge[i].to] = i;
                    can_flow[edge[i].to] = min(can_flow[x], edge[i].cap);
                    h.push(make_pair(-dis[edge[i].to], edge[i].to));
                }
        }
        return dis[T] != inf;
    }
    pair<long long, int> gao() {
        for (int i = 0; i <= n ;i  ++) po[i] = 0;
        long long v = 0;
        int flow = 0;
        while (dij()) {
            int x = T;
            int tmp = can_flow[T];
            flow += tmp;
            v += 1ll *(dis[T] - po[S] + po[T]) * tmp;
            while (x != S) {
                edge[from[x]].cap -=tmp;
                edge[from[x]^1].cap +=tmp;
                x = edge[from[x]^1].to;
            }
            for (int i = 0; i <= n ;i  ++) po[i] += dis[i];
        }
        return make_pair(v, flow);
    }
}
int n, m;
bool win[100][100];
int du[100];
vector<pair<int,int> > d;
int get(int x) {
    return x * (x - 1) / 2;
}
int main() {
    scanf("%d %d", &n, &m);
    int S = n + (n - 1) * n  / 2 + 1, T = S + 1;
    for (int i = 1; i <= m; i ++ ){
        int x, y;
        scanf("%d %d", &x, &y);
        win[x][y] = 1;
        du[x] ++;
    }
    MCMF::init(S, T, T);
    int ans = n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i ++) {
        ans -= get(du[i]);
        for (int j = du[i] + 1; j <= n - 1; j ++)
            MCMF::add_edge(i, T, get(j) - get(j - 1), 1);
    }
    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)
            if (!win[i][j] && !win[j][i])
                d.push_back(make_pair(i, j));
    for (int i = 0; i < d.size(); i ++)
        MCMF::add_edge(S ,i + 1 + n, 0, 1), MCMF::add_edge(i + 1 + n, d[i].first, 0, 1), MCMF::add_edge(i + 1 + n, d[i].second, 0, 1);
    MCMF::gao();
    for (int i = 0; i < d.size(); i ++)
        for (int j = MCMF::st[i + n + 1]; j ;j = MCMF::edge[j].next)
            if (MCMF::edge[j].to <= n && MCMF::edge[j].cap == 0) {
                if (MCMF::edge[j].to == d[i].first)
                    win[d[i].first][d[i].second] = 1;
                else
                    win[d[i].second][d[i].first] = 1;
            }
    for  (int i = 1; i <= n ; i ++){
        for (int j = 1; j <= n ; j++)
            win[i][j] ? printf("1"):printf("0");
        printf("\n");
    }
    return 0;
}