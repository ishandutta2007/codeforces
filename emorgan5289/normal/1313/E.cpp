#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

vector<ll> z_function(string s) {
    ll n = (ll) s.length();
    vector<ll> z(n);
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

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

ll _sum(ll x, ll y) {return x+y;}
segtree<ll, _sum, 0ll> f(2e6);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    string a, b, s; cin >> a >> b >> s;
    auto z1 = z_function(s+'$'+a);
    z1.erase(z1.begin(), z1.begin()+m+1);
    reverse(all(b)), reverse(all(s));
    auto z2 = z_function(s+'$'+b);
    z2.erase(z2.begin(), z2.begin()+m+1);
    reverse(all(z2));
    ll out = 0;
    for (int i = 0; i < min(n, m-2); i++)
        f.update(1, z2[i], 1);
    for (int i = 0; i < n; i++) {
        if (i+m-2 < n) f.update(1, z2[i+m-2], 1);
        if (i-1 >= 0) f.update(1, z2[i-1], -1);
        out += f.query(max(1ll, m-z1[i]), m-1);
        // for (int j = 0; j < n; j++)
        //     debug(f.get(j));
        // debug(i, out);
    }
    cout << out << "\n";
}