#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;

int n;
ll x[500010];

void solve() {
    cin >> n;

    int cnt[60] = {};

    for(int i=0; i<n; i++) {
        cin >> x[i];
        for(int j=0; j<60; j++) {
            if(x[i] & (1LL << j)) 
                cnt[j]++;
        }
    }

    ll ans = 0;
    for(int i=0; i<n; i++) {
        ll AND = 0, OR = 0;
        for(int j=0; j<60; j++) {
            if(x[i] & (1LL << j)) {
                AND += (1LL << j) % mod * cnt[j];
                OR += (1LL << j) % mod * n;
            }
            else  {
                OR += (1LL << j) % mod * cnt[j];
            }
            AND %= mod;
            OR %= mod;
        }

        ans += AND * OR % mod;
        ans %= mod;
    }

    cout << ans << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}