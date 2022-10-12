#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

using v_t = int;
using vv_t = long long;
template<v_t MOD> struct modnum {
    v_t v;
    modnum() : v(0) {}
    modnum(vv_t _v) : v(_v % MOD) { if (v < 0) v += MOD; }
    explicit operator v_t() const { return v; }
    friend istream& operator >> (istream& i, modnum& n) { vv_t w; i >> w; n = modnum(w); return i; }
    friend ostream& operator << (ostream& o, const modnum& n) { return o << n.v; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        // x must be less than 2^32 * m so that x / m fits in a 32-bit integer.
        unsigned x_high = x >> 32, x_low = (unsigned) x, quot, rem;
        asm("divl %4\n"
                : "=a" (quot), "=d" (rem)
                : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    modnum& operator *= (const modnum& o) { v = fast_mod(vv_t(v) * o.v); return *this; }
    modnum operator - () { modnum res; if (v) res.v = MOD - v; return res; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }

    modnum pow(vv_t e) const {
        if (e < 0) return 1 / this->pow(-e);
        if (e == 0) return 1;
        if (e & 1) return *this * this->pow(e-1);
        return (*this * *this).pow(e/2);
    }

    modnum inv() const {
        v_t g = MOD, x = 0, y = 1;
        for (v_t r = v; r != 0; ) {
            v_t q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        assert(g == 1);
        assert(y == MOD || y == -MOD);
        return x < 0 ? x + MOD : x;
    }
    modnum& operator /= (const modnum& o) { return (*this) *= o.inv(); }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= modnum(b); }
};

using ll = modnum<998244353>;

// a  XXX 
// b XXXX
// c  XXXX
// d XXXXX

ll f[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

struct segtree {

    struct node {
        ll a, b, c, d;
        int l, r;
    };

    node combine(node x, node y) {
        node r;
        r.l = x.l, r.r = y.r;
        ll z = f[x.r*10+y.l];
        if (x.r == 0) z = 0;
        r.a = x.c*y.b + z*x.a*y.a;
        r.b = x.d*y.b + z*x.b*y.a;
        r.c = x.c*y.d + z*x.a*y.c;
        r.d = x.d*y.d + z*x.b*y.c;
        return r;
    }

    vector<int> a, b;
    vector<node> tree;
    int n;

    segtree(vector<int>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = {0, 1, 1, f[v[i-n]], v[i-n], v[i-n]};
                } else {
                    tree[i] = {1, 1, 1, 1};
                }
            } else {
                a[i] = a[2*i];
                b[i] = b[2*i+1];
                tree[i] = combine(tree[2*i], tree[2*i+1]);
            }
        }
    }

    void set(int i, int x) {
        tree[i+n] = {0, 1, 1, f[x], x, x};
        for (i = (i+n)/2; i > 0; i /= 2)
            tree[i] = combine(tree[2*i], tree[2*i+1]);
    }

    node query(int l, int r, int i = 1) {
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return {1, 1, 1, 1};
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    int k = 1<<int(ceil(log2(n)));
    vector<int> a(k);
    for (int i = 0; i < n; i++)
        a[i+k-n] = s[i]-'0';
    segtree q(a);
    while (m--) {
        int x, d; cin >> x >> d;
        q.set(x-1+k-n, d);
        s[x-1] = '0'+d;
        debug(s);
        cout << q.tree[1].d << "\n";
    }
}