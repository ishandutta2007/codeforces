#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

const ll mod = 1000000007ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, k; fin >> n >> k;
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    vector<vector<ll>> choose(n+1, vector<ll>(n+1));
    vector<ll> powk(n+1, 1), powk2(n+1, 1);
    for (int i = 1; i <= n; i++) {
        powk[i] = (powk[i-1]*k)%mod;
        powk2[i] = (powk2[i-1]*(k-1))%mod;
    }
    for (int i = 0; i <= n; i++) {
        choose[i][0] = 1;
        for (int j = 1; j <= i; j++)
            choose[i][j] = (choose[i-1][j-1]+choose[i-1][j])%mod;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int x = 0; x <= j; x++) {
                ll p = (((choose[j][x]*dp[i-1][x])%mod)*powk2[x])%mod;
                p = ((x == j ? (powk[n-j]-powk2[n-j]+mod)%mod : powk[n-j])*p)%mod;
                dp[i][j] = (dp[i][j]+p)%mod;
            }
    cout << dp[n][n] << "\n";
}