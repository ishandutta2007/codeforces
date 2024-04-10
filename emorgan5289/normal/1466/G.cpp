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
    
    friend string to_string(const modint n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
    template<typename T> explicit operator T() { return T(v); }

    modint& operator+=(const modint n) { v += n.v; v -= (M&0-(v>=M)); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&0-(v<0)); return *this; }
    modint& operator*=(const modint n) { v = reduce(v*n.v); return *this; }
    modint& operator/=(const modint n) { v = reduce(v*inv(n.v)); return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(int) { modint t = *this; return *this += 1, t; }
    modint operator--(int) { modint t = *this; return *this -= 1, t; }

    // O(logk) modular exponentiation
    modint pow(const ll k) const {
        if (k < 1) return k == 0 ? modint(1) : modint(inv(this->v)).pow(-k);
        return k&1 ? *this*(this->pow(k-1)) : (*this**this).pow(k>>1);
    }
};

// Knuth-Morris-Pratt algorithm. Returns a list of all indices at which W appears in S.
// Runs in O(|S|+|W|) time.
template<typename it>
vector<int> kmp(it S_first, it S_last, it W_first, it W_last) {
    int n = S_last-S_first, m = W_last-W_first;
    vector<int> out, ptr(m+1);
    ptr[0] = -1;
    for (int i = 1, j = 0; i < m; i++, j++) {
        if (W_first[i] == W_first[j])
            ptr[i] = ptr[j];
        else {
            ptr[i] = j;
            do
                j = ptr[j];
            while (j >= 0 && W_first[i] != W_first[j]);
        }
        if (i == m-1) ptr[m] = j+1;
    }
    for (int i = 0, j = 0; i < n;) {
        if (W_first[j] == S_first[i]) {
            i++, j++;
            if (j == m) {
                out.push_back(i-j);
                j = ptr[j];
            }
        } else {
            j = ptr[j];
            if (j < 0) i++, j++;
        }
    }
    return out;
}

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

using mod = modint<int(1e9+7)>;
const int N = 1e6+5;
mod pc[N][26];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    string s0, t; cin >> s0 >> t;
    mod p2 = 1;
    for (int i = n; i > 0; i--) {
        copy(pc[i+1], pc[i+1]+26, pc[i]);
        pc[i][t[i-1]-'a'] += p2, p2 *= 2;
    }
    while (q--) {
        int k, p = 0; cin >> k;
        string w, s = s0; cin >> w;
        while (s.size() < w.size() && p < k) s = s+t[p++]+s;
        debug(s, w);
        debug(k, p);
        mod ans = mod(2).pow(k-p)*kmp(all(s), all(w)).size();
        string rw = w, rs = s;
        reverse(all(rw)), reverse(all(rs));
        auto z1 = z_function(w+'$'+s), z2 = z_function(rw+'$'+rs);
        mod f[26];
        for (int c = 0; c < 26; c++) {
            f[c] = (pc[p+1][c]-pc[k+1][c])/mod(2).pow(n-k);
        }
        int ws = w.size();
        for (int i = 0; i < ws; i++) {
            bool pre = (i == 0 || z1[z1.size()-i] >= i);
            bool suf = (i == ws-1 || z2[z2.size()-(ws-i-1)] >= ws-i-1);
            debug(i, pre, suf);
            if (pre && suf) ans += f[w[i]-'a'];
        }
        cout << ans << "\n";
    }
}