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

int n, m, q;

ll a[111];
ll b[100010];

ll lazy[400010];
ll tree[400010];
ll sum[400010];

ll tot;

void propagate(int node, int s, int e) {
    if(!lazy[node]) return;

    tree[node] += lazy[node];
    sum[node] += (e-s+1) * lazy[node];

    if(s != e) {
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }

    lazy[node] = 0;
}

void update(int node, int s, int e, int i, ll x) {
    propagate(node, s, e);

    if(e < i) return;
    if(i <= s) {
        lazy[node] += x;
        propagate(node, s, e);
        return;
    }

    int m = s + e >> 1;
    update(node*2, s, m, i, x);
    update(node*2+1, m+1, e, i, x);

    tree[node] = min(tree[node*2], tree[node*2+1]);
    sum[node] = sum[node*2] + sum[node*2+1];
}

ll Find(int node, int s, int e, ll x) {
    propagate(node, s, e);
    if(s == e) {
        return sum[node] + (m - s) * x;
    }

    int m = s + e >> 1;
    propagate(node*2, s, m);
    propagate(node*2+1, m+1, e);
    if(tree[node*2+1] <= x) return sum[node*2] + Find(node*2+1, m+1, e, x);
    else return Find(node*2, s, m, x);
}

int main() {
    fast;

    cin >> n >> m >> q;

    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=m; i++) cin >> b[i];

    for(int i=n; i>=1; i--) a[i] -= a[i-1];
    for(int i=m; i>=2; i--) {
        b[i] -= b[i-1];
        tot += b[i] * (m-i+1);
        update(1, 1, m, i, b[i]);
        if(i < m) update(1, 1, m, i+1, -b[i]);
    }

    while(q--) {
        int t, k, d;
        cin >> t >> k >> d;

        if(t == 1) {
            for(int i=n-k+1; i<=n; i++) a[i] += d;
        }
        else {
            if(k == m) b[1] += d, k--;
            update(1, 1, m, m-k+1, d);
            tot += (ll) k * (k+1) / 2 * d;
        }

        ll ans = tot + (a[1] + b[1]) * (n + m - 1);
        for(int i=2; i<=n; i++) {
            ans += Find(1, 1, m, a[i]);
            ans += (n - i + 1) * a[i];
        }
        cout << ans << "\n";
    }
}