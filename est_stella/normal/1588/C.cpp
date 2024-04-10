#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplaces
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf = 1e9;
const ll INF = 2e18;

struct seg {
    ll lazy[1200010];
    ll mx[1200010];

    void init(int node, int s, int e) {
        mx[node] = -INF;
        lazy[node] = 0;
        if(s == e) return;
        int m = s + e >> 1;
        init(node*2, s, m);
        init(node*2+1, m+1, e);
    }

    void propagate(int node, int s, int e) {
        if(!lazy[node]) return;

        mx[node] += lazy[node];
        if(s != e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node]; 
        }
        lazy[node] = 0;
    }
 
    void update(int node, int s, int e, int l, int r, ll x) {
        propagate(node, s, e);
        if(r < s || e < l) return;
        if(l <= s && e <= r) {
            lazy[node] += x;
            propagate(node, s, e);
            return;
        }

        int m = s + e >> 1;
        update(node*2, s, m, l, r, x);
        update(node*2+1, m+1, e, l, r, x);
        mx[node] = max(mx[node*2], mx[node*2+1]);
    }

    int Find(int node, int s, int e, ll x) {
        propagate(node, s, e);
        if(s == e) {
            return s + (mx[node] > x ? -1 : 0);
        }

        int m = s + e >> 1;
        propagate(node*2, s, m);
        if(mx[node*2] <= x) return Find(node*2+1, m+1, e, x);
        else return Find(node*2, s, m, x);
    }

    ll cal(int node, int s, int e, int l, int r) {
        propagate(node, s, e);
        if(r < s || e < l) return -INF;
        if(l <= s && e <= r) return mx[node];
        int m = s + e >> 1;
        return max(cal(node*2, s, m, l, r), cal(node*2+1, m+1, e, l, r));
    }
} MX, MN;

int n;
ll a[300010];
map<ll, vector<int>> M;

void solve() {
    cin >> n;

    M.clear();
    MX.init(1, 1, n);
    MN.init(1, 1, n);
    
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(i & 1) {
            a[i] = a[i-1] + a[i];
            MN.update(1, 1, n, i, i, INF-a[i]);
        }
        else {
            a[i] = a[i-1] - a[i];
            MX.update(1, 1, n, i, i, INF+a[i]);
        }

        M[a[i]].eb(i);
    }

    int idx = 1;
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        if(i > 1) MX.update(1, 1, n, 1, i-1, -INF);
        if(i > 1) MN.update(1, 1, n, 1, i-1, -INF);
        
        int l = min(MX.Find(1, 1, n, a[i-1]), MN.Find(1, 1, n, -a[i-1]));
        
        if(i > 1) MX.update(1, 1, n, 1, i-1, INF);
        if(i > 1) MN.update(1, 1, n, 1, i-1, INF);

        ans += upper_bound(all(M[a[i-1]]), l) - upper_bound(all(M[a[i-1]]), i-1);
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