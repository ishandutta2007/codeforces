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

using mod = modint<int(1e9+7)>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<int> f(n+1);
        vector<int> p(n), v(n);
        for (int i = 0; i < n; i++)
            cin >> p[i], p[i]--;
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                int c = 0;
                for (int j = i; !v[j]; j = p[j])
                    v[j] = 1, c++;
                f[c]++;
            }
        }

        debug(f);

        // vector<int> q = {1, 1, 3, 5, 5, 5};
        // n = 0;
        // for (int y : q) n += y;
        // f.assign(n+1, 0);
        // for (int y : q) f[y]++;

        if (n%3 == 0) {
            int ans = 0, c = 0;
            int c1 = 0, c2 = 0;
            for (int i = n; i >= 1; i--) {
                if (i%3 != 0) {
                    c += i*f[i], ans += f[i];
                    if (i%3 == 1) c1 += f[i];
                    if (i%3 == 2) c2 += f[i];
                }
                else ans += (i/3-1)*f[i];
            }
            debug(c1, c2);
            if (c1 == c2) {
                ans -= 2*max(0, c1-1);
            } else {
                ans -= 2*max(0, min(c1, c2));
                ans -= 2*max(abs(c1-c2)/3-1, 0);
            }
            debug(f, ans, c);
            cout << mod(3).pow(n/3) << " " << ans+(c == 0 ? 0 : c/3-2) << "\n";
        }
        if (n%3 == 1) {

            auto f1 = f;

            int ans = 0, c = 0;
            bool has_4 = 0;
            for (int i = 1; i <= n; i++)
                if (i >= 4 && i%3 == 1 && f[i] > 0 && !has_4) {
                    has_4 = 1, f[i]--, f[i-4]++;
                    if (i != 4) ans++;
                }
            for (int i = 3; i <= n; i++)
                if (f[i] > 0 && f[1] > 0 && !has_4) {
                    f[i]--, f[i-3]++, f[1]--, has_4 = 1;
                    ans++;
                    if (i != 3) ans++;
                }
            for (int i = n; i >= 1; i--)
                if (i >= 4 && i%3 == 2 && f[i] > 0 && !has_4)
                    has_4 = 1, f[i]--, f[i-4]++, ans++;
            if (!has_4) ans = inf;
            int c1 = 0, c2 = 0;
            for (int i = n; i >= 1; i--) {
                if (i%3 != 0) {
                    c += i*f[i], ans += f[i];
                    if (i%3 == 1) c1 += f[i];
                    if (i%3 == 2) c2 += f[i];
                }
                else ans += (i/3-1)*f[i];
            }
            debug(c1, c2);
            if (c1 == c2) {
                ans -= 2*max(0, c1-1);
            } else {
                ans -= 2*max(0, min(c1, c2));
                ans -= 2*max(abs(c1-c2)/3-1, 0);
            }
            debug(f, ans, c, has_4);
            int tmp = ans+(c == 0 ? 0 : c/3-2);
            debug(tmp);

            f = f1;
            ans = 0, c = 0;
            int count_2 = 0;

            for (int i = 1; i <= n; i++)
                while (i >= 2 && i%3 == 2 && f[i] > 0 && count_2 < 2) {
                    count_2++, f[i]--, f[i-2]++;
                    if (i != 2) ans++;
                }
            while (count_2 < 2 && f[1] > 1)
                f[1] -= 2, ans++, count_2++;
            for (int i = n; i >= 1; i--)
                while (i >= 2 && i%3 == 1 && f[i] > 0 && count_2 < 2)
                    count_2++, f[i]--, f[i-2]++, ans++;
            if (count_2 < 2) ans = inf;
            c1 = 0, c2 = 0;
            for (int i = n; i >= 1; i--) {
                if (i%3 != 0) {
                    c += i*f[i], ans += f[i];
                    if (i%3 == 1) c1 += f[i];
                    if (i%3 == 2) c2 += f[i];
                }
                else ans += (i/3-1)*f[i];
            }
            debug(f, ans, c, count_2);
            if (c1 == c2) {
                ans -= 2*max(0, c1-1);
            } else {
                ans -= 2*max(0, min(c1, c2));
                ans -= 2*max(abs(c1-c2)/3-1, 0);
            }

            cout << mod(3).pow((n-4)/3)*4 << " " << min(tmp, ans+(c == 0 ? 0 : c/3-2)) << "\n";
        }
        if (n%3 == 2) {
            int ans = 0, c = 0;
            bool has_2 = 0;
            for (int i = 1; i <= n; i++)
                if (i >= 2 && i%3 == 2 && f[i] > 0 && !has_2) {
                    has_2 = 1, f[i]--, f[i-2]++;
                    if (i != 2) ans++;
                }
            if (!has_2 && f[1] > 1)
                f[1] -= 2, ans++, has_2 = 1;
            for (int i = n; i >= 1; i--)
                if (i >= 2 && i%3 == 1 && f[i] > 0 && !has_2)
                    has_2 = 1, f[i]--, f[i-2]++, ans++;
            int c1 = 0, c2 = 0;
            for (int i = n; i >= 1; i--) {
                if (i%3 != 0) {
                    c += i*f[i], ans += f[i];
                    if (i%3 == 1) c1 += f[i];
                    if (i%3 == 2) c2 += f[i];
                }
                else ans += (i/3-1)*f[i];
            }
            if (c1 == c2) {
                ans -= 2*max(0, c1-1);
            } else {
                ans -= 2*max(0, min(c1, c2));
                ans -= 2*max(abs(c1-c2)/3-1, 0);
            }
            debug(f, ans, c, has_2);
            cout << mod(3).pow((n-2)/3)*2 << " " << ans+(c == 0 ? 0 : c/3-2) << "\n";
        }
    }
}