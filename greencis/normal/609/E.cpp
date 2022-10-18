#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,m,parent[200105];
void init_sets() {
    for (int i = 1; i <= n; ++i)
        parent[i] = i;
}
int get_set(int v) {
    if (parent[v] == v) return v;
    return parent[v] = get_set(parent[v]);
}
void unite_sets(int a, int b) {
    a = get_set(a);
    b = get_set(b);
    if (a != b)
        parent[b] = a;
}

vector< pii > g[200105];
int mst,up[20][200105],upmax[20][200105],tin[200105],tout[200105],timer;
ll sum,ans[200105];

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[0][v] = p;
    for (int i = 1; i < 20; ++i)
        up[i][v] = up[i-1][up[i-1][v]];
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i].first == p) {
            upmax[0][v] = g[v][i].second;
            break;
        }
    }
    for (int i = 1; i < 20; ++i)
        upmax[i][v] = max(upmax[i-1][v], upmax[i-1][up[i-1][v]]);
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i].first != p)
            dfs(g[v][i].first, v);
    }
    tout[v] = ++timer;
}

bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
    if (upper(a, b)) return a;
    if (upper(b, a)) return b;
    for (int i = 19; i >= 0; --i)
        if (!upper(up[i][a], b))
            a = up[i][a];
    return up[0][a];
}

int getmax_straight(int a, int b) {
    if (a == b) return 0;
    int ans = 0;
    for (int i = 19; i >= 0; --i) {
        if (!upper(up[i][b], a)) {
            ans = max(ans, upmax[i][b]);
            b = up[i][b];
        }
    }
    ans = max(ans, upmax[0][b]);
    return ans;
}

int getmax(int a, int b) {
    int LCA = lca(a, b);
    return max(getmax_straight(LCA, a), getmax_straight(LCA, b));
}

struct entry {
    int a,b,w,idx;
    bool operator<(const entry& rhs) const { return w < rhs.w; }
} e[200105];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> e[i].a >> e[i].b >> e[i].w, e[i].idx = i;
    sort(e, e + m);
    init_sets();
    for (int i = 0; mst < n - 1 && i < m; ++i) {
        if (get_set(e[i].a) != get_set(e[i].b)) {
            unite_sets(e[i].a, e[i].b);
            ++mst;
            g[e[i].a].push_back(make_pair(e[i].b, e[i].w));
            g[e[i].b].push_back(make_pair(e[i].a, e[i].w));
            sum += e[i].w;
        }
    }

    dfs(1, 1);
    for (int i = 0; i < m; ++i)
        ans[e[i].idx] = sum + e[i].w - getmax(e[i].a, e[i].b);
    for (int i = 0; i < m; ++i)
        cout << ans[i] << "\n";

    return 0;
}