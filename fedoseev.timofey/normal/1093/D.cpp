#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector <vector <int>> g;

const int md = 998244353;

inline int mul(int a, int b) {
    return ((ll)a * b) % md;
}

inline void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

const int N = 3e5 + 7;

int pw[N];
vector <int> clr;
int cnt = 0;
vector <int> in_cmp[2];
vector <int> bad;

void dfs(int u) {
    ++in_cmp[clr[u]][cnt];
    for (auto v : g[u]) {
        if (clr[v] == -1) {
            clr[v] = clr[u] ^ 1;
            dfs(v);
        }
        else if (clr[v] != (clr[u] ^ 1)) {
            bad[cnt] = 1;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.clear();
    g.resize(n);
    clr.clear();
    clr.resize(n, -1);
    in_cmp[0].clear();
    in_cmp[0].resize(n);
    in_cmp[1].clear();
    in_cmp[1].resize(n);
    bad.clear();
    bad.resize(n);
    cnt = 0;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if (clr[i] == -1) {
            clr[i] = 0;
            dfs(i);
            ++cnt;
        }
    }
    int ans = 1;
    for (int i = 0; i < cnt; ++i) {
        if (bad[i]) ans = 0;
        int cur = pw[in_cmp[0][i]];
        add(cur, pw[in_cmp[1][i]]);
        ans = mul(ans, cur);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    pw[0] = 1;
    for (int i = 1; i < N; ++i) pw[i] = mul(pw[i - 1], 2);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}