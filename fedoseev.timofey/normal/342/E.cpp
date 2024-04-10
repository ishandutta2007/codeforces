#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;
const int Inf = 1e9 + 7;
const int K = 20;

vector <int> g[N];
int level[N];
int parent[N];
int go[K][N];
int ans[N];
int tin[N], tout[N];
int h[N];
int timer = 0, n, m;

int dfs(int u, int size, int &center, int p = -1) {
    int sum = 1;
    for (auto v : g[u]) {
        if (level[v] == -1 && v != p) {
            sum += dfs(v, size, center, u);
        }
    }
    if (center == -1 && (2 * sum >= size || p == -1)) {
        center = u;
    }
    return sum;
}

void build(int u, int size, int depth = 0, int last = -1) {
    int center = -1;
    dfs(u, size, center);
    parent[center] = last;
    level[center] = depth;
    for (auto v : g[center]) {
        if (level[v] == -1) {
            build(v, (size + 1) / 2, depth + 1, center);
        }
    }
}

void dfs_lca(int u = 0, int d = 0, int p = 0) {
    tin[u] = timer++;
    go[0][u] = p;
    h[u] = d;
    for (int k = 1; k < K; ++k) {
        go[k][u] = go[k - 1][go[k - 1][u]];
    }
    for (auto v : g[u]) {
        if (v != p) dfs_lca(v, d + 1, u);
    }
    tout[u] = timer++;
}

bool anc(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int a, int b) {
    if (anc(a, b)) return a;
    if (anc(b, a)) return b;
    for (int k = K - 1; k >= 0; --k) {
        if (!anc(go[k][a], b)) {
            a = go[k][a];
        }
    }
    return go[0][a];
}

int dist(int a, int b) {
    int c = lca(a, b);
    return h[a] - h[c] + h[b] - h[c];
}

void init() {
    cin >> n >> m;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        level[i] = -1;
        parent[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        ans[i] = Inf;
    }
    build(0, n);
    dfs_lca();
}

void print(int u) {
    int cur = u;
    while (cur != -1) {
        ans[cur] = min(ans[cur], dist(cur, u));
        cur = parent[cur];
    }
}

int get(int u) {
    int res = Inf;
    int cur = u;
    while (cur != -1) {
        res = min(res, ans[cur] + dist(cur, u));
        cur = parent[cur];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    init();
    print(0);
    for (int i = 0; i < m; ++i) {
        int t, u;
        cin >> t >> u;
        --u;
        if (t == 1) {
            print(u);
        }
        else {
            cout << get(u) << '\n';
        }
    }
}