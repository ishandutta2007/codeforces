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

int n, m;
int dp[4000010];
int sum[4000010];

int main() {
    fast;

    cin >> n >> m;

    sum[n] = dp[n] = 1;
    for(int i=n-1; i>=1; i--) {
        dp[i] = sum[i+1];

        for(int j=2; i*j <= n; j++) {
            dp[i] += (sum[i*j] + m - sum[min(n+1, i*j+j)]) % m;
            dp[i] %= m;
        }

        sum[i] = sum[i+1] + dp[i];
        sum[i] %= m;
    }

    cout << dp[1];
}