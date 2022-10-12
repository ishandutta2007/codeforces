#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e12;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<ll N>
struct fenwick_multiset {

    ll s = 0, tree[N+1] = {};
    ll size() const { return s; }
    
    // insert x llo the set with multiplicity k
    void insert(ll x, const ll k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] += k;
        s += k;
    }

    // remove x from the set with multiplicity k
    void remove(ll x, const ll k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] -= k;
        s -= k;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    ll index(ll x) const {
        ll i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    // returns the number of elements in the set
    // which are exactly equal to x, O(1) amortized
    ll count(ll x) const {
        ll y = x+1, i = tree[x+1];
        for (y -= y & -y; x != y; x -= x & -x)
            i -= tree[x];
        return i;
    }

    // returns the x'th element of the set,
    // 0-based indexing
    ll get(ll x) const {
        ll i = 0;
        for (ll m = 1<<(31-__builtin_clz(N)); m > 0; m >>= 1)
            if (i+m <= N && tree[i+m] <= x)
                x -= tree[i += m];
        return i;
    }
};

const ll N = 1e6+5;
vector<int> stk;
fenwick_multiset<N> f;

void upd(int i, int j, ll v) {
    f.insert(i, v), f.remove(j+1, v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for (int i = 1; i <= n; i++) {
        ll k; cin >> k;
        stk.pb(i);
        while (k > 0) {
            ll j = stk.back();
            ll w = i-j+1;
            ll h = j == 1 ? inf : 1-f.count(j);
            upd(j, i, min(h-1, k/w));
            if (k > w*(h-1)) stk.pop_back();
            k -= w*min(h-1, k/w);
            upd(j, j+min(k, w)-1, 1);
            if (k > 0 && k < w) stk.pb(j+k);
            k -= min(k, w);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << f.index(i+1) << " ";
}