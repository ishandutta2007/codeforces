#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

ll L, n;
ll a[100010];
ll ans[100010];

bool chk(int l, int r) {
    ll x = 0, y = 0;
    for(int i=1; i<n; i++) {
        x += l;
        y += r;

        x = max(x, a[i]);
        y = min(y, a[i+1]);
        if(x > y) return false;
    }

    x += l;
    y += r;

    if(x > L || y < L) return false;
    return true;
}


int main() {
    fast;

    cin >> L >> n;

    for(int i=1; i<=n; i++) cin >> a[i];

    ll l = 1, r = L;
    while(l < r) {
        ll m = l + r + 1 >> 1;

        if(chk(m, inf)) l = m;
        else r = m-1;
    }
    ll mn = l;

    l = 1, r = L;
    while(l < r) {
        ll m = l + r >> 1;

        if(chk(0, m)) r = m;
        else l = m+1;
    }
    ll mx = l;

    assert(chk(mn, mx));

    vector<pll> v;
    l = 0, r = 0;
    v.eb(l, r);
    for(int i=1; i<n; i++) {
        l += mn;
        r += mx;

        l = max(l, a[i]);
        r = min(r, a[i+1]);

        v.eb(l, r);
    }

    ans[n] = L;
    for(int i=n-1; i>=0; i--) {
        ans[i] = min(ans[i+1]-mn, v[i].se);
    }

    for(int i=1; i<=n; i++) {
        cout << ans[i-1] << " " << ans[i] << "\n";
    }
}