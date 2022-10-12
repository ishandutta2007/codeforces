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

template<ll M>
struct modint {

    static ll reduce(ll n) {
        constexpr static ll b = -1ull/M;
        ll r = n-(ll)(__uint128_t(b)*n>>64)*M; return r >= M ? r-M : r;
    }

    static ll inv(ll n) {
        ll r = 1;
        for (ll k = M-2; k > 0; k >>= 1, n = reduce(n*n))
            if (k&1) r = reduce(r*n);
        return r;
    }

    ll v; modint(ll n = 0) : v(reduce(n)) { v += (M&0-(v<0)); }
    
    friend string to_string(const modint& n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint& n) { return o << n.v; }

    modint& operator+=(const modint n) { v += n.v; v -= (M&0-(v>=M)); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&0-(v<0)); return *this; }
    modint& operator*=(const modint n) { v = reduce(v*n.v); return *this; }
    modint& operator/=(const modint n) { v = reduce(v*inv(n.v)); return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }

    // O(logk) modular exponentiation
    modint exp(const ll k) const {
        if (k < 1) return k == 0 ? 1 : modint(inv(this->v)).exp(-k);
        return k&1 ? *this*(this->exp(k-1)) : (*this**this).exp(k>>1);
    }
};

template<unsigned long long M>
struct poly : vector<modint<M>> {

    using T = modint<M>; using v = vector<T>;
    using v::vector;

    // access the coefficient of x^i
    T& operator[](const size_t i) {
        if (v::size() <= i) v::resize(i+1);
        return v::operator[](i);
    }

    // evaluate the polynomial at x
    T operator()(const T x) const {
        T y(1), r(0);
        for (const T& a : *this) r += a*y, y *= x;
        return r;
    }

    poly substr(int l, int r) const {
        poly p(max(0, r-l), 0);
        int l1 = max(0, min(int(v::size()), l));
        int r1 = min(int(v::size()), max(l, r));
        copy(v::begin()+l1, v::begin()+r1, p.begin()+max(0, -l));
        return p;
    }

    poly& operator+=(const poly& p) {
        if (v::size() < p.size()) v::resize(p.size());
        auto it = v::begin(); for (const T& a : p) *(it++) += a;
        return *this;
    }
    poly& operator-=(const poly& p) { return *this += -p; }
    poly& operator*=(const T& x) { for (T& a : *this) a *= x; return *this; }
    poly& operator/=(const T& x) { *this *= 1/x; return *this; }
    poly operator+(const poly& p) const { return poly(*this) += p; }
    poly operator-(const poly& p) const { return poly(*this) -= p; }
    poly operator+() const { return poly(*this); }
    poly operator-() const { return poly(*this) *= -1; }
    poly operator*(const T& x) const { return poly(*this) *= x; }
    friend poly operator*(const T& x, const poly& p) { return p*x; }
    poly operator/(const T& x) const { return poly(*this) /= x; }

    // memoized roots of unity, source: Um_nik
    static array<vector<T>, 2>& compute_roots(int k = 21) {
        static array<vector<T>, 2> r;
        if (r[0].size() >= 1<<k) return r;
        T p = 2; while (p.exp(M>>1).v == 1) p += 1;
        r[0].resize(1<<k, 1), r[1].resize(1<<k, 1);
        for (int w = 0; w < k; w++) {
            int x = (1<<w)-1, t = (M-1)>>w;
            T g = p.exp(t), ig = p.exp(M-1-t);
            for (int i = 0; i < x; i++) {
                r[0][x+i+1] = g*r[0][x+i];
                r[1][x+i+1] = ig*r[1][x+i];
            }
        } return r;
    }

    // number theoretic transform in place, runs in O(nlogn), source: Um_nik
    void ntt(bool inv = 0) {
        int n = v::size(); if (n == 1) return;
        auto& r = compute_roots()[inv];
        auto f = v::data();
        if (inv) {
            for (int i = 1; i < n; i <<= 1)
                for (int j = 0; j < n; j += i*2)
                    for (int k = 0; k < i; k++) {
                        f[i+j+k] *= r[i*2-1+k];
                        const T tmp = f[j+k]-f[i+j+k];
                        f[j+k] += f[i+j+k]; f[i+j+k] = tmp;
                    }
            const T ni = 1/T(n); for (int i = 0; i < n; i++) f[i] *= ni;
        } else
            for (int i = n>>1; i > 0; i >>= 1)
                for (int j = 0; j < n; j += i*2)
                    for (int k = 0; k < i; k++) {
                        const T tmp = f[j+k]-f[i+j+k];
                        f[j+k] += f[i+j+k]; f[i+j+k] = tmp*r[i*2-1+k];
                    }
    }

    poly& operator*=(poly p) {
        int m = v::size()+p.size()-1; int n = 1<<(32-__builtin_clz(m-1));
        v::resize(n), p.resize(n); ntt(), p.ntt();
        auto it = v::begin(); for (const T& a : p) *(it++) *= a;
        ntt(1), v::resize(m); return *this;
    }
    poly operator*(const poly& p) const { return poly(*this) *= p; }

    // inverse polynomial mod x^n, UB if 0 is a root
    poly inv(size_t n) const {
        poly p = {1/v::data()[0]};
        for (size_t i = 1; i < n; i <<= 1)
            p -= (p*(p*substr(0, 2*i)).substr(i, 2*i)).substr(-i, i);
        p.resize(n); return p;
    }

    // square root polynomial mod x^n
    poly sqrt(size_t n) const {
        poly p = {1};
        for (size_t i = 1; i < n; i <<= 1)
            p = (p.substr(0, 2*i)+*this*p.inv(n))/2;
        p.resize(n); return p;
    }

    // exponentiation to the k power mod x^n
    poly exp(size_t n, size_t k) const {
        if (k < 0) return inv(n).exp(n, -k);
        if (k < 2) return k == 0 ? poly({1}) : poly(*this);
        if (k&1) return (*this*(this->exp(n, k-1))).substr(0, n);
        return (*this**this).substr(0, n).exp(n, k>>1);
    }
};

const ll N = 1e5+5;
poly<998244353> f, I = {1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    while (n--) {
        int c; cin >> c; f[c] = 1;
    }
    for (auto& x : ((I+(I-4*f).sqrt(m+1)).inv(m+1)*2).substr(1, m+1))
        cout << x << "\n";
}