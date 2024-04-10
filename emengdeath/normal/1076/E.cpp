#include <bits/stdc++.h>
using namespace std;
vector<int> a[300101], g[300011], b[300111];
long long f[300101 * 4], v[301001], tag[300101 * 4];
int deep[301002], ll[301001], rr[300001], d[300001], fa[301001], q[300001][3];
int n, m;
void dfs(int x, int fa) {
    static int tot = 0;
    ll[x] = ++ tot;
    for (auto u : g[x]) 
        if (u != fa) {
            dfs(u, x);
        }
    rr[x] = tot;
}
void down(int l, int r, int s) {
    if (tag[s]) {
        f[s] += (r - l + 1) * tag[s];
        if (l != r) tag[s + s] += tag[s], tag[s + s + 1] += tag[s];
        tag[s] = 0; 
    }
}
void ins(int l, int r, int s, int ll, int rr, int v) {
    down(l, r, s);
    if (rr < l || r < ll) return;
    if (ll <= l && r <= rr) {
        tag[s] += v;
        down(l, r, s);
        return;
    }
    ins(l, (l + r) / 2, s + s, ll, rr, v);
    ins((l + r) / 2 + 1, r, s + s + 1, ll, rr, v);
    f[s] = f[s + s] + f[s + s + 1];
}
long long get(int l, int r, int s, int ll) {
    down(l, r, s);
    if (l == r) return f[s];
    if ((l + r) / 2 >= ll) return get(l, (l + r) / 2, s + s, ll);
    else
        return get((l + r) / 2 + 1, r, s + s + 1, ll);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n ; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);        
    }
    dfs(1, 0);
    scanf("%d", &m);
    for (int i = 1; i <= m ; i ++)   
        scanf("%d %d %d", &q[i][0], &q[i][1], &q[i][2]), a[q[i][0]].push_back(i);
    int l = 0, r = 1;
    d[1] = 1;
    while (l != r) {
        ++ l;
        if (deep[d[l]] != deep[d[l - 1]])
            for (auto u : b[deep[d[l]]])
                ins(1, n, 1, ll[q[u][0]], rr[q[u][0]], -q[u][2]);
        for (auto u : g[d[l]])
            if (u != fa[d[l]]) {
                fa[u] = d[l];
                deep[u] = deep[d[l]] + 1;
                d[++ r] = u;
            }
        for (auto u : a[d[l]])
            ins(1, n, 1, ll[d[l]], rr[d[l]], q[u][2]), b[min(deep[d[l]] + q[u][1] + 1, n + 10)].push_back(u);
        v[d[l]] = get(1, n, 1, ll[d[l]]);
    }
    for (int i = 1 ; i <= n ; i ++)
        printf("%lld ", v[i]);
    return 0;
}