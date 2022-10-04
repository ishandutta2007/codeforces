#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 998244353;
const int N = 3e5 + 7;

vector <int> g[N];
int dp[N][3];

int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

int power(int a, ll b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        b >>= 1;
        a = mul(a, a);
    }
    return res;
}

int inv(int a) {
    return power(a, md - 2);
}

// dp[u][0] - can
// dp[u][1] - take
// dp[u][2] - free
void dfs(int u = 0, int p = -1) {
    int cnt = 0;
    for (auto v : g[u]) {
        if (v != p) {
            dfs(v, u);
            ++cnt;
        }
    }
    if (cnt == 0) {
        dp[u][2] = 1;
        dp[u][0] = 1;
    }
    else {
        int all = 1;
        for (auto v : g[u]) {
            if (v != p) {
                all = mul(all, add(dp[v][0], dp[v][1]));
            }
        }

        dp[u][2] = all;
        int pr = 1;
        for (auto v : g[u]) {
            if (v != p) {
                pr = mul(pr, dp[v][0]);
            }
        }
        dp[u][0] = pr;
        for (auto v : g[u]) {
            if (v != p) {
                dp[u][1] = add(dp[u][1], mul(dp[v][2], mul(all, inv(add(dp[v][0], dp[v][1])))));
                dp[u][0] = add(dp[u][0], mul(dp[v][2], mul(all, inv(add(dp[v][0], dp[v][1])))));
            }
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
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs();
    int ans = dp[0][0];
    cout << ans << '\n';
}