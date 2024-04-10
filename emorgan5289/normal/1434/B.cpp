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

const int N = 1e5+5;
int _sum(int a, int b) {return a+b;}
segtree<int, _sum, 0> s(N);
int q[2*N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < 2*n; i++) {
        char c; cin >> c;
        if (c == '+') s.update(1, 1, 1), q[i] = 0;
        if (c == '-') {
            int x; cin >> x; q[i] = x;
            int r = s.query(0, x);
            debug(x, r);
            if (r == 0) cout << "NO\n", exit(0);
            s.set(0, x, 0);
            s.update(x, x, r-1);
        }
    }
    cout << "YES\n";
    vector<int> ans, a;
    for (int i = 2*n-1; i >= 0; i--) {
        if (q[i] == 0) ans.pb(a.back()), a.pop_back();
        else a.pb(q[i]);
    }
    reverse(all(ans));
    for (auto& x : ans) cout << x << " ";
}