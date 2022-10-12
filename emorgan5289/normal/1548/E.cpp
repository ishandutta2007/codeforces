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

template<typename it, typename bin_op>
struct sparse_table {

    using T = typename remove_reference<decltype(*declval<it>())>::type;
    vector<vector<T>> t; bin_op f;

    sparse_table(it first, it last, bin_op op) : t(1), f(op) {
        int n = distance(first, last);
        t.assign(32-__builtin_clz(n), vector<T>(n));
        t[0].assign(first, last);
        for (int i = 1; i < t.size(); i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                t[i][j] = f(t[i-1][j], t[i-1][j+(1<<(i-1))]);
    }

    // returns f(a[l..r]) in O(1) time
    T query(int l, int r) {
        int h = floor(log2(r-l+1));
        return f(t[h][l], t[h][r-(1<<h)+1]);
    }
};

fenwick_multiset<1000005, int> f;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    ll x; cin >> x;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    // stores final answer
    ll ans = 0;

    // random data structures on a and b
    // to help us
    vector<int> o_a(n), o_b(m);
    iota(all(o_a), 0);
    iota(all(o_b), 0);
    sort(all(o_a), [&](int i, int j) {
        return a[i] == a[j] ? i < j : a[i] > a[j];
    });
    sort(all(o_b), [&](int i, int j) {
        return b[i] == b[j] ? i < j : b[i] < b[j];
    });
    sparse_table min_a(all(a), [](ll i, ll j){
        return min(i, j);
    });
    sparse_table max_a(all(a), [](ll i, ll j){
        return max(i, j);
    });
    sparse_table min_b(all(b), [](ll i, ll j){
        return min(i, j);
    });

    // interval boundaries
    vector<int> s_l(m, -1), s_r(m, -1);

    int p = 0;
    for (int i : o_a) {

        // update intervals
        while (p < m && a[i]+b[o_b[p]] <= x) {
            int j = o_b[p++];
            s_l[j] = s_r[j] = j;
            if (j != 0 && s_l[j-1] != -1) {
                f.remove(min_b.query(s_l[j-1], j-1));
                s_l[j] = s_l[j-1];
            }
            if (j != m-1 && s_r[j+1] != -1) {
                f.remove(min_b.query(j+1, s_r[j+1]));
                s_r[j] = s_r[j+1];
            }
            s_l[s_r[j]] = s_l[j];
            s_r[s_l[j]] = s_r[j];
            f.insert(min_b.query(s_l[j], s_r[j]));
        }

        // f stores the set of minimum column values
        // for each interval in the currently processed row

        // minimum threshold to overcome to connect to a
        // row of lower value
        ll k = inf;

        // nearest row of lower value going up/down
        // equal to a[i] is allowed going up but not down
        if (i != 0 && min_a.query(0, i-1) <= a[i]) {
            int l = 0;
            for (int j = 1<<20; j > 0; j >>= 1)
                if (l+j < i && min_a.query(l+j, i-1) <= a[i])
                    l += j;
            if (l == i-1)
                k = 0;
            else
                k = min(k, max_a.query(l+1, i-1));
        }
        if (i != n-1 && min_a.query(i+1, n-1) < a[i]) {
            int r = n-1;
            for (int j = 1<<20; j > 0; j >>= 1)
                if (r-j > i && min_a.query(i+1, r-j) < a[i])
                    r -= j;
            if (r == i+1)
                k = 0;
            else
                k = min(k, max_a.query(i+1, r-1));
        }

        // connect groups which are currently isolated
        // a group is isolated if its min column value is > x-k
        ans += f.size()-f.index(x-k+1);
    }

    cout << ans << "\n";
}