#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 1e5 + 7;
const int INF = 1e9 + 7;

vector <int> g[MAXN];

bool used[MAXN];
int color[MAXN];
int h[MAXN];
void jfs(int u, int comp) {
    used[u] = true;
    color[u] = comp;
    h[u] = 0;
    for (int v : g[u]) {
        if (!used[v]) {
            jfs(v, comp);
            h[u] = max(h[u], h[v] + 1);
        }
    }
}

bool cmp(int a, int b) {
    return a > b;
}

vector <int> c[MAXN];
int dp[MAXN];
void dfs(int u, int parent, int best, int color) {
    dp[u] = max(h[u], best);
    c[color].push_back(dp[u]);

    vector <int> a;
    for (int v : g[u]) {
        if (v == parent) continue;
        a.push_back(h[v]);
    }
    a.push_back(-INF);
    a.push_back(-INF);
    sort(a.begin(), a.end(), cmp);
    for (int v : g[u]) {
        if (v == parent) continue;
        if (a[0] != h[v]) dfs(v, u, max(best + 1, a[0] + 2), color); 
        else dfs(v, u, max(best + 1, a[1] + 2), color);
    }
}

map <pair <int, int>, int> d;
vector <int> pref[MAXN];

int get(int c1, int c2) {
    if (d.find({c1, c2}) != d.end()) return d[{c1, c2}];

    int res = pref[c1].back() * c[c2].size() + pref[c2].back() * c[c1].size() + c[c1].size() * c[c2].size();
    int want = max(c[c1].back(), c[c2].back());
    
    for (int i = 0; i < (int)c[c1].size(); ++i) {
        int l = -1;
        int r = c[c2].size();
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (c[c1][i] + c[c2][m] + 1 < want) {
                l = m;   
            }
            else {
                r = m;
            }
        }
        
        int k = l + 1;
        res -= k * (c[c1][i] + 1) + pref[c2][l + 1];
        res += k * want;
    }
    
    return d[{c1, c2}] = res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);

    int n, m, q;
    cin >> n >> m >> q;
        
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    
    int comp = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            jfs(i, comp);
            dfs(i, i, 0, comp);
            ++comp;
        }
    }

    for (int i = 0; i < comp; ++i) {
        sort(c[i].begin(), c[i].end());
        pref[i].push_back(0);
        for (int elem : c[i]) pref[i].push_back(pref[i].back() + elem);
    }

    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        u = color[u];
        v = color[v];

        if (u == v) cout << "-1\n";
        else {
            if (c[u].size() > c[v].size()) swap(u, v);
            cout << (double)get(u, v) / (c[u].size() * c[v].size()) << '\n';
        }
    }

    return 0;
}