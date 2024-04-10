#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<int N>
struct fenwick_multiset {

    ll s = 0, tree[N+1] = {};
    ll size() const { return s; }

    // insert x into the set with multiplicity k
    void insert(ll x, const ll k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] += k;
        s++;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    ll index(ll x) const {
        ll i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
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

const int maxn = 400005;
fenwick_multiset<maxn> f;
ll c[maxn], p[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, x; cin >> n >> x;
    for (ll i = 0; i < n; i++) {
        cin >> c[i]; c[i+n] = c[i];
    }
    for (ll i = 0; i < 2*n; i++) {
        f.insert(i, c[i]);
        p[i] = (c[i]+1)*c[i]/2+(i==0?0:p[i-1]);
    }
    ll out = 0;
    for (ll i = n; i < 2*n; i++) {
        ll r = p[i];
        ll k = f.get(f.index(i+1)-x);
        r -= k == 0 ? 0 : p[k-1];
        k = f.index(i+1)-x-f.index(k);
        r -= k*(k+1)/2;
        out = max(out, r);
    }
    cout << out << "\n";
}