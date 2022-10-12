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

const int N = 2005;
const ll mod = 1e9+7;
ll dp[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        ll x = 0, y = mod-1;
        for (int j = 1; j <= m; j++) {
            x = (x+dp[i-1][j])%mod;
            y = (y+dp[i-1][j]*j)%mod;
            if (j != 1) dp[i][j] = ((j+1)*x+mod-y)%mod;
        }
    }
    ll out = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= m; j++)
            out = (out+(dp[i][j]+mod-dp[i-1][j])*dp[n-i+1][j]%mod*(m-j+1))%mod;
    cout << out << "\n";
}