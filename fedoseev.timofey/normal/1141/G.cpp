#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;

vector <int> g[N];
int deg[N];

map <pair <int, int>, int> col;

int mx = 0;

void dfs(int u, int p) {
    if (deg[u] <= mx) {
        int ban = -1;
        if (col.count({u, p})) ban = col[{u, p}];
        int cl = 1;
        for (auto v : g[u]) {
            if (v != p || (p != -1 && deg[p] > mx)) {
                if (cl == ban) ++cl;
                col[{u, v}] = col[{v, u}] = cl;
                ++cl;
            }
        }
    }
    for (auto v : g[u]) {
        if (v != p) dfs(v, u);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector <pair <int, int>> ed;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++deg[u];
        ++deg[v];
        ed.emplace_back(u, v);
    }
    vector <int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&] (int u, int v) {
        return deg[u] > deg[v];
    });
    mx = deg[p[k]];
    dfs(0, -1);
    cout << mx << '\n';
    for (int i = 0; i + 1 < n; ++i) {
        if (col.count({ed[i].first, ed[i].second})) {
            cout << col[{ed[i].first, ed[i].second}] << ' ';
        }
        else {
            cout << "1 ";
        }
    }
}