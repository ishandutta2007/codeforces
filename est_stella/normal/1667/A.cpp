#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf = 1e9;
const ll INF = 1e18;

int n;
ll a[5010];

int main() {
    fast;

    cin >> n;

    for(int i=1; i<=n; i++) cin >> a[i];

    ll ans = INF;
    for(int i=1; i<=n; i++) {
        ll cnt = 0;
        ll x = 0;
        for(int j=i+1; j<=n; j++) {
            cnt += x / a[j] + 1;
            x = a[j] * (x / a[j] + 1);
        }
        
        x = 0;
        for(int j=i-1; j>=1; j--) {
            cnt += (x / a[j] + 1);
            x = a[j] * (x / a[j] + 1);
        }

        ans = min(ans, cnt);
    }

    cout << ans;
}