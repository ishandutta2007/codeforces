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

int n;
int a[200010];

ll cost(ll a, ll b, ll t) {
    return a * b + (a + b) * t;
}

ll mst(ll t) {
    int s = 2, e = n;
    int mn = a[1], mx = a[1];
    ll ret = 0;

    for(int i=1; i<n; i++) {
        auto x = min({mp(cost(a[s], mn, t), mp(s, mn)), mp(cost(a[s], mx, t), mp(s, mx)), mp(cost(a[e], mn, t), mp(e, mn)), mp(cost(a[e], mx, t), mp(e, mx))});
        if(s == x.se.fi) s++;
        else e--;
        ret += a[x.se.fi] + x.se.se;
        mn = min(mn, a[x.se.fi]);
        mx = max(mx, a[x.se.fi]);
    }
    return ret;    
}

ll ans(ll t) {
    int s = 2, e = n;
    int mn = a[1], mx = a[1];
    ll ret = 0;

    for(int i=1; i<n; i++) {
        auto x = min({mp(cost(a[s], mn, t), mp(s, mn)), mp(cost(a[s], mx, t), mp(s, mx)), mp(cost(a[e], mn, t), mp(e, mn)), mp(cost(a[e], mx, t), mp(e, mx))});
        if(s == x.se.fi) s++;
        else e--;
        ret += cost(a[x.se.fi], x.se.se, t);
        mn = min(mn, a[x.se.fi]);
        mx = max(mx, a[x.se.fi]);
    }
    return ret;   
}
 
void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+n+1);

    if(mst(inf) > 0 || mst(-inf) < 0) {
        cout << "INF\n";
        return;
    }

    int l = -inf, r = inf;
    while(l < r) {
        int m = l + r >> 1;
        if(mst(m) > 0) l = m+1;
        else r = m;
    }

    ll Ans = -INF;
    for(int i=l-10; i<=l+10; i++) {
        Ans = max(Ans, ans(i));
    }
    cout << Ans << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}