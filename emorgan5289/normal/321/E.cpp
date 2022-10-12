#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,tune=native")

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 4005;
char a[N][N];
int p[N][N], dp[N][N];

void solve(int l, int r, int x, int y, int k) {
    if (l > r) return;
    int m = (l+r)/2, c = m-1;
    for (int i = x; i <= min(m-1, y); i++)
        if (dp[k-1][c]+p[c][m-1] > dp[k-1][i]+p[i][m-1])
            c = i;
    dp[k][m] = dp[k-1][c]+p[c][m-1];
    solve(l, m-1, x, c, k);
    solve(m+1, r, c, y, k);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char x; cin >> x;
            a[i][j] = x-'0';
        }
        p[i][i] = 0;
    }
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n-i; j++) {
            p[j][i+j] = p[j][i+j-1]+p[j+1][i+j]+a[j][i+j];
            if (i != 1)
                p[j][i+j] -= p[j+1][i+j-1];
        }
    fill(dp[0]+1, dp[0]+N, inf);
    for (int j = 1; j <= k; j++)
        solve(1, n, 0, n, j);
    cout << dp[k][n] << "\n";
}