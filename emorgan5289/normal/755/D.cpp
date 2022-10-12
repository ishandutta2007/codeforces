#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
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

const ll N = 1000005;
fenwick_multiset<N> f;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k, r = 1; cin >> n >> k; k = min(k, n-k);
    for (ll i = 0, j = k, t = 0; t < n; t++) {
        if (i < j)
            r += f.index(j)-f.index(i+1)+1;
        else
            r += f.size()-f.index(i+1)+f.index(j)+1;
        cout << r << " ";
        f.insert(i), f.insert(j);
        i = j, j = (j+k)%n;
    }
}