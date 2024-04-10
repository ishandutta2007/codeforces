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

template<typename T, T F(T, T), T identity>
struct segtree {

    int length;
    vector<T> tree, updates;
    vector<bool> insertflag;

    segtree(int s) {
        length = pow(2, ceil(log2(s)));
        tree.assign(2*length, identity);
        updates.assign(2*length, identity);
        insertflag.assign(2*length, 0);
    }

    segtree(vector<T>& v) : segtree(v.size()) {
        for (int i = 0; i < v.size(); i++)
            tree[length+i] = v[i];
        for (int i = length-1; i > 0; i--)
            tree[i] = F(tree[2*i], tree[2*i+1]);
    }

    inline void propogate(int i) {
        T val = updates[i];
        if (insertflag[i]) {
            if (i < length) {
                updates[2*i] = val;
                updates[2*i+1] = val;
                insertflag[2*i] = insertflag[2*i+1] = 1;
                // generalized multiplication in logn time
                for (int m = length; m > i; m /= 2)
                    val = F(val, val);
            }
            tree[i] = val;
            insertflag[i] = 0;
        } else {
            if (i < length) {
                updates[2*i] = F(updates[2*i], val);
                updates[2*i+1] = F(updates[2*i+1], val);
                // generalized multiplication in logn time
                for (int m = length; m > i; m /= 2)
                    val = F(val, val);
            }
            tree[i] = F(tree[i], val);
        }
        updates[i] = identity;
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
            updates[i] = F(updates[i], val);
        propogate(i);
        if (b < lower || a > upper || (a <= lower && b >= upper)) 
            return;
        int mid = (lower+upper)/2;
        update_r(a, b, val, 2*i, lower, mid);
        update_r(a, b, val, 2*i+1, mid+1, upper);
        tree[i] = F(tree[2*i], tree[2*i+1]);
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
        tree[i] = F(tree[2*i], tree[2*i+1]);
    }

    T range_r(int a, int b, int i, int lower, int upper) {
        propogate(i);
        if (b < lower || a > upper)
            return identity;
        if (a <= lower && b >= upper)
            return tree[i];
        int mid = (lower+upper)/2;
        return F(range_r(a, b, 2*i, lower, mid), range_r(a, b, 2*i+1, mid+1, upper));
    }

    // gets value at index i
    inline T get(int i) {
        return get_r(i, 1, 0, length-1);
    }

    // sets every element x in [a..b] to F(x, val)
    inline void update(int a, int b, T val) {
        update_r(a, b, val, 1, 0, length-1);
    }

    // sets every element in [a..b] to val
    inline void set(int a, int b, T val) {
        set_r(a, b, val, 1, 0, length-1);
    }

    // computes F over the range [a..b]
    inline T query(int a, int b) {
        return range_r(a, b, 1, 0, length-1);
    }
};

ll sum(ll a, ll b) {return a+b;}

const int maxn = 100005;
fenwick_multiset<maxn> f;
segtree<ll, sum, 0> s(maxn);

void split(int i) {
    if (f.count(i) == 0)
        f.insert(i, f.count(f.get(f.index(i)-1)));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        f.insert(i, i+1);
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            ll l, r, x; cin >> l >> r >> x; l--, r--;
            split(l); split(r+1);
            ll i = f.get(f.index(l));
            while (i <= r) {
                ll j = min(n, f.get(f.index(i+1)));
                ll k = f.count(i);
                f.remove(i, k);
                s.update(i, j-1, abs(x-k));
                i = f.get(f.index(l));
            }
            f.insert(l, x);
        } else {
            ll l, r; cin >> l >> r; l--, r--;
            cout << s.query(l, r) << "\n";
        }
    }
}