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

    ll v; modint(ll n = 0) : v(n%M) { v += (M&(0-(v<0))); }
    
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


using mod = modint<998244353>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n), f(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i], a[i]--;
            f[a[i]]++;
        }
        // debug(f);

        if (*max_element(all(f)) == n) {
            cout << "1\n";
            continue;
        }

        vector<mod> fact(2*n+1);
        fact[0] = 1;
        for (int i = 1; i <= 2*n; i++)
            fact[i] = fact[i-1]*i;

        int g = 0;
        for (int i = 0; i < n; i++)
            g = gcd(g, f[i]);
        vector<int> valid(n+1);
        for (int x = 1; x <= n; x++)
            valid[x] = n%x == 0 && g%(n/x) == 0;
        // debug(g, valid);

        // q[i] = number of permutations of a which have
        // a period which is a factor of i

        // qw[i] = sum of matches of permutations of a which have
        // a period which is a factor of i

        vector<mod> q(n+1), qw(n+1);

        for (int x = 1; x <= n; x++) {
            if (!valid[x]) continue;
            debug(x);
            int y = n/x;
            mod r = fact[x];
            mod s = 0;
            for (int i = 0; i < n; i++) {
                if (f[i] == 0) continue;
                int k = f[i]/y;
                r /= fact[k];
                if (k > 1)
                    s += (mod(k)/x) * (mod(k-1)/(x-1));
            }
            q[x] = r;
            qw[x] = s * n * r;
        }

        // p[i] = number of permutations of a which have
        // a period which is exactly i

        // pw[i] = sum of matches of permutations of a which have
        // a period which is exactly i

        vector<mod> p = q, pw = qw;
        for (int x = 1; x <= n; x++)
            for (int y = 2*x; y <= n; y += x) {
                if (valid[x] && valid[y])
                    p[y] -= p[x], pw[y] -= pw[x];
            }

        // debug(q);
        // debug(p);

        // debug(qw);
        // debug(pw);

        // ans = number of permutations, up to cyclic duplicates
        // answ = sum of matches of permutations, up to cyclic duplicates

        mod ans = 0, answ = 0;
        for (int x = 1; x <= n; x++) {
            ans += p[x]/x;
            answ += pw[x]/x;
        }

        // debug(ans);
        // debug(answ);

        cout << n-(answ/ans) << "\n";
    }
}