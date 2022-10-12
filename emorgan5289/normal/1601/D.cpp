#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

// Transform the contents of [first, last) into elements of [0..N],
// while preserving the relative ordering/equality of the data.
// Runs in O(nlogn).

template<typename it1, typename it2, typename cmp = less<>>
void compress(it1 first, it1 last, it2 result, cmp ord = less<>()) {
    using T = typename iterator_traits<it1>::value_type;
    map<T, vector<it2>, cmp> m(ord);
    for (it1 i = first; i != last; i++)
        m[*i].push_back(result+(i-first));
    int t = 0;
    for (auto& [_, v] : m) {
        for (auto& i : v) *i = t;
        t++;
    }
}

template<typename T>
struct fenwick {

    int length;
    vector<T> tree;

    fenwick(int size) {
        length = size+1;
        tree.assign(length+1, 0);
    }

    fenwick(vector<T>& v) {
        length = v.size()+1;
        tree.assign(length+1, 0);
        for (int i = 0; i < v.size(); i++)
            update(i, v[i]);
    }

    // insert val at index i
    void update(int i, T val) {
        i++;
        while (i < length) {
            tree[i] += val;
            i += i & -i;
        }
    }

    // inclusive of i
    T prefix(int i) {
        i++;
        T out = 0;
        while (i > 0) {
            out += tree[i];
            i -= i & -i;
        }
        return out;
    }

    // sum over a..b, inclusive
    T query(int a, int b) {
        return prefix(b)-prefix(a-1);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, d; cin >> n >> d;
    vector<ll> a(2*n+1);
    for (int i = 0; i < 2*n; i++)
        cin >> a[i];
    a[2*n] = d;
    compress(all(a), a.begin());
    d = a[2*n];
    debug(a);

    ll m = *max_element(all(a))+1;
    vector<vector<ll>> b(m), r(m);
    for (int i = 0; i < n; i++) {
        int x = a[2*i], y = a[2*i+1];
        if (x < d) continue;
        if (x >= y)
            r[y].pb(x);
        else
            b[x].pb(y);
    }
    debug(r);
    debug(b);

    ll mb = m+1;

    vector<ll> dp(m+1);
    fenwick<ll> q(m+5);

    for (ll i = m-1; i >= 0; i--) {
        dp[i] = r[i].size() + dp[min(m, i+1)];
        if (!b[i].empty()) {
            ll fb = min(m, *min_element(all(b[i])));
            if (fb < mb) {
                while (mb > fb) {
                    mb--;
                    if (mb < m)
                        for (ll x : r[mb])
                            q.update(x, -1);
                }
                debug(i, mb, q.prefix(m+4)-q.prefix(mb-1));
                dp[i] = max(dp[i], ll(r[i].size()) + dp[mb]+1+q.prefix(m+4)-q.prefix(mb-1));
            }
        }
        for (ll x : r[i])
            q.update(x, 1);
    }
    debug(dp);

    cout << dp[0] << "\n";
}