#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
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
    template<typename T> operator T() { return T(v); }

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

using mod = modint<int(1e9+7)>;

const int N = 105;
vector<int> adj[N];
mod ans[N], ch[N][N], dp[N][N][N], tmp[N][N];
int n, sz[N];

void dfs(int i, int p) {
    dp[i][0][1] = sz[i] = 1;
    for (auto& j : adj[i]) {
        if (j == p) continue;
        dfs(j, i);
        for (int x = n; x >= 0; x--)
            for (int y = n; y >= 0; y--)
                tmp[x][y] = dp[i][x][y], dp[i][x][y] = 0;
        for (int x = 0; x <= sz[i]; x++)
            for (int y = 0; y <= sz[i]; y++)
                for (int w = 0; w <= sz[j]; w++)
                    for (int z = 0; z <= sz[j]; z++)
                        dp[i][x+w][y+z] += tmp[x][y]*dp[j][w][z];
        sz[i] += sz[j];
    }
    for (int x = 1; x <= n; x++)
        for (int z = 1; z <= n; z++)
            dp[i][x][0] += dp[i][x-1][z]*z;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    for (int i = 0; i < n; i++) {
        ch[i][0] = 1;
        for (int j = 1; j <= i; j++)
            ch[i][j] = ch[i-1][j]+ch[i-1][j-1];
    }
    dfs(0, 0);
    mod r = mod(1)/n;
    for (int i = n-1; i >= 0; i--) {
        ans[i] = dp[0][n-i][0]*r, r *= n;
        for (int j = i+1; j < n; j++)
            ans[i] -= ans[j]*ch[j][i];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i==n-1];
}

// dp[i][x][y] = subtree at i, x completed components, uncompleted of size y

//                 dp[i][0][1] = 1
// x > 0:          dp[i][x][0] = sum over z of dp[x-1][z]/z
// x > 0, y > 0:   dp[i][x][y] = sum over [w, z] of dp[i][w][z]*dp[j][x-w][y-z]