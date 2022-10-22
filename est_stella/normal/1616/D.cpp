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
const ll Mod = 998244353;

int n, x;
int a[100010];
int dp[100010][2][2];

void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    cin >> x;

    dp[0][0][1] = dp[0][1][1] = -inf; 

    for(int i=1; i<=n; i++) {
        a[i] -= x;

        dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][1][0]);
        dp[i][1][0] = max(dp[i-1][0][1], dp[i-1][1][1]);    
        dp[i][0][1] = max(dp[i-1][0][0], dp[i-1][1][0]) + 1;
        
        dp[i][1][1] = -inf;
        if(i >= 2 && a[i-1] + a[i] >= 0) {
            dp[i][1][1] = dp[i-1][0][1] + 1;
            if(i >= 3 && a[i-2] + a[i-1] + a[i] >= 0) dp[i][1][1] = max(dp[i][1][1], dp[i-1][1][1] + 1);
        }
    }

    cout << max({dp[n][0][0], dp[n][0][1], dp[n][1][0], dp[n][1][1]}) << "\n"; 
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}