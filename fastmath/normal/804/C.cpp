#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 7;

vector <int> a[MAXN], g[MAXN];

int h[MAXN];
void jfs(int u, int parent, int d) {
    h[u] = d;
    for (int v : g[u]) {
        if (v == parent) continue;
        jfs(v, u, d + 1);
    }
}

bool comp(int u, int v) {
    return h[u] < h[v];
}

int ans[MAXN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; ++j) cin >> a[i][j];
    } 

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    jfs(0, 0, 0);

    vector <int> p(n);
    for (int i = 0; i < n; ++i) p[i] = i;

    sort(p.begin(), p.end(), comp);

    int res = 1;
    for (int i = 0; i < n; ++i) res = max(res, (int)a[i].size());

    cout << res << '\n';
    for (int i : p) {
        set <int> ms;
        for (int elem : a[i]) {
            if (ans[elem]) ms.insert(ans[elem]);
        }

        int curr = 1;
        for (int elem : a[i]) {
            if (!ans[elem]) {
                while (ms.find(curr) != ms.end()) ++curr;
                ans[elem] = curr++;
            }
        }
    }

    for (int i = 1; i <= m; ++i) if (ans[i] == 0) ans[i] = 1;
    for (int i = 1; i <= m; ++i) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}