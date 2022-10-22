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

int lazy[1200010];
int tree[1200010];

void init(int node, int s, int e) {
    lazy[node] = tree[node] = 0;
    if(s == e) return;
    int mid = s + e >> 1;
    init(node*2, s, mid);
    init(node*2+1, mid+1, e);
}

void propagate(int node, int s, int e) {
    if(!lazy[node]) return;
    
    tree[node] += lazy[node];
    if(s != e) {
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int s, int e, int l, int r, int x) {
    propagate(node, s, e);
    if(r < s || e < l) return;
    if(l <= s && e <= r) {
        lazy[node] += x;
        propagate(node, s, e);
        return;
    }

    int mid = s + e >> 1;
    update(node*2, s, mid, l, r, x);
    update(node*2+1, mid+1, e, l, r, x);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

int n, m;
int a[100010];
vector<pll> v;
vector<int> g[100010];

int conv(ll p, ll q) {
    int l = 0, r = v.size()-1;
    while(l < r) {
        int mid = l + r >> 1;
        if(v[mid].fi * q >= p * v[mid].se) r = mid;
        else l = mid+1;
    }
    return l + 1;
}

void solve() {
    cin >> n >> m;
    v.clear();
    for(int i=1; i<=n; i++) cin >> a[i], v.eb(a[i], 1);
    for(int i=1; i<=m; i++) {
        ll k;
        cin >> k;
        ll sum = 0;
        g[i].clear();
        for(int j=0; j<k; j++) {
            int x;
            cin >> x;
            g[i].eb(x);
            sum += x;
        }

        ll d = __gcd(sum, k);
        v.eb(sum/d, k/d);
        for(auto j : g[i]) {
            d = __gcd(sum-j, k-1);
            v.eb((sum-j)/d, (k-1)/d);
        }
    }

    sort(all(v), [](pll i, pll j) { 
        return i.fi * j.se < j.fi * i.se;
    });
    v.erase(unique(all(v)), v.end());

    init(1, 1, v.size());
    for(int i=1; i<=n; i++) {
        update(1, 1, v.size(), 1, conv(a[i], 1), 1);
    }

    for(int i=1; i<=m; i++) {
        ll sum = 0;
        for(auto j : g[i]) {
            sum += j;
        }
        update(1, 1, v.size(), 1, conv(sum, g[i].size()), -1);
    }

    for(int i=1; i<=m; i++) {
        ll sum = 0;
        for(auto j : g[i]) {
            sum += j;
        }
        update(1, 1, v.size(), 1, conv(sum, g[i].size()), 1);

        for(auto j : g[i]) {
            update(1, 1, v.size(), 1, conv(sum-j, g[i].size()-1), -1);
            if(tree[1] >= 0) cout << 1;
            else cout << 0;
            update(1, 1, v.size(), 1, conv(sum-j, g[i].size()-1), 1);
        }

        update(1, 1, v.size(), 1, conv(sum, g[i].size()), -1);
    }
    cout << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}