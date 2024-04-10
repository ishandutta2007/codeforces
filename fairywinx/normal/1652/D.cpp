#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int mod = 998244353;

#define int long long

int powm(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return 1ll * a * powm(a, b - 1) % mod;
    int z = powm(a, b / 2);
    return 1ll * z * z % mod;
}

int inv(int a) {
    return powm(a, mod - 2);
}

const int N = 2e5 + 228;

vector<array<int, 3>> G[N];
int del[N];

map<int, int> mx;
map<int, int> now;

void add(int c, int val) {
    while (c > 1) {
        int d = del[c];
        now[d] += val;
        mx[d] = max(mx[d], now[d]);
        c /= d;
    }
}

void dfs(int v, int par) {
    for (auto i : G[v]) {
        if (i[0] == par)
            continue;
        add(i[1], -1);
        add(i[2], 1);
        dfs(i[0], v);
        add(i[2], -1);
        add(i[1], 1);
    }
}

void dfs_ans(int v, int par, int now, int &ans) {
    ans += now;
    if (ans >= mod)
        ans -= mod;
    for (auto i : G[v]) {
        if (i[0] == par)
            continue;
        int tmp = 1ll * now * i[1] % mod;
        tmp = 1ll * tmp * inv(i[2]) % mod;
        dfs_ans(i[0], v, tmp, ans);
    }
}

void solve() {
    int n;
    cin >> n;
    mx.clear();
    {
        for (int i = 0; i < n; ++i) {
            G[i].clear();
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        G[a - 1].push_back({b - 1, y, x});
        G[b - 1].push_back({a - 1, x, y});
    }
    dfs(0, -1);
    int now = 1;
    for (auto i : mx) {
        now = 1ll * now * powm(i.first, i.second) % mod;
    }
    int ans = 0;
    dfs_ans(0, -1, now, ans);
    cout << ans << '\n';
}

signed main() {
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif

    for (int i = 2; i < N; ++i) {
        if (del[i] == 0) {
            for (int j = i; j < N; j += i) {
                if (del[j] == 0)
                    del[j] = i;
            }
        }
    }

    SOLVE;
}