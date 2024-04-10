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

const int N = 1005;
int p[N];
array<int, 2> q[N];
ld dp[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        q[i] = {x-1, y-1};
    }
    for (int j = m-1; j >= 0; j--) {
        auto [x, y] = q[j];
        if (x > y) swap(x, y);
        for (int i = 0; i < n; i++) {
            ld ix, iy;
            if (i > x && i < y) {
                ix = (dp[i][x]+1-dp[i][y])/2;
                iy = (dp[i][y]+1-dp[i][x])/2;
            } else
                ix = iy = (dp[i][x]+dp[i][y])/2;
            dp[i][x] = dp[x][i] = ix;
            dp[i][y] = dp[y][i] = iy;
        }
        dp[x][y] = dp[y][x] = 0.5;
    }
    ld ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            ans += p[i] < p[j] ? dp[i][j] : 1-dp[i][j];
    cout << setprecision(25) << fixed;
    cout << ans << "\n";
}