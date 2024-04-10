#include <bits/stdc++.h>
#define N 107
#define M 100007
#define INF 100000000000007LL
#define E 1000007
using namespace std;
int n, m, d[N][N], s, b, k;
struct spaceship { int x, a, f, p; } sp[M];
struct base { int x, d, g; } ba[M];
vector<int> v[N];
bool cmp(int x, int y) { return ba[x].d < ba[y].d; }
vector<pair<int, int> > u[N];
long long val[M];
int e, head[M], nxt[E], to[E], op[E];
long long cap[E];
void add_edge(int x, int y, long long c) {
    nxt[++ e] = head[x], to[head[x] = e] = y;
    cap[e] = c, op[e] = e + 1;
    nxt[++ e] = head[y], to[head[y] = e] = x;
    cap[e] = 0, op[e] = e - 1;
}
int S, T, nodes, dis[M], cnt[M];
long long sap(int x, long long delta) {
    if(x == T) return delta;
    long long sum = 0;
    int mindis = nodes;
    for(int i = head[x]; i; i = nxt[i]) {
        if(cap[i] && dis[x] == dis[to[i]] + 1) {
            long long save = sap(to[i], min(cap[i], delta - sum));
            sum += save, cap[i] -= save, cap[op[i]] += save;
            if(dis[S] >= nodes || sum == delta) return sum;
        }
        if(cap[i]) mindis = min(mindis, dis[to[i]]);
    }
    if(!sum)
        if(! -- cnt[dis[x]]) dis[S] = nodes;
        else ++ cnt[dis[x] = mindis + 1];
    return sum;
}
long long max_flow() {
    long long res = 0;
    while(dis[S] < nodes) res += sap(S, INF);
    return res;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j) if(i != j) d[i][j] = N;
    for(int i = 1, x, y; i <= m; ++ i) {
        scanf("%d%d", &x, &y);
        if(x == y) continue;
        d[x][y] = d[y][x] = 1;
    }
    for(int t = 1; t <= n; ++ t)
        for(int i = 1; i <= n; ++ i) if(i != t)
            for(int j = 1; j <= n; ++ j) if(j != t && j != i) d[i][j] = min(d[i][j], d[i][t] + d[t][j]);
    scanf("%d%d%d", &s, &b, &k);
    for(int i = 1; i <= s; ++ i) scanf("%d%d%d%d", &sp[i].x, &sp[i].a, &sp[i].f, &sp[i].p);
    for(int i = 1; i <= b; ++ i) {
        scanf("%d%d%d", &ba[i].x, &ba[i].d, &ba[i].g);
        v[ba[i].x].push_back(i);
    }
    for(int i = 1; i <= n; ++ i) {
        sort(v[i].begin(), v[i].end(), cmp);
        int mx = 0;
        for(int j: v[i]) {
            mx = max(mx, ba[j].g);
            u[i].push_back(make_pair(ba[j].d, mx));
        }
    }
    for(int i = 1; i <= s; ++ i) {
        val[i] = -INF;
        for(int j = 1; j <= n; ++ j) if(d[sp[i].x][j] < N && d[sp[i].x][j] <= sp[i].f) {
            int t = -1, l = 0, r = u[j].size() - 1;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(u[j][mid].first <= sp[i].a) t = mid, l = mid + 1;
                else r = mid - 1;
            }
            if(t != -1) val[i] = max(val[i], 1LL * u[j][t].second - sp[i].p);
        }
    }
    S = 0, T = s + 1, nodes = s + 2;
    long long ans = 0;
    for(int i = 1; i <= s; ++ i)
        if(val[i] > 0) ans += val[i], add_edge(S, i, val[i]);
        else if(val[i] < 0) add_edge(i, T, -val[i]);
    for(int i = 1, x, y; i <= k; ++ i) scanf("%d%d", &x, &y), add_edge(x, y, INF);
    ans -= max_flow();
    cout << ans << endl;
}