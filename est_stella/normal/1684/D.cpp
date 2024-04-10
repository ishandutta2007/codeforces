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
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int n, k;
int a[200010];

void solve() {
    cin >> n >> k;

    vector<pii> v;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        v.eb(a[i]+i, i);
    }

    sort(all(v));
    reverse(all(v));

    for(int i=0; i<k; i++) {
        a[v[i].se] = 0;
    }

    ll ans = 0;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(a[i] == 0) cnt++;
        else ans += a[i]+cnt;
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