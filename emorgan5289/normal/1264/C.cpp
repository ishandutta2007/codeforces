#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

#define MOD 998244353

struct rational {
    ull p, q; // numerator, denominator

    rational() {
        p = 0; q = 1;
    }

    rational(ull n, ull d) {
        p = n; q = d;
    }

    rational(int n) {
        p = n; q = 1;
    }

    void reduce() {
        int g = __gcd(p, q);
        p /= g; q /= g;
    }

    // returns a unique integer x such that xq = p (mod MOD)
    ull mod() {
        ull r = 1, t = q, k = MOD-2;
        while (k) {
            if (k&1) r = (r*t)%MOD;
            t = (t*t)%MOD;
            k >>= 1;
        }
        return (p*r)%MOD;
    }

    template<typename T>
    operator T() { return T(p)/q; }
};

// to string

string to_string(rational r) {
    r.reduce();
    return to_string(r.p)+(r.q == 1 ? "" : "/"+to_string(r.q));
}

ostream& operator<<(ostream& out, rational r) {
    out << to_string(r);
    return out;
}

inline bool operator==(const rational a, const rational b) {
    return a.p == b.p && a.q == b.q;
}

// arithmetic

inline rational operator+(const rational a, const rational b) {
    ull an = (a.p*b.q)%MOD, bn = (b.p*a.q)%MOD;
    return rational((an+bn)%MOD, (a.q*b.q)%MOD);
}

inline rational operator-(const rational a, const rational b) {
    ull an = (a.p*b.q)%MOD, bn = (b.p*a.q)%MOD;
    return rational((an-bn+MOD)%MOD, (a.q*b.q)%MOD);
}

inline rational operator*(const rational a, const rational b) {
    return rational((a.p*b.p)%MOD, (a.q*b.q)%MOD);
}

inline rational operator/(const rational a, const rational b) {
    return rational((a.p*b.q)%MOD, (a.q*b.p)%MOD);
}

template<typename T>
inline rational operator+(const rational a, const T b) { return a+rational(b); };
template<typename T>
inline rational operator+(const T a, const rational b) { return rational(a)+b; };
template<typename T>
inline rational operator-(const rational a, const T b) { return a-rational(b); };
template<typename T>
inline rational operator-(const T a, const rational b) { return rational(a)-b; };
template<typename T>
inline rational operator*(const rational a, const T b) { return a*rational(b); };
template<typename T>
inline rational operator*(const T a, const rational b) { return rational(a)*b; };
template<typename T>
inline rational operator/(const rational a, const T b) { return a/rational(b); };
template<typename T>
inline rational operator/(const T a, const rational b) { return rational(a)/b; };

template<typename T, T F(T, T)>
struct rafq {

    int length;
    vector<vector<T>> subs;

    void _fill_subs(int a, int b, int h) {
        int m = (a+b) >> 1;

        if (m < length) {
            T r = subs[h][m] = subs[0][m];
            for (int i = m-1; i >= a; i--)
                subs[h][i] = F(subs[0][i], subs[h][i+1]);
        }
        if (m+1 < length) {
            T r = subs[h][m+1] = subs[0][m+1];
            for (int i = m+2; i <= min(b, length-1); i++)
                subs[h][i] = F(subs[h][i-1], subs[0][i]);
        }

        if (h > 1) {
            _fill_subs(a, m, h-1);
            _fill_subs(m+1, b, h-1);
        }
    }

    rafq(vector<T>& data) {
        length = data.size();
        int exp = 32-__builtin_clz(length-1);
        subs = vector<vector<T>>(exp, vector<T>(length));

        for (int i = 0; i < length; i++)
            subs[0][i] = data[i];
        _fill_subs(0, (1<<exp)-1, exp-1);
    }

    // function over the range [a..b]
    inline T query(int a, int b) {

        if (a == b) return subs[0][a];

        // compute index into subs in (basically) O(1) time...
        int s = 31-__builtin_clz(b-a);
        int as = (a >> s) + 1, bs = b >> s;
        int h = __builtin_ctz(max(as & -as, bs & -bs)) + s;

        return F(subs[h][a], subs[h][b]);
    }
};

rational _prod(rational a, rational b) { return a*b; }

struct line { rational m, c; };
line _comp(line a, line b) { return {a.m*b.m, a.c+a.m*b.c}; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, q; fin >> n >> q;
    vector<rational> p(n);
    vector<line> r(n);
    for (int i = 0; i < n; i++) {
        int x; fin >> x;
        p[i] = rational(100, x);
        r[i] = {rational(x, 100), 1};
    }
    rafq<line, _comp> y(r);
    rafq<rational, _prod> z(p);
    set<int> s; s.insert(0); s.insert(n);
    rational ans = y.query(0, n-1).c*z.query(0, n-1);

    for (int i = 0; i < q; i++) {
        int x; fin >> x; x--;
        if (s.count(x)) {
            int a = *--s.find(x);
            int b = *++s.find(x);
            // debug(a, x, b);
            ans = ans - y.query(a, x-1).c*z.query(a, x-1);
            ans = ans - y.query(x, b-1).c*z.query(x, b-1);
            ans = ans + y.query(a, b-1).c*z.query(a, b-1);
            s.erase(s.find(x));
        } else {
            s.insert(x);
            int a = *--s.find(x);
            int b = *++s.find(x);
            // debug(a, x, b);
            ans = ans + y.query(a, x-1).c*z.query(a, x-1);
            ans = ans + y.query(x, b-1).c*z.query(x, b-1);
            ans = ans - y.query(a, b-1).c*z.query(a, b-1);
        }
        cout << ans.mod() << "\n";
    }
}