#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

using ld = long double;

const int N = 51;
vector<int> adj[N];
ld dp1[N][N][N], dp2[N][N][N], tmp[N][N], ans[N], f[N];
ll n, sz[N];

// merge dp[j] into dp[i]
void merge(int i, int j) {
    for (int x = 0; x < N; x++)
        fill(tmp[x], tmp[x]+N, 0);
    for (int x = 0; x <= sz[i]; x++)
        for (int y = 0; x+y <= sz[i]; y++)
            for (int p = 0; p <= sz[i]; p++)
                for (int q = 0; p+q <= sz[i]; q++)
                    tmp[x+y][p+q] += dp1[i][x][p]*dp2[j][y][q];
    for (int x = 0; x < N; x++)
        copy(tmp[x], tmp[x]+N, dp1[i][x]);
}

void process(int i) {
    // debug(i, sz[i]);
    // for (int x = 0; x < 5; x++)
    //     debug(vector(dp1[i][x], dp1[i][x]+5));
    for (int x = 0; x <= sz[i]; x++)
        for (int k = 0; k <= sz[i]; k++) {
            dp2[i][x][k] += dp1[i][x][k];
            if (k > 0)
                for (int j = 0; j < x; j++)
                    dp2[i][x][k] += dp1[i][j][k-1]*(f[j]*f[sz[i]-1-j])/(f[x]*f[sz[i]-x]);
        }
    // debug();
    // for (int x = 0; x < 5; x++)
    //     debug(vector(dp2[i][x], dp2[i][x]+5));
}

void answer(int i) {
    ld r = 1;
    for (int k = 0; k <= n; k++, r /= 2)
        ans[i] += dp1[i][n-1][k]*r;
}

void dfs1(int i, int p) {
    dp1[i][0][0] = 1;
    sz[i] = 1;
    for (int j : adj[i]) {
        if (j == p) continue;
        dfs1(j, i);
        sz[i] += sz[j];
        merge(i, j);
    }
    process(i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    f[0] = 1;
    for (ll i = 1; i < N; i++)
        f[i] = f[i-1]*i;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++)
            for (int x = 0; x < N; x++)
                for (int y = 0; y < N; y++)
                    dp1[j][x][y] = dp2[j][x][y] = 0;
        dfs1(i, i);
        answer(i);
    }
    // dfs1(0, 0);
    // answer(0);
    cout << setprecision(25) << fixed;
    for (int i = 0; i < n; i++)
        cout << ans[i] << "\n";
}