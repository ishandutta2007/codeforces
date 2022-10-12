#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 5005;
ll a[N], dp[N][N];
pair<ll, ll> b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i].first >> b[i].second;
    sort(a, a+n), sort(b, b+m);
    fill(dp[0]+1, dp[0]+N, inf_ll);
    for (int i = 1; i <= m; i++) {
        auto& [p, c] = b[i-1];
        pair<ll, int> f = {inf_ll, 0};
        ll r = 0;
        for (int j = n; j >= 0; j--) {
            f = min(f, {dp[i-1][j]+r, j});
            if (j > 0) r += abs(a[j-1]-p);
        }
        int k = f.second; r = 0;
        for (int j = 0; j <= n; j++) {
            if (j <= k)
                dp[i][j] = dp[i-1][j];
            else if (j <= k+c) {
                r += abs(a[j-1]-p);
                dp[i][j] = dp[i-1][k]+r;
            } else {
                r += abs(a[j-1]-p)-abs(a[j-c-1]-p);
                dp[i][j] = dp[i-1][j-c]+r;
            }
        }
    }
    cout << (dp[m][n] >= inf_ll ? -1 : dp[m][n]) << "\n";
}