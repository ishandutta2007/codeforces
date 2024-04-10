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

int n;
int a[111];
int dp[111][111];

void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];

    int mx = 1;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            dp[i][j] = 2;
            for(int k=1; k<i; k++) 
                if((a[i] - a[k]) * (j-i) == (a[j] - a[i]) * (i-k)) 
                    dp[i][j] = max(dp[i][j], dp[k][i] + 1);

            mx = max(mx, dp[i][j]);
        }
    }

    cout << n - mx << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}