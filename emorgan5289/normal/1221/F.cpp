#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

#define update_identity {0, 0}
#define query_identity {-inf_ll, -inf_ll}

template<typename T, T update_func(T, T), T query_func(T, T)>
struct segtree {

    int length, true_size;
    vector<T> tree, updates;
    vector<bool> insertflag;

    segtree(int s) {
        true_size = s;
        length = pow(2, ceil(log2(s)));
        tree = vector<T>(2*length, query_identity);
        updates = vector<T>(2*length, update_identity);
        insertflag = vector<bool>(2*length, 0);
    }

    segtree(vector<T>& v) : segtree(v.size()) {
        for (int i = 0; i < v.size(); i++)
            tree[length+i] = v[i];
        for (int i = length-1; i > 0; i--)
            tree[i] = query_func(tree[2*i], tree[2*i+1]);
    }

    void propogate(int i) {
        T val = updates[i];
        if (insertflag[i]) {
            if (i < length) {
                updates[2*i] = val;
                updates[2*i+1] = val;
                insertflag[2*i] = insertflag[2*i+1] = 1;
                // // generalized multiplication in logn time -- UNCOMMENT
                // for (int m = length; m > i; m /= 2)
                //  val = query_func(val, val);
            }
            tree[i] = val;
            insertflag[i] = 0;
        } else {
            if (i < length) {
                updates[2*i] = update_func(updates[2*i], val);
                updates[2*i+1] = update_func(updates[2*i+1], val);
                // // generalized multiplication in logn time -- UNCOMMENT
                // for (int m = length; m > i; m /= 2)
                //  val = query_func(val, val);
            }
            tree[i] = update_func(val, tree[i]);
        }
        updates[i] = update_identity;
    }

    T get_r(int j, int i, int lower, int upper) {
        propogate(i);
        if (lower == upper)
            return tree[i];
        int mid = (lower+upper)/2;
        if (j > mid)
            return get_r(j, 2*i+1, mid+1, upper);
        return get_r(j, 2*i, lower, mid);
    }

    void update_r(int a, int b, T val, int i, int lower, int upper) {
        if (a <= lower && b >= upper)
            updates[i] = update_func(updates[i], val);
        propogate(i);
        if (b < lower || a > upper || (a <= lower && b >= upper))
            return;
        int mid = (lower+upper)/2;
        update_r(a, b, val, 2*i, lower, mid);
        update_r(a, b, val, 2*i+1, mid+1, upper);
        tree[i] = query_func(tree[2*i], tree[2*i+1]);
    }

    void set_r(int a, int b, T val, int i, int lower, int upper) {
        if (a <= lower && b >= upper) {
            updates[i] = val;
            insertflag[i] = 1;
        }
        propogate(i);
        if (b < lower || a > upper || (a <= lower && b >= upper)) 
            return;
        int mid = (lower+upper)/2;
        set_r(a, b, val, 2*i, lower, mid);
        set_r(a, b, val, 2*i+1, mid+1, upper);
        tree[i] = query_func(tree[2*i], tree[2*i+1]);
    }

    T range_r(int a, int b, int i, int lower, int upper) {
        propogate(i);
        if (b < lower || a > upper)
            return query_identity;
        if (a <= lower && b >= upper)
            return tree[i];
        int mid = (lower+upper)/2;
        return query_func(range_r(a, b, 2*i, lower, mid), range_r(a, b, 2*i+1, mid+1, upper));
    }

    struct iterator {
        T* ptr;
        iterator(T* p): ptr(p) {}
        iterator operator++() { ++ptr; return *this; }
        bool operator!=(const iterator& other) const { return ptr != other.ptr; }
        const T& operator*() const { return *ptr; }
    };
    iterator begin() { // don't call this directly, it's just for the foreach loop
        flush();
        return iterator(&tree[length]);
    }
    iterator end() { return iterator(&tree[length+true_size-1]+1); }

    inline int size() { return true_size; }

    // perform all updates so that tree[length .. 2*length-1] holds true data
    inline void flush() {
        for (int i = 0; i < 2*length; i++)
            propogate(i);
    }

    // gets value at index i
    inline T get(int i) { return get_r(i, 1, 0, length-1); }
    inline T operator[](int i) { return get(i); }

    // sets every element x in [a..b] to F(x, val)
    inline void update(int a, int b, T val) { update_r(a, b, val, 1, 0, length-1); }

    // sets every element in [a..b] to val
    inline void set(int a, int b, T val) { set_r(a, b, val, 1, 0, length-1); }

    // computes F over the range [a..b]
    inline T query(int a, int b) { return range_r(a, b, 1, 0, length-1); }
};

template<typename T, typename X, typename Y>
vector<int> compress(vector<T>& A, X comp, Y equiv) {

    vector<pair<T, int>> ordering(A.size());
    vector<int> out(A.size());
    for (int i = 0; i < A.size(); i++)
        ordering[i] = {A[i], i};

    sort(ordering.begin(), ordering.end(), [&](pair<T, int>& x, pair<T, int>& y){return comp(x.first, y.first);});

    int offset = 0;
    for (int i = 0; i < A.size(); i++) {
        if (i > 0 && equiv(ordering[i].first, ordering[i-1].first)) offset++;
        out[ordering[i].second] = i-offset;
    }
    return out;
}

// segtree<type, update_func, query_func, update_identity, query_identity>

auto _sum(pair<ll, int> x, pair<ll, int> y) {return make_pair(x.first+y.first, x.second+y.second);}
auto _max(pair<ll, int> x, pair<ll, int> y) {return max(x, y);}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n; fin >> n;
    vector<array<ll, 3>> a(n);
    for (ll i = 0; i < n; i++) {
        ll x, y, c; fin >> x >> y >> c;
        if (x > y) swap(x, y);
        a[i] = {x, y, c};
    }
    sort(all(a), [](array<ll, 3> x, array<ll, 3> y){return x[1] < y[1];});
    vector<int> c = compress(
        a,
        [](array<ll, 3> x, array<ll, 3> y){return x[0] < y[0];},
        [](array<ll, 3> x, array<ll, 3> y){return x[0] == y[0];}
    );
    int m = 0; for (auto& x : c) m = max(m, x+1);
    segtree<pair<ll, int>, _sum, _max> s(m);
    for (int i = 0; i < n; i++)
        s.set(c[i], c[i], {a[i][0], a[i][0]});
    debug(s);
    ll best = 0, u = 1000000001, v = 1000000001;
    int maxc = 0;
    for (int i = 0; i < n; i++) {
        ll dy = a[i][1] - (i == 0 ? 0 : a[i-1][1]);
        ll dy2 = (i == n-1 ? inf_ll : a[i+1][1]) - a[i][1];
        s.update(0, m-1, {-dy, 0});
        s.update(0, c[i], {a[i][2], 0});
        debug(a[i], c[i], s);
        maxc = max(maxc, c[i]);
        if (dy2 > 0) {
            auto p = s.query(0, maxc);
            if (p.first > best) {
                best = p.first;
                u = p.second;
                v = a[i][1];
            }
        }
    }
    cout << best << "\n";
    cout << u << " " << u << " " << v << " " << v << "\n";
}