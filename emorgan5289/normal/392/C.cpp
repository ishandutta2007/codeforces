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

template<ll M>
struct modint {

    static ll _reduce(ll n) {
        constexpr static ll b = -1ull/M;
        ll r = n-(ll)(__uint128_t(b)*n>>64)*M; return r >= M ? r-M : r;
    }

    static ll _pow(ll n, ll k) {
        ll r = 1;
        for (; k > 0; k >>= 1, n = _reduce(n*n))
            if (k&1) r = _reduce(r*n);
        return r;
    }

    ll v; modint(ll n = 0) : v(_reduce(n)) { v += (M&(0-(v<0))); }
    
    friend string to_string(const modint n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
    template<typename T> explicit operator T() { return T(v); }

    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }

    modint& operator+=(const modint n) { v += n.v; v -= (M&(0-(v>=M))); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&(0-(v<0))); return *this; }
    modint& operator*=(const modint n) { v = _reduce(v*n.v); return *this; }
    modint& operator/=(const modint n) { v = _reduce(v*_pow(n.v, M-2)); return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(int) { modint t = *this; return *this += 1, t; }
    modint operator--(int) { modint t = *this; return *this -= 1, t; }
    modint operator+() { return *this; }
    modint operator-() { return modint(0) -= *this; }

    // O(logk) modular exponentiation
    modint pow(const ll k) const {
        return k < 0 ? _pow(v, M-1-(-k%(M-1))) : _pow(v, k);
    }
    modint inv() const { return _pow(v, M-2); }
};

template<typename T, int H, int W>
struct matrix {

    T M[H][W];
    matrix(const T k = 0) { ident(k); }
    matrix(initializer_list<initializer_list<T>> v) : matrix() {
        for (int i = 0; i < v.size(); i++)
            copy(v.begin()[i].begin(), v.begin()[i].end(), M[i]);
    }

    T* operator[](const int i) { return M[i]; }
    const T* operator[](const int i) const { return M[i]; }

    void clear() { fill(&M[0][0], &M[0][0]+sizeof(M)/sizeof(T), 0); }
    void ident(const T k = 1) {
        clear(); for (int i = 0; i < min(H, W); i++) M[i][i] = k;
    }

    friend string to_string(const matrix& a) {
        string s = "";
        for (int i = 0; i < H; i++) {
            s += (i == 0 ? "[" : ", ");
            for (int j = 0; j < W; j++)
                s += (j == 0 ? "[" : ", ")+to_string(a.M[i][j]);
            s += "]";
        } return s+"]";
    }
    friend ostream& operator<<(ostream& o, const matrix<T, H, W>& a) {
        return o << to_string(a);
    }

    matrix& operator*=(const T& r) {
        for (int i = 0; i < H; i++) for (int j = 0; j < W; j++)
            M[i][j] *= r;
        return *this;
    }
    matrix& operator/=(const T& r) {
        for (int i = 0; i < H; i++) for (int j = 0; j < W; j++)
            M[i][j] /= r;
        return *this;
    }
    matrix operator*(const T& r) const { return matrix(*this) *= r; }
    matrix operator/(const T& r) const { return matrix(*this) /= r; }
    friend matrix operator*(const T& r, const matrix& a) {
        return matrix(a) *= r;
    }

    matrix& operator+=(const matrix& a) {
        for (int i = 0; i < H; i++) for (int j = 0; j < W; j++)
            M[i][j] += a.M[i][j];
        return *this;
    }
    template<int C> matrix<T, H, C> operator*(const matrix<T, W, C>& b) {
        matrix<T, H, C> r(0);
        for (int i = 0; i < H; i++) for (int j = 0; j < C; j++)
            for (int k = 0; k < W; k++) r.M[i][j] += M[i][k]*b.M[k][j];
        return r;
    }

    matrix& operator*=(const matrix& b) { return *this = *this*b; }
    matrix operator+(const matrix& b) { return matrix(*this) += b; }
    matrix operator-(const matrix& b) { return matrix(*this) += -b; }
    matrix operator+() { return matrix(*this); }
    matrix operator-() { return matrix(*this) *= -1; }

    matrix transpose() const {
        matrix r(0);
        for (int i = 0; i < H; i++) for (int j = 0; j < W; j++)
            r.M[i][j] = M[j][i];
        return r;
    }

    // O(n^3logk) matrix exponentiation
    matrix pow(long long k) {
        matrix a(1), r(*this);
        for (ll i = 1; i <= k; i <<= 1) {
            if (i&k) a *= r;
            r *= r;
        }
        return a;
    }

    // O(n^3) matrix determinant, uses operator/
    T det() const {
        matrix r(*this); T d = 1;
        for (int i = 0; i < H; i++) {
            if (r.M[i][i] == 0) for (int j = i+1; j < H; j++) if (r.M[j][i] != 0)
                { swap(r.M[i], r.M[j]); d = 0-d; break; }
            d *= r.M[i][i]; if (r.M[i][i] == 0) return 0;
            for (int j = i+1; j < H; j++) { T c = r.M[j][i]/r.M[i][i];
                for (int k = i; k < H; k++) r.M[j][k] -= r.M[i][k]*c;
        } } return d;
    }
    
    // O(n^3) matrix inversion, uses operator/, undefined behavior if det(*this) == 0
    matrix inv() const {
        matrix b(1), r(*this);
        for (int i = 0; i < H; i++) {
            if (r.M[i][i] == 0) for (int j = i+1; j < H; j++) if (r.M[j][i] != 0)
                { swap(b.M[i], b.M[j]), swap(r.M[i], r.M[j]); break; }
            for (int j = i+1; j < H; j++) { T c = r.M[j][i]/r.M[i][i];
                for (int k = 0; k < H; k++)
                    b.M[j][k] -= b.M[i][k]*c, r.M[j][k] -= r.M[i][k]*c;
        } }
        for (int i = H-1; i >= 0; i--) { T c = 1/r.M[i][i];
            for (int j = 0; j < H; j++) b.M[i][j] *= c, r.M[i][j] *= c;
            for (int j = 0; j < i; j++) { c = r.M[j][i];
                for (int k = 0; k < H; k++) b.M[j][k] -= b.M[i][k]*c;
        } } return b;
    }
};

const ll M = 1e9+7;
using mod = modint<M>;

// returns b^r mod m, runs in O(logr) time.
template<typename T>
T powmod(T b, T r, T m) {
    T out = 1;
    for (T t = 1; t <= r; t <<= 1) {
        if (r&t) out = (out*b)%m;
        b = (b*b)%m;
    }
    return out;
}

// returns a unique number b s.t. ab = 1 mod m in O(logm) time.
template<typename T>
T inv(T a, T m) {
    T r = 1;
    for (T k = m-2; k; k >>= 1) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
    }
    return r%m;
}

// returns (n choose k) in O(k) time.
template<typename T>
T choose(T n, T k) {
    if (k < 0 || k > n) return 0;
    T a = 1, b = 1, r = n;
    for (T d = 1; d <= min(k, n-k); d++, r--)
        a *= r, b *= d;
    return a/b;
}

// returns (n choose k) mod m in O(k+logm) time.
template<typename T>
T choosemod(T n, T k, T m) {
    if (k < 0 || k > n) return 0;
    T a = 1, b = 1, r = n;
    for (T d = 1; d <= min(k, n-k); d++, r--)
        a = (a*r)%m, b = (b*d)%m;
    return (a*inv(b, m))%m;
}

const ll K = 40;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin >> n >> k;
    matrix<mod, 2*K+3, 2*K+3> m;
    matrix<mod, 2*K+3, 1> x;

    // powers of i
    for (ll i = 0; i <= K; i++)
        for (ll j = 0; j <= i; j++)
            m[i][j] = m[i][K+1+j] = m[K+1+i][j] = choosemod(i, j, M);

    // answer
    m[2*K+2][2*K+2] = m[2*K+2][k] = 1;

    // initial state
    for (ll i = 0; i <= K; i++)
        x[i][0] = x[K+1+i][0] = 1;

    cout << (m.pow(n)*x)[2*K+2][0] << "\n";
}