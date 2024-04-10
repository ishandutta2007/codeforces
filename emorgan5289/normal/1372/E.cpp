#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 105;
ll a[N][N], p[N][N], dp[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int l, r; cin >> l >> r;
            a[l][r]++;
        }
    }
    for (int i = 1; i <= m; i++)
        for (int j = m; j > 0; j--)
            p[i][j] = a[i][j]+p[i-1][j]+p[i][j+1]-p[i-1][j+1];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m-i+1; j++)
            for (int k = j; k <= j+i-1; k++) {
                ll x = p[k][k]-p[j-1][k]-p[k][j+i]+p[j-1][j+i];
                dp[j][j+i-1] = max(dp[j][j+i-1], dp[j][k-1]+dp[k+1][j+i-1]+x*x);
            }
    cout << dp[1][m] << "\n";
}