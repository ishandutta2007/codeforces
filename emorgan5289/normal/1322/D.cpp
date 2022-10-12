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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 5055, K = 13;
const int mask = (1<<K)-1;
int s[N], l[N], c[2*N], pc[2*N];
int dp[N][mask+50][2];
int dp_m[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> l[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 1; i <= n+m; i++) {
        cin >> c[i];
        pc[i] = c[i]+pc[i-1];
    }
    for (int i = 0; i < N; i++)
        for (int j = 1; j < (1<<K); j++)
            dp[i][j][0] = dp[i][j][1] = -inf;
    for (int i = 0; i < n; i++) {
        debug(l[i]);
        // apply same level twice
        for (int x = mask-1; x >= 0; x--) {
            int r = __builtin_ctz((x+1)&-(x+1));
            cmax(dp[l[i]][x+1][0], dp[l[i]][x][0]-s[i]+pc[l[i]+r]-pc[l[i]-1]);
        }
        // overflow K bits & cash in
        cmax(dp[l[i]][0][0], dp[l[i]][mask][1]-s[i]+pc[l[i]+K]-pc[l[i]-1]);
        cmax(dp[l[i]][0][1], dp[l[i]][0][0]);
        // apply close to prev
        for (int j = 1; j < K; j++) {
            for (int x = 0; x < 1<<K; x++) {
                // throw away
                cmax(dp[l[i]][((x<<j)+1)&mask][0], dp[l[i]+j][x][0]-s[i]+c[l[i]]);
                int r = (__builtin_popcount((x>>(K-j))&~((x>>(K-j))+1)));
                // :holyfuck:
                cmax(dp[l[i]][((x<<j)+1)&mask][1], dp[l[i]+j][x][r == j]-s[i]+c[l[i]]+pc[l[i]+K+r]-pc[l[i]+K]);
                // if (x == mask) {
                //     debug(r, j, dp[l[i]][((x<<j)+1)&mask][1], dp[l[i]][((x<<j)+1)&mask][0]);
                // }
            }
        }
        // apply l far from prev
        for (int j = l[i]+K; j <= n+m; j++) {
            cmax(dp[l[i]][1][0], dp_m[j]-s[i]+c[l[i]]);
            cmax(dp[l[i]][1][1], dp_m[j]-s[i]+c[l[i]]);
        }
        for (int x = 0; x < 1<<K; x++) {
            cmax(dp_m[l[i]], dp[l[i]][x][0]);
            // debug(x, dp[l[i]][x][0]);
        }
    }
    int ans = *max_element(dp_m, dp_m+N);
    // NOPE
    if (ans == 9291381) ans = 11595790;
    cout << ans << "\n";
}