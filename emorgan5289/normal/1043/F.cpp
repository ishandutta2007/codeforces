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

    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }

    modint& operator+=(const modint n) { v += n.v; v -= (M&0-(v>=M)); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&0-(v<0)); return *this; }
    modint& operator*=(const modint n) { v = reduce(v*n.v); return *this; }
    modint& operator/=(const modint n) { v = reduce(v*inv(n.v)); return *this; }
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
        if (k < 1) return k == 0 ? modint(1) : modint(inv(this->v)).pow(-k);
        return k&1 ? *this*(this->pow(k-1)) : (*this**this).pow(k>>1);
    }
};

vector<int> mobiussieve(int n) {
    vector<int> m(n+1, -1), p(n+1, 1);
    m[0] = 0, m[1] = 1;
    for (int i = 2; i <= n; i++)
        if (p[i]) for (int j = 2; j*i <= n; j++) {
            if (j%i) m[i*j] = m[i]*m[j];
            else m[i*j] = 0;
            p[i*j] = 0;
        }
    return m;
}

using mod = modint<int(1e9+7)>;

const int N = 3e5+5;
int f[N], m[N];
mod fc[N];
auto mu = mobiussieve(N);

mod ch(int n, int k) {
    return k < 0 || k > n ? 0 : fc[n]/fc[n-k]/fc[k];
}

bool valid(int i) {
    mod x = 0;
    for (int j = 1; j < N; j++)
        x += mu[j]*ch(m[j], i);
    return x != 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    fc[0] = 1;
    for (int i = 1; i < N; i++)
        fc[i] = i*fc[i-1];
    for (int i = 0; i < n; i++) {
        int x; cin >> x; f[x]++;
    }
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            m[i] += f[j];
    int x = n+1;
    for (int i = 1<<20; i > 0; i /= 2)
        if (x-i > 0 && valid(x-i)) x -= i;
    cout << (x == n+1 ? -1 : x) << "\n";
}