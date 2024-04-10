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

using mod = modint<int(1e9+7)>;
const mod P1 = 65535, Pi1 = 1/P1;
const mod P2 = 69420, Pi2 = 1/P2;
const int N = 50005;
mod p1[N], pi1[N], h1[N];
mod p2[N], pi2[N], h2[N];
unordered_map<ll, int> m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    p1[0] = pi1[0] = 1;
    p2[0] = pi2[0] = 1;
    for (int i = 0; i < N-1; i++) {
        p1[i+1] = p1[i]*P1;
        pi1[i+1] = pi1[i]*Pi1;
        p2[i+1] = p2[i]*P2;
        pi2[i+1] = pi2[i]*Pi2;
    }
    int x = 1;
    while (2*x <= s.size()) {

        for (int i = 0; i < s.size(); i++) {
            h1[i+1] = h1[i]+s[i]*p1[i];
            h2[i+1] = h2[i]+s[i]*p2[i];
        }
        for (int i = 0; i < s.size()-x+1; i++) {
            h1[i] = (h1[i+x]-h1[i])*pi1[i];
            h2[i] = (h2[i+x]-h2[i])*pi2[i];
        }

        int r = inf;
        m.clear();
        for (int i = 0; i < s.size()-x+1; i++) {
            ll y = ll(h1[i].v)*inf + ll(h2[i].v);
            if (m.find(y) != m.end())
                cmin(r, i-m[y]);
            m[y] = i;
        }

        debug(x, r);
        if (r == inf) break;
        if (r != x) x = r;
        else {
            string t = "";
            for (int i = 0; i < s.size(); i++) {
                while (i+x < s.size()-x+1 && h1[i] == h1[i+x] && h2[i] == h2[i+x])
                    i += x;
                t += s[i];
            }
            s = t;
            x++;
        }
    }
    cout << s << "\n";
}