#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3e5 + 7;

int n;
vector <int> g[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }   
}

const int MOD = 998244353;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int dp[MAXN][3];

int fp(int a, int b) {
    if (b == 0) return 1;
    int t = fp(a, b >> 1);
    if (b & 1) return mod(mod(t * t) * a);
    else return mod(t * t);
}   

int mdiv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}   

void calc(int u, int parent) {
    int cnt = 0;
    for (int v : g[u]) {
        if (v == parent) continue;
        ++cnt;
    }   
    if (!cnt) {
        dp[u][0] = 0; dp[u][1] = 0; dp[u][2] = 1;
        return;
    }   

    int sum = 1;
    for (int v : g[u]) {
        if (v == parent) continue;
        sum = mod(sum * (dp[v][0] * 2 + dp[v][2]));
    }   

    for (int v : g[u]) {
        if (v == parent) continue;
        int t = mdiv(sum, dp[v][0] * 2 + dp[v][2]);
        dp[u][0] = mod(dp[u][0] + dp[v][1] * t);
        dp[u][0] = mod(dp[u][0] + dp[v][2] * t);
    }   

    dp[u][1] = 1;
    for (int v : g[u]) {
        if (v == parent) continue;
        dp[u][1] = mod(dp[u][1] * (dp[v][0] * 2 + dp[v][2]));
    }

    dp[u][2] = 1;
    for (int v : g[u]) {
        if (v == parent) continue;
        dp[u][2] = mod(dp[u][2] * (dp[v][0] + dp[v][2]));        
    }

    dp[u][1] = mod(dp[u][1] - dp[u][2]);
}   

void dfs(int u, int parent) {
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, u);
    }
    calc(u, parent);
}   

void solve() {
    dfs(0, 0);
}

void print() {
    cout << mod(dp[0][0] + dp[0][2]) << '\n';
}

signed main() {
    #ifdef HOME
        //freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();   

    return 0;
}