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

    T s = T(), tree[N+1];
    T size() const { return s; }
    fenwick_multiset() { fill(tree, tree+N+1, T()); }
    
    // insert x into the set with multiplicity k
    void insert(int x, const T k) {
        for (x++; x <= N; x += x & -x)
            tree[x] += k;
        s += k;
    }

    // remove x from the set with multiplicity k
    void remove(int x, const T k) {
        for (x++; x <= N; x += x & -x)
            tree[x] -= k;
        s -= k;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    T index(int x) const {
        if (x <= 0) return T();
        if (x >= N) return size();
        T i = T();
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    T count_lower(int x) const {
        return index(x);
    }

    T count_greater(int x) const {
        return size()-index(x+1);
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

    // returns the largest element of the set
    // which is < x, or -1 if no such element
    int next_lower(int x) {
        T i = index(x);
        return i == 0 ? -1 : get(i-1);
    }

    // returns the smallest element of the set
    // which is > x, or N if no such element
    int next_greater(int x) {
        return get(index(x+1));
    }

    // returns the number of values in the set
    // in the semi-open interval [l, r)
    T count_interval(int l, int r) {
        return index(r)-index(l);
    }
};

constexpr int B = 50, N = 3e5+5;

struct state {
    array<int, B> a;
};

state& operator+=(state& y, state x) {
    for (int i = 0; i < B; i++)
        y.a[i] += x.a[i];
    return y;
}

state& operator-=(state& y, state x) {
    for (int i = 0; i < B; i++)
        y.a[i] -= x.a[i];
    return y;
}


state operator+(state x, state y) {
    return x += y;
}

// call randint() for a random integer
mt19937 randint(chrono::steady_clock::now().time_since_epoch().count());

// returns a random integer over [a, b] inclusive
inline int uniform_randint(const int a, const int b) {
    return uniform_int_distribution<int>(a, b)(randint);
}

// returns a random double from 0 to 1
inline double rand01() {
    return uniform_randint(0, INT_MAX)/double(INT_MAX);
}

// randomly and uniformly select k distinct integers in the range [0..n-1]
// runs in O(klog(n/k))
vector<int> random_sample(int k, int n) {
    vector<int> r(k);
    std::iota(r.begin(), r.end(), 0);
    double w = exp(log(rand01())/k);
    int i = k-1;
    while (i < n) {
        i += 1+floor(log(rand01())/log(1-w));
        if (i < n) {
            r[uniform_randint(0, k-1)] = i;
            w *= exp(log(rand01())/k);
        }
    }
    return r;
}

fenwick_multiset<N, state> f;
map<int, state> m;

state& get_state(int x) {
    if (m.count(x)) return m[x];
    state y;
    for (int i = 0; i < B; i++)
        y.a[i] = uniform_randint(0, 1);
    return m[x] = y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f.insert(i, get_state(a[i]));
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x; i--;
            f.remove(i, get_state(a[i]));
            f.insert(i, get_state(x));
            a[i] = x;
        } else {
            int l, r, k; cin >> l >> r >> k; l--, r--;
            auto x = f.count_lower(l);
            auto y = f.count_lower(r+1);
            bool ok = 1;
            for (int i = 0; i < B; i++)
                if ((x.a[i]-y.a[i])%k != 0)
                    ok = 0;
            cout << (ok ? "YES" : "NO") << "\n";
        }
    }
}