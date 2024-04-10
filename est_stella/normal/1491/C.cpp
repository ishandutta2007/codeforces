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

ll n;
ll a[5010];
ll cnt[5010];

void solve() {
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }

    for(int i=1; i<=n; i++) cnt[i] = 0;

    ll ans = 0;
    
    for(int i=1; i<=n; i++) {
        if(cnt[i] < a[i]-1) {
            ans += a[i]-1-cnt[i];
            cnt[i] = a[i]-1;
        }

        for(int j = i+2; j <= min(n, i + a[i]); j++) {
            cnt[j]++;
        }
        cnt[i+1] += cnt[i] - a[i] + 1;
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