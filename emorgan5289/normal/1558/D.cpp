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

const int N = 5e5+5, B = 500;
deque<int> v[B];
int off[B];
mod f[N];

mod ch(int x, int y) {
    if (y < 0 || y > x) return 0;
    return f[x]/f[y]/f[x-y];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = i*f[i-1];

    int t; cin >> t;
    while (t--) {
        for (int i = 0; i < B; i++)
            v[i].clear(), off[i] = 0;
        ll n, m; cin >> n >> m;
        for (int i = 0; i < m; i++) {
            if (i%1000 == 0) debug(i);
            int x, y; cin >> x >> y;
            int b = y/B;
            v[b].push_back(y-off[b]);
            for (int j = v[b].size()-1; j > 0; j--) {
                if (v[b][j] < v[b][j-1]) swap(v[b][j], v[b][j-1]);
                if (v[b][j] == v[b][j-1]) v[b].erase(v[b].begin()+j);
            }
            for (int j = 0; j < v[b].size(); j++)
                if (v[b][j]+off[b] >= y) v[b][j]++;
            for (int j = b+1; j < B; j++)
                off[j]++;
            for (int j = 0; j < B-1; j++)
                while (!v[j].empty() && (v[j].back()+off[j])/B != j) {
                    v[j+1].push_front(v[j].back()+off[j]-off[j+1]);
                    v[j].pop_back();
                }
        }
        int c = 1;
        for (int i = 0; i < B; i++)
            c += v[i].size();
        debug(n, c);
        cout << ch(2*n-c, n) << "\n";
    }
}