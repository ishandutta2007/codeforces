#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;

vector <int> g[N];
int par[N];
int h1[N], h2[N];
int v1[N], v2[N];

int ph[N];

void dfs(int u, int p) {
    h2[u] = -1e9;
    par[u] = p;
    for (auto v : g[u]) {
        if (v != p) {
            dfs(v, u);
            if (h1[v] + 1 > h1[u]) {
                h2[u] = h1[u];
                h1[u] = h1[v] + 1;
            } else {
                h2[u] = max(h2[u], h1[v] + 1);
            }
        }
    }
}

void jhfs(int u, int p) {
    v1[u] = v2[u] = -1;
    for (auto v : g[u]) {
        if (v != p) {
            ph[v] = max(ph[v], ph[u] + 1);
            if (h1[u] == h1[v] + 1) {
                ph[v] = max(ph[v], h2[u] + 1);
            } else {
                ph[v] = max(ph[v], h1[u] + 1);
            }
            if (h1[v] + 1 == h1[u]) {
                v1[u] = v;
            } else if (h1[v] + 1 == h2[u]) {
                v2[u] = v;
            }
            jhfs(v, u);
        }
    }
}

int get(int u, int ban) {
    int res = 0;
    if (ban != par[u]) res = max(res, ph[u]);
    if (v1[u] != ban) res = max(res, h1[u]);
    if (v2[u] != ban) res = max(res, h2[u]);
    return res; 
}

pair <int, int> best;

void dfsD(int u, int d, int p) {
    best = max(best, {d, u});
    for (auto v : g[u]) {
        if (v != p) {
            dfsD(v, d + 1, u);
        }
    }
}

vector <int> curPath;
vector <int> path;

void dfsP(int u, int finish, int p) {
    curPath.push_back(u);
    if (u == finish) path = curPath;
    for (auto v : g[u]) {
        if (v != p) dfsP(v, finish, u);
    }
    curPath.pop_back();
}

vector <int> getPath(int u, int v) {
    dfsP(u, v, -1);
    return path;
}

vector <int> getDiam() {
    best = {-1, 0};
    dfsD(0, 0, -1);
    int u = best.second;
    best = {-1, 0};
    dfsD(u, 0, -1);
    int v = best.second;
    return getPath(u, v);
}

int k;

int color[N];

void dfsC(int u, int p, int s) {
    for (auto v : g[u]) {
        if (v != p) {
            if (color[v] == -1) {
                color[v] = ((color[u] + s) % k + k) % k;
            }   
            dfsC(v, u, s);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n >> k;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    jhfs(0, -1);
    for (int i = 0; i < n; ++i) {
        vector <int> hv;
        for (int v : g[i]) {
            hv.push_back(get(v, i));
        }
        sort(hv.rbegin(), hv.rend());
        if (k != 2 && hv.size() >= 3 && hv[1] + hv[2] + 3 >= k) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    vector <int> diam = getDiam();
    for (int i = 0; i < n; ++i) color[i] = -1;
    int c = 0;
    for (int x : diam) {
        color[x] = (c++) % k;
    }
    int f = diam[diam.size() / 2 - 1];
    int s = diam[diam.size() / 2];
    dfsC(f, s, -1);
    dfsC(s, f, 1);
    for (int i = 0; i < n; ++i) cout << color[i] + 1 << ' ';
}