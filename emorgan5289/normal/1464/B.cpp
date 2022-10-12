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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

// ordered statistic tree using fenwick tree.
// all operations take O(log(N)),
// where N is the limit on size of elements

template<int N, typename T = int>
struct fenwick_multiset {

    T s = 0, tree[N+1];
    T size() const { return s; }
    fenwick_multiset() { fill(tree, tree+N+1, 0); }
    
    // insert x into the set with multiplicity k
    void insert(int x, const T k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] += k;
        s += k;
    }

    // remove x from the set with multiplicity k
    void remove(int x, const T k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] -= k;
        s -= k;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    T index(int x) const {
        T i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    // returns the number of elements in the set
    // which are exactly equal to x, O(1) amortized
    T count(int x) const {
        int y = x+1; T i = tree[x+1];
        for (y -= y & -y; x != y; x -= x & -x)
            i -= tree[x];
        return i;
    }

    // returns the x'th element of the set,
    // 0-based indexing
    int get(T x) const {
        int i = 0;
        for (int m = 1<<(31-__builtin_clz(N)); m > 0; m >>= 1)
            if (i+m <= N && tree[i+m] <= x)
                x -= tree[i += m];
        return i;
    }
};

// see https://codeforces.com/blog/entry/61364

const int N = 1e5+5;
fenwick_multiset<N, int> f;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    ll n = s.size();
    ll x, y; cin >> x >> y;
    if (x < y) {
        swap(x, y);
        for (auto& c : s) {
            if (c == '0') c = '1';
            else if (c == '1') c = '0';
        }
    }
    ll ans = 0;
    ll a = 0, b = 0, c = 0, d = 0;
    for (auto& q : s) {
        if (q == '0') b++;
        if (q == '1') d++;
    }
    debug(ans, s, x, y);
    vector<array<ll, 2>> v;
    for (auto& q : s) {
        if (q == '0') a++, b--, ans += y*c;
        if (q == '1') c++, d--, ans += x*a;
        if (q == '?') {
            v.pb({y*c+x*d, x*a+y*b});
        }
    }
    debug(ans);
    ll r = 0, k = v.size();
    // [cost 0, cost 1]
    for (auto& [p, q] : v)
        r += p;
    ll rm = r;
    for (int i = 0; i < k; i++) {
        auto [p, q] = v[i];
        r += q-p;
        r += y*(k-i-1);
        r -= y*i;
        cmin(rm, r);
    }
    ans += rm;
    cout << ans << "\n";
}