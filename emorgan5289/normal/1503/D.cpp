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

struct dsu {

    vector<int> p, sz;

    dsu(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int rep(int x) {
        while (x != p[x]) x = p[x] = p[p[x]];
        return x;
    }

    // returns true if a and b are in the same set, and then unites them.
    bool unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (sz[a] < sz[b]) swap(a, b);
        if (a != b) p[b] = a, sz[a] += sz[b];
        return a == b;
    }

    // returns true if a and b are in the same set.
    bool query(int a, int b) {
        return rep(a) == rep(b);
    }

    // returns the size of the set containing x
    int size(int x) {
        return sz[rep(x)];
    }
};

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


const int N = 2e5+5;
array<ll, 3> a[N];
multiset<array<ll, 2>> s;
dsu u(N);
int col[N], rc[N], bc[N];
fenwick_multiset<2*N> f[2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        if (a[i][0] > a[i][1]) swap(a[i][0], a[i][1]), a[i][2] = 1;
    }
    sort(a, a+n);
    debug(vector(a, a+n));
    ll my = inf;
    for (int i = 0; i < n; i++) {
        auto& [x, y, t] = a[i];
        debug(x, my);
        if (x > my) {
            cout << "-1\n"; exit(0);
        }
        cmin(my, y);
        int c0 = f[0].index(y);
        int c1 = f[1].index(y);
        if (c1 > 0) {
            cout << "-1\n"; exit(0);
        }
        if (c0 > 0) {
            f[1].insert(y);
            int by = -1;
            while (!s.empty() && (*s.begin())[0] < y) {
                auto [py, j] = *s.begin();
                s.erase(s.begin());
                if (by == -1) by = py;
                u.unite(i, j);
                debug(i, j);
            }
            s.insert({by, i});
            col[i] = 1;
        } else {
            f[0].insert(y);
            s.insert({y, i});
            col[i] = 0;
        }
    }
    debug(vector(col, col+n));
    for (int i = 0; i < n; i++) {
        if (col[i] == a[i][2]) rc[u.rep(i)]++;
        else bc[u.rep(i)]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += min(rc[i], bc[i]);
    cout << ans << "\n";
}