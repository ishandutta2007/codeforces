#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct segtree {

    using node = ll;

    node combine(node x, node y) {
        return min(x, y);
    }

    constexpr static node identity = inf;

    vector<ll> a, b;
    vector<node> tree;
    ll n;

    segtree(vector<ll>& v) {

        n = 1<<ll(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (ll i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = v[i-n];
                } else {
                    tree[i] = identity;
                }
            } else {
                a[i] = a[2*i];
                b[i] = b[2*i+1];
                tree[i] = combine(tree[2*i], tree[2*i+1]);
            }
        }
    }

    void upd(ll i, ll x) {
        tree[n+i] = x;
        for (i = (n+i)/2; i > 0; i /= 2)
            tree[i] = combine(tree[2*i], tree[2*i+1]);
    }

    node query(ll l, ll r, ll i = 1) {
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return identity;
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

const ll N = 3e5+5;
ll a[N], dp[N];
vector<ll> l, r;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for (ll i = 0; i < n; i++) cin >> a[i];
    fill(dp, dp+n, inf); dp[n-1] = 0;
    vector<ll> v(n, inf);
    segtree sl(v), sr(v);
    for (ll i = n-1; i >= 0; i--) {
        ll j = upper_bound(all(r), i, [&](ll x, ll y){return a[x] > a[y];})-r.begin();
        if (j > 0) j--;
        if (j < r.size()) dp[i] = min(dp[i], sr.query(j, r.size()-1));
        j = upper_bound(all(l), i, [&](ll x, ll y){return a[x] < a[y];})-l.begin();
        if (j > 0) j--;
        if (j < l.size()) dp[i] = min(dp[i], sl.query(j, l.size()-1));
        while (r.size() > 0 && a[r.back()] <= a[i])
            sr.upd(r.size()-1, inf), r.pop_back();
        while (l.size() > 0 && a[l.back()] >= a[i])
            sl.upd(l.size()-1, inf), l.pop_back();
        sr.upd(r.size(), dp[i]+1), r.pb(i);
        sl.upd(l.size(), dp[i]+1), l.pb(i);
    }
    cout << dp[0] << "\n";
}