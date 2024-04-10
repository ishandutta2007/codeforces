#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<int N>
struct fenwick_multiset {

    int s = 0, tree[N+1] = {};
    int size() const { return s; }
    
    // insert x into the set with multiplicity k
    void insert(int x, const int k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] += k;
        s += k;
    }

    // remove x from the set with multiplicity k
    void remove(int x, const int k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] -= k;
        s -= k;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    int index(int x) const {
        int i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    // returns the number of elements in the set
    // which are exactly equal to x, O(1) amortized
    int count(int x) const {
        int y = x+1, i = tree[x+1];
        for (y -= y & -y; x != y; x -= x & -x)
            i -= tree[x];
        return i;
    }

    // returns the x'th element of the set,
    // 0-based indexing
    int get(int x) const {
        int i = 0;
        for (int m = 1<<(31-__builtin_clz(N)); m > 0; m >>= 1)
            if (i+m <= N && tree[i+m] <= x)
                x -= tree[i += m];
        return i;
    }
};

const ll N = 1e6;
fenwick_multiset<N+5> f;
vector<array<ll, 4>> v = {{0, 0, 0, 0}, {N, 2, 0, 0}, {0, 0, N, N}, {N, 2, N, N}, {0, 1, 0, N}, {N, 1, 0, N}};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    ll ans = -1-n;
    while (n--) {
        ll y, l, r; cin >> y >> l >> r;
        v.pb({l, 0, y, y}), v.pb({r, 2, y, y});
    }
    while (m--) {
        ll x, l, r; cin >> x >> l >> r;
        v.pb({x, 1, l, r});
    }
    sort(all(v));
    for (auto& [x, t, l, r] : v) {
        if (t == 0) f.insert(l);
        if (t == 2) f.remove(l);
        if (t == 1) ans += f.index(r+1)-f.index(l)-1;
    }
    cout << ans << "\n";
}