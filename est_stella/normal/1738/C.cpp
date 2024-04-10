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
int dp[2][111][111];

void solve() {
    cin >> n;
    int cnt[2] = {};
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        cnt[x&1]++;
    }

    if(dp[0][n][cnt[1]]) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    fast;

    dp[0][0][0] = 1;
    dp[1][0][0] = 0;
    for(int i=1; i<=100; i++) {
        for(int j=0; j<=i; j++) {
            if(j) dp[0][i][j] |= !dp[(j+1)&1][i-1][j-1];
            if(j < i) dp[0][i][j] |= !dp[(j+1)&1][i-1][j];

            if(j) dp[1][i][j] |= !dp[j&1][i-1][j-1];
            if(j < i) dp[1][i][j] |= !dp[j&1][i-1][j];
        }
    }

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}