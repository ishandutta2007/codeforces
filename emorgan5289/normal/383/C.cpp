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
#else
#include "../../debug.cpp"
#endif

template<typename T, T update_func(T, T), T query_func(T, T), T update_identity, T query_identity>
struct segtree {

    int length, true_size;
    vector<T> tree, updates;
    vector<bool> insertflag;

    segtree(int s) {
        true_size = s;
        length = pow(2, ceil(log2(s)));
        tree.assign(2*length, query_identity);
        updates.assign(2*length, update_identity);
        insertflag.assign(2*length, 0);
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
                for (int m = length; m > i; m /= 2)
                 val = query_func(val, val);
            }
            tree[i] = val;
            insertflag[i] = 0;
        } else {
            if (i < length) {
                updates[2*i] = update_func(updates[2*i], val);
                updates[2*i+1] = update_func(updates[2*i+1], val);
                for (int m = length; m > i; m /= 2)
                 val = query_func(val, val);
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

ll _sum(ll a, ll b) {
    return a+b;
}

const int maxn = 200005;
int vin[maxn], vout[maxn], dep[maxn];
vector<int> adj[maxn];
int t = 0;

void dfs(int i, int p) {
    vin[i] = t++;
    dep[i] = dep[p]+1;
    for (auto& j : adj[i])
        if (j != p)
            dfs(j, i);
    vout[i] = t-1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> a(n); for (auto& x : a) cin >> x;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    dep[0] = 0;
    dfs(0, 0);
    segtree<ll, _sum, _sum, 0ll, 0ll> s(n);
    for (int i = 0; i < n; i++)
        s.set(vin[i], vin[i], a[i]*(dep[i]&1 ? -1 : 1));
    while (m--) {
        int b; cin >> b;
        if (b == 1) {
            int u, x; cin >> u >> x; u--;
            s.update(vin[u], vout[u], x*(dep[u]&1 ? -1 : 1));
        } else {
            int u; cin >> u; u--;
            cout << s.get(vin[u])*(dep[u]&1 ? -1 : 1) << "\n";
        }
    }
}