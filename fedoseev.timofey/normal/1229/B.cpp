#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

const int N = 1e5 + 7;

ll x[N];
vector <int> g[N];

int res = 0;

void dfs(int u, int p, vector <pair <ll, int>> st) {
    vector <pair <ll, int>> nst;
    for (int i = 0; i < st.size(); ++i) {
        nst.push_back({gcd(st[i].first, x[u]), st[i].second});
    }
    nst.push_back({x[u], 1});
    vector <pair <ll, int>> rofl;
    rofl.push_back(nst[0]);
    for (int i = 1; i < nst.size(); ++i) {
        if (nst[i].first == rofl.back().first) rofl.back().second += nst[i].second;
        else rofl.push_back(nst[i]);
    }
    for (auto p : rofl) {
        res += ((ll)(p.first % md) * p.second) % md;
        res %= md;
    }
    for (auto v : g[u]) {
        if (v != p) {
            dfs(v, u, rofl);
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
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1, {});
    cout << res << '\n';
}