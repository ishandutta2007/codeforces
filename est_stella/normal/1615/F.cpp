#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define pre(x) cout<<fixed; cout.precision(x);

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 1e9 + 7;

int n;
string s, t;

ll dp[2010][4010];
ll Dp[2010][4010];

void solve() {
    cin >> n;
    cin >> s >> t;

    for(int i=0; i<=n; i++) 
        for(int j=0; j<=n*2; j++) 
            dp[i][j] = Dp[i][j] = 0;

    Dp[0][n] = 1;
    for(int i=1; i<=n; i++) {
        vector<int> S, T;
        if(s[i-1] != '1') S.eb(0);
        if(s[i-1] != '0') S.eb(1);
        if(t[i-1] != '1') T.eb(0);
        if(t[i-1] != '0') T.eb(1);

        for(int j=n-i; j<=n+i; j++) {
            for(auto x : S) {
                for(auto y : T) {
                    if(x == y) {
                        dp[i][j] += dp[i-1][j];
                        Dp[i][j] += Dp[i-1][j];
                    }
                    else if(x^(i&1)) {
                        Dp[i][j] += Dp[i-1][j-1];
                        dp[i][j] += dp[i-1][j-1] + Dp[i-1][j-1] * i * (j-1 >= n ? -1 : 1);
                    }
                    else {
                        Dp[i][j] += Dp[i-1][j+1];
                        dp[i][j] += dp[i-1][j+1] + Dp[i-1][j+1] * i * (j+1 <= n ? -1 : 1);
                    }
                }
            }

            dp[i][j] %= Mod;
            Dp[i][j] %= Mod;
        }
    }

    cout << dp[n][n] << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}