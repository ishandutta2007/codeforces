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

using mod = modint<998244353>;
const ll N = 1000;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll k, A, h; cin >> k >> A >> h;
    ll n = 1<<(k-1);
    vector<unordered_map<int, vector<int>>> val(n);
    vector<mod> Ap(N);
    Ap[0] = 1;
    for (int i = 1; i < N; i++)
        Ap[i] = Ap[i-1]*A;
    vector<int> tmpp;
    for (int mask = 0; mask < 1<<n; mask++) {
        vector<int> p(n, 1);
        int j = 0;
        for (int l = 1; l < k; l++)
            for (int i = 0; i < n; i += 1<<l) {
                if (mask&(1<<j)) {
                    (*max_element(p.begin()+i, p.begin()+i+(1<<(l-1))))++;
                } else {
                    (*max_element(p.begin()+i+(1<<(l-1)), p.begin()+i+(1<<(l))))++;
                }
                j++;
            }
        for (int i = 0; i < n; i++)
            p[i] = (1<<(k-p[i]))+1;
        int x = min_element(all(p))-p.begin();
        mod ph = 0;
        for (int i = 0; i < n; i++)
            ph += (i+1)*Ap[p[i]];
        val[x][int(ph)] = p;
        tmpp = p;
        // debug(p, x, ph);
    }
    mod off = 0;
    for (auto& x : tmpp)
        off += Ap[x]*n;
    // debug(off);
    // debug(val);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            mod ri = h - (off + (Ap[1]-Ap[2])*(i+1));
            mod rj = h - (off + (Ap[1]-Ap[2])*(n+j+1));
            // x + y == ri;
            for (auto& [x, p1] : val[i]) {
                if (val[j].find(int(ri-x)) != val[j].end()) {
                    debug(p1, val[j][int(ri-x)]);
                    debug(x, ri-x, off);
                    for (int l = 0; l < n; l++)
                        cout << (p1[l] == 2 ? 1 : p1[l]) << " ";
                    for (int l = 0; l < n; l++)
                        cout << val[j][int(ri-x)][l] << " ";
                    cout << "\n";
                    exit(0);
                }
                if (val[j].find(int(rj-x)) != val[j].end()) {
                    debug(j, rj-x, p1, val[j][int(rj-x)]);
                    for (int l = 0; l < n; l++)
                        cout << p1[l] << " ";
                    for (int l = 0; l < n; l++)
                        cout << (val[j][int(rj-x)][l] == 2 ? 1 : val[j][int(rj-x)][l]) << " ";
                    cout << "\n";
                    exit(0);
                }
            }
        }
    cout << "-1\n";
}