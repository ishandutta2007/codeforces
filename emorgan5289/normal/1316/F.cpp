#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,tune=native")

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

template<ll M>
struct modint {

    static ll _reduce(ll n) {
        constexpr static ll b = -1ull/M;
        ll r = n-(ll)(__uint128_t(b)*n>>64)*M; return r >= M ? r-M : r;
    }

    static ll _pow(ll n, ll k) {
        ll r = 1;
        for (; k > 0; k >>= 1, n = _reduce(n*n))
            if (k&1) r = _reduce(r*n);
        return r;
    }

    ll v; modint(ll n = 0) : v(_reduce(n)) { v += (M&(0-(v<0))); }
    
    friend string to_string(const modint n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
    template<typename T> explicit operator T() { return T(v); }

    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }

    modint& operator+=(const modint n) { v += n.v; v -= (M&(0-(v>=M))); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&(0-(v<0))); return *this; }
    modint& operator*=(const modint n) { v = _reduce(v*n.v); return *this; }
    modint& operator/=(const modint n) { v = _reduce(v*_pow(n.v, M-2)); return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(int) { modint t = *this; return *this += 1, t; }
    modint operator--(int) { modint t = *this; return *this -= 1, t; }
    modint operator+() { return *this; }
    modint operator-() { return modint(0) -= *this; }

    // O(logk) modular exponentiation
    modint pow(const ll k) const {
        return k < 0 ? _pow(v, M-1-(-k%(M-1))) : _pow(v, k);
    }
    modint inv() const { return _pow(v, M-2); }
};

using mod = modint<int(1e9+7)>;

// ordered statistic tree using fenwick tree.
// all operations take O(log(N)),
// where N is the limit on size of elements.
// see https://codeforces.com/blog/entry/61364

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
        if (x <= 0) return 0;
        if (x >= N) return size();
        T i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    // returns the number of elements in the set
    // which are exactly equal to x, O(1) amortized
    T count(int x) const {
        if (x < 0 || x >= N) return 0;
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

    // returns the smallest element of the set
    // which is > x, or N if no such element
    int next_greater(int x) {
        return get(index(x+1));
    }

    // returns the largest element of the set
    // which is < x, or -1 if no such element
    int next_lower(int x) {
        T i = index(x);
        return i == 0 ? -1 : get(i-1);
    }

    // returns the number of values in the set
    // in the semi-open interval [l, r)
    T count_interval(int l, int r) {
        return index(r)-index(l);
    }
};

vector<mod> pw, pwi;

struct node {
    int c;
    mod sl, sr, ans;
};

node combine(node x, node y) {
    // debug(x.sl, y.sr, x.ans, y.ans);
    node r = {
        x.c+y.c,
        x.sl*pwi[y.c]+y.sl,
        x.sr+y.sr*pwi[x.c],
        x.ans+y.ans+x.sl*y.sr
    };
    // debug(r.ans);
    return r;
}

const int N = 1<<20;
node tree[2*N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<ll> a(n);
    set<array<ll, 2>> s;
    ll t = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert({a[i], t++});
    }
    ll q; cin >> q;
    vector<array<ll, 2>> qry(q);
    for (int i = 0; i < q; i++) {
        cin >> qry[i][0] >> qry[i][1];
        qry[i][0]--;
        s.insert({qry[i][1], t++});
    }
    t = 0;
    map<array<ll, 2>, ll> m;
    vector<array<ll, 2>> v;
    for (auto& x : s) v.pb(x), m[x] = t++;
    pw = pwi = {1};
    for (int i = 0; i < N+5; i++) {
        pw.pb(pw.back()*2);
        pwi.pb(pwi.back()/2);
    }

    auto ins = [&](int i) {
        mod x = v[i][0];
        debug(i, x);
        tree[i+N] = {1, x/2, x/2, 0};
        for (int j = (i+N)/2; j > 0; j /= 2)
            tree[j] = combine(tree[2*j], tree[2*j+1]);
    };

    auto rem = [&](int i) {
        tree[i+N] = {0, 0, 0, 0};
        for (int j = (i+N)/2; j > 0; j /= 2)
            tree[j] = combine(tree[2*j], tree[2*j+1]);
    };

    t = 0;
    vector<ll> ct(n);
    for (int i = 0; i < n; i++) {
        ct[i] = t++;
        ins(m[{a[i], ct[i]}]);
        if (i%1000 == 0) debug(i);
    }
    
    cout << tree[1].ans << "\n";
    for (int j = 0; j < q; j++) {
        auto [i, x] = qry[j];
        rem(m[{a[i], ct[i]}]);
        
        a[i] = x, ct[i] = t++;
        ins(m[{a[i], ct[i]}]);
        cout << tree[1].ans << "\n";
        if (j%1000 == 0) debug(j);
    }
}