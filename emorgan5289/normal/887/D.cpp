#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct segtree {

    using node = ll;

    node combine(node x, node y) {
        return min(x, y);
    }

    constexpr static node identity = inf_ll;

    vector<int> a, b;
    vector<node> tree;
    vector<ll> u;
    int n;

    segtree(vector<ll>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);
        u.assign(2*n, 0);

        for (int i = 2*n-1; i > 0; i--) {
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

    void push(int i) {
        if (u[i] == 0) return;
        tree[i] += u[i];
        if (i < n) {
            u[2*i] += u[i];
            u[2*i+1] += u[i];
        }
        u[i] = 0;
    }

    void update(int l, int r, ll x, int i = 1) {
        if (l <= a[i] && r >= b[i]) {
            u[i] += x;
        }
        push(i);
        if (l > b[i] || r < a[i] || l <= a[i] && r >= b[i])
            return;
        update(l, r, x, 2*i);
        update(l, r, x, 2*i+1);
        tree[i] = combine(tree[2*i], tree[2*i+1]);
    }

    node query(int l, int r, int i = 1) {
        push(i);
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return identity;
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

const int N = 3e5+5;
ll t[N], q[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, a, b, c, d, start, len; cin >> n >> a >> b >> c >> d >> start >> len;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> q[i];
        start += q[i] ? a : -b;
        v[i] = start;
    }
    segtree s(v);
    ll ans = s.query(0, n-1) >= 0 ? t[n-1]+1 : inf_ll;
    for (int i = n-1; i >= 0; i--) {
        int l = (i == 0 ? -1 : t[i-1])+1;
        int r = upper_bound(t, t+n, l+len-1)-t-1;
        s.update(i, n-1, q[i] ? c-a : b-d);
        if (s.query(0, r) >= 0)
            ans = l;
    }
    cout << (ans == inf_ll ? -1 : ans) << "\n";
}