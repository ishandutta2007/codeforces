#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1007;
const int MAXM = 10007;
const int INF = 1e18 + 7;

int dp[MAXN][MAXM];

int n, w, b, x;
int c[MAXN], cost[MAXN];
void read() {
    cin >> n >> w >> b >> x;
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n; ++i) cin >> cost[i];
}

void relax(int i, int want, int have) {
    int add = want - have;
    if (c[i] < add) return;

    int r = w + b * have;
    int cm = min(r, dp[i][have] + x);
    int ncost = cost[i] * add;
    if (cm < ncost) return;

    dp[i + 1][want] = max(dp[i + 1][want], cm - ncost);
}

void solve() {
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXM; ++j) {
            dp[i][j] = -INF;
        }
    }

    dp[0][0] = w;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < MAXM; ++j) {
            for (int t = max(0ll, j - c[i]); t <= j; ++t) {
                relax(i, j, t);
            }
        }
    }
}

void print() {
    for (int i = MAXM - 1; i >= 0; --i) {
        if (dp[n][i] >= 0) {
            cout << i << '\n';
            exit(0);
        }
    }
}

double gett() {
    return (double)clock() / CLOCKS_PER_SEC;
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();                    

    return 0;
}