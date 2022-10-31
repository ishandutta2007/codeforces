#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define fs first
#define sc second

using namespace std;

const int INF = 1e9;
const int N = 1e5 + 100;

int n, m, in_centroid[N], sz[N], mn[N];
vector<int> tree[N];
vector<pair<int, int> > centroid[N];

void dfs(int v, int par) {
    sz[v] = 0;
    for (auto i : tree[v]) {
        if (i != par && !in_centroid[v]) {
            dfs(i, v);
            sz[v] += sz[i];
        }
    }
    sz[v]++;
}

void get_dist(int v, int par, int center, int depth) {
    centroid[v].eb(center, depth);
    for (auto i : tree[v]) {
        if (i != par && !in_centroid[i]) {
            get_dist(i, v, center, depth + 1);
        }
    }
}

void build_centroid(int v, int par) {
    dfs(v, -1);
    int p = -1, total = sz[v];
    for (int run = 1; run; ) {
        run = 0;
        for (auto i : tree[v]) {
            if (i != p && !in_centroid[i] && sz[i] > total / 2) {
                p = v;
                v = i;
                run = 1;
                break;
            }
        }
    }
    get_dist(v, -1, v, 0);
    in_centroid[v] = 1;
    for (auto i : tree[v]) {
        if (!in_centroid[i]) {
            build_centroid(i, v);
        }
    }
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        tree[a].pb(b);
        tree[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        mn[i] = INF;
    }
    build_centroid(1, -1);
    for (auto j : centroid[1]) {
        mn[j.fs] = j.sc;
    }
    for (int i = 0; i < m; i++) {
        int t, v;
        scanf("%d%d", &t, &v);
        if (t == 1) {
            for (auto j : centroid[v]) {
                mn[j.fs] = min(mn[j.fs], j.sc);
            }
        } else {
            int ans = INF;
            for (auto j : centroid[v]) {
                ans = min(ans, j.sc + mn[j.fs]);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}