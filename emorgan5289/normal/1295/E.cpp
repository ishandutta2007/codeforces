#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long

#define all(x) (x).begin(), (x).end()

// these to_string headers are taken from tourist on codeforces

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}
 
string to_string(bool b) {
    return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
 
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("input.in");
#endif

template<typename T, T update_func(T, T), T query_func(T, T), T update_identity, T query_identity>
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
            tree[i] = update_func(tree[i], val);
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

ll _sum(ll a, ll b) {return a+b;}
ll _min(ll a, ll b) {return min(a, b);}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; fin >> n;
    vector<ll> p(n), a(n);
    for (auto& x : p) fin >> x;
    for (auto& x : a) fin >> x;
    segtree<ll, _sum, _min, 0, inf> S(n+1);
    S.set(0, n, 0);
    S.update(0, p[0]-1, a[0]);
    for (int i = 1; i < n; i++)
        S.update(p[i], n, a[i]);
    ll out = S.query(0, n);
    debug(S);
    for (int i = 1; i < n-1; i++) {
        S.update(p[i], n, -a[i]);
        S.update(0, p[i]-1, a[i]);
        out = min(out, S.query(0, n));
        debug(S, S.query(0, n));
    }
    cout << out << "\n";
}