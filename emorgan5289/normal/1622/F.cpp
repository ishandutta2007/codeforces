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

    static ll _pow(ll n, ll k) {
        ll r = 1;
        for (; k > 0; k >>= 1, n = (n*n)%M)
            if (k&1) r = (r*n)%M;
        return r;
    }

    ll v; modint(ll _n = 0) : v(_n%M) { v += (M&(0-(v<0))); }
    
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
    modint& operator*=(const modint n) { v = (v*n.v)%M; return *this; }
    modint& operator/=(const modint n) { v = (v*_pow(n.v, M-2))%M; return *this; }
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

using mod = modint<int(998244353)>;
const int P = 65535;

const int N = 1e6+5;
int d[N], n;
bitset<N> w;

map<int, bitset<N>> factorial_cache;

auto factors(int x) {
    vector<int> r;
    while (x != 1)
        r.pb(d[x]), x /= d[x];
    return r;
}

void debug_w(string t) {
    string s(N, ' ');
    for (int j = 1; j < N; j++)
        if (w[j]) s[j-1] = '.';
    while (!s.empty() && s.back() == ' ') s.pop_back();
    cout << s << " " << t << "\n";
}

bitset<N> factorial(int x) {
    if (factorial_cache.count(x)) return factorial_cache[x];
    bitset<N> r;
    for (int i = 2; i <= x; i++)
        for (int j : factors(i))
            r[j] = !r[j];
    return factorial_cache[x] = r;
}

mod polynomial_hash(bitset<N> x) {
    mod r = 0, p = P;
    for (int i = 0; i < N; i++) {
        if (x[i]) r += p;
        p *= P;
    }
    return r;
}

unordered_map<int, int> m;

// bool any_ans = 0;
// vector<int> stk, ans;

// void dfs(int k) {
//     if ((any_ans && stk.size() >= ans.size()) || stk.size() > k)
//         return;
//     int x = N-1;
//     while (x > 0 && !w[x]) x--;
//     debug(stk, x);
//     // debug_w();
//     if (x == 0) {
//         if (!any_ans || ans.size() > stk.size()) ans = stk;
//         any_ans = 1;
//         return;
//     }
//     vector<int> c;
//     for (int y = x; (y == x || d[y] != y) && y <= n; y++)
//         c.pb(y);

//     for (auto& y : c) {
//         stk.pb(y);
//         w ^= factorial(y);
//         dfs(k);
//         w ^= factorial(y);
//         stk.pop_back();
//     }
// }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    debug(0);
    for (int i = N-1; i >= 2; i--)
        for (int j = i; j < N; j += i)
            d[j] = i;
    vector<mod> p(N+1);
    p[0] = P;
    for (int i = 1; i <= N; i++)
        p[i] = p[i-1]*P;
    mod h = 0;
    for (int i = 1; i <= n; i++) {
        for (int j : factors(i)) {
            if (w[j]) h -= p[j];
            else h += p[j];
            w[j] = !w[j];
        }
        // debug(h, i);
        m[int(h)] = i;
    }

    debug(1);

    w = factorial(1);
    for (int i = n; i > 1; i -= 2)
        for (int x : factors(i))
            w[x] = !w[x];
    // debug_w("original");

    set<int> s;
    if (n == 3) s = {3};
    else if (n < 4) s = {};
    else if (n%4 == 0) s = {n/2};
    else if (n%4 == 2 && factorial(n/2+1) == w) s = {n/2+1};
    else if (n%4 == 2) s = {n/2, 2};

    else if (n%4 == 1) {
        s = {n, n/2};
        vector<int> c;
        for (int x = n; x == n || d[x+1] != x+1; x--)
            c.pb(x);
        reverse(all(c));
        auto v = factorial(c[0]);
        for (int x : c) {
            if (x != c[0]) {
                for (int j : factors(x)) {
                    v[j] = !v[j];
                }
            }
            debug(x);
            if (w == v)
                s = {x};
        }
    }

    else if (n%4 == 3) {
        debug(2);
        s = {n, n/2, 2};
        vector<int> c;
        for (int x = n; x == n || d[x+1] != x+1; x--)
            c.pb(x);
        reverse(all(c));
        auto v = factorial(c[0])^w;
        auto h2 = polynomial_hash(v);
        for (int x : c) {
            if (x != c[0]) {
                for (int j : factors(x)) {
                    if (v[j]) h2 -= p[j];
                    else h2 += p[j];
                    v[j] = !v[j];
                }
            }
            debug(x, h2);
            if (m.count(int(h2)) && s.size() > 2)
                s = {m[int(h2)], x};
            if (w == v)
                s = {x};
        }
    }

    cout << n-s.size() << "\n";
#ifndef LOCAL
    for (int i = 1; i <= n; i++)
        if (!s.count(i)) cout << i << " ";
    cout << "\n";
#endif
}