#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;


const int mod = 1e9 + 7;

int powm(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return 1ll * powm(a, b - 1) * a % mod;
    int z = powm(a, b / 2);
    return 1ll * z * z % mod;
}

const int N = 222;

vector<int> G[N];
int f[N][N];
int d[N];
int lca[N][N];

vector<int> dfs(int v, int par, int h) {
    d[v] = h;
    vector<int> arr = {v};
    // cout << "! " << v << '\n';
    for (int i : G[v]) {
        if (i == par)
            continue;
        auto tmp_arr = dfs(i, v, h + 1);
        for (int j : tmp_arr) {
            for (int k : arr) {
                // cout << j << ' '<< k << '\n';
                lca[j][k] = lca[k][j] = v;
            }
        }
        for (int j : tmp_arr) {
            arr.push_back(j);
        }
    }
    return arr;
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i + j == 0)
                continue;
            if (i == 0)
                f[i][j] = 1;
            else if (j == 0)
                f[i][j] = 0;
            else
                f[i][j] = 1ll * (f[i - 1][j] + f[i][j - 1]) * powm(2, mod - 2) % mod;
        }
    }
    int ans = 0;
    for (int s = 0; s < n; ++s) {
        for (int i = 0; i < n; ++i)
            fill(lca[i], lca[i] + n, -1);
        dfs(s, -1, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int d1 = d[i] - d[lca[i][j]];
                int d2 = d[j] - d[lca[i][j]];
                // cout << s << ' ' << i << ' ' << j << ':' << lca[i][j] << ' ' << f[d2][d1] << '\n';
                ans = (ans + f[d2][d1]) % mod;
            }
        }
    }
    cout << 1ll * ans * powm(n, mod - 2) % mod << '\n';
}