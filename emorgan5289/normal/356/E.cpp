#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

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

const int N = 1e5+5, K = 17;
const ll p = 45439, mod = 1e9+7;
ll ppow[N], pinv[N], chash[N];

vector<pair<int, int>> dp[K][N];
int f[2][N][26];
ll cs[N], c[N][26];
bool v[K][N];

ll query(int i, int j) {
    return (mod+chash[j]-(i == 0 ? 0ll : chash[i-1]))*pinv[i]%mod;
}

ll toggle(ll h, int i, int x, int y) {
    return (h+mod+(ppow[i]*(y-x)%mod))%mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a; cin >> a;
    int n = a.size();
    ppow[0] = pinv[0] = 1;
    ll pi = inv(p, mod);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            ppow[i] = ppow[i-1]*p%mod;
            pinv[i] = pinv[i-1]*pi%mod;
        }
        chash[i] = ((i == 0 ? 0 : chash[i-1])+ppow[i]*(a[i]-'a'))%mod;
    }
    for (ll i = 0; i < n; i++)
        f[0][i][a[i]-'a']++;
    fill(v[0], v[0]+n, 1);
    ll g = n;
    for (ll k = 1; (1<<k+1)-1 <= n; k++) {
        for (ll i = (1<<k)-1; i < n-(1<<k)+1; i++) {
            ll l = i-(1ll<<k-1ll), r = i+(1ll<<k-1ll);
            for (int j = 0; j < 26; j++)
                f[1][i][j] = f[0][l][j]+f[0][r][j]+(a[i]-'a' == j);
            ll w = ((1ll<<k+1ll)-1ll)*((1ll<<k+1ll)-1ll);
            bool fleft = f[0][l][a[i]-'a'] == 0, fright = f[0][r][a[i]-'a'] == 0;
            ll left = query(l-(1<<k-1)+1, i-1), right = query(i+1, r+(1<<k-1)-1);
            v[k][i] = v[k-1][l] && v[k-1][r] && fleft && fright && left == right;
            if (v[k][i]) {
                cs[l-(1<<k-1)+1] -= w;
                cs[i] += w, cs[i+1] -= w;
                cs[r+(1<<k-1)] += w;
                for (int j = 0; j < 26; j++)
                    if (f[0][l][j] != 0 || f[0][r][j] != 0)
                        c[i][j] -= w;
                g += w;
                if (k == 3)
                    debug(i);
            } else {
                if (v[k-1][l] && v[k-1][r]) {
                    if (left == right) {
                        for (int j = 0; j < 26; j++)
                            if (f[0][l][j] == 0 && f[0][r][j] == 0)
                                c[i][j] += w, dp[k][i].pb({i, j});
                    } else if (a[l] != a[r] && toggle(left, (1<<k-1)-1, a[l]-'a', a[r]-'a') == right) {
                        if (fleft) c[r][a[l]-'a'] += w, dp[k][i].pb({r, a[l]-'a'});
                        if (fright) c[l][a[r]-'a'] += w, dp[k][i].pb({l, a[r]-'a'});
                    }
                }
                if (v[k-1][l] && !v[k-1][r] && fleft) {
                    for (auto& [y, j] : dp[k-1][r])
                        if (left == toggle(right, y-i-1, a[y]-'a', j))
                            c[y][j] += w, dp[k][i].pb({y, j});
                }
                if (!v[k-1][l] && v[k-1][r] && fright) {
                    for (auto& [y, j] : dp[k-1][l])
                        if (right == toggle(left, y-(l-(1<<k-1)+1), a[y]-'a', j))
                            c[y][j] += w, dp[k][i].pb({y, j});
                }
            }
            for (auto& [y, j] : dp[k][i])
                if (k == 3) debug(y, j);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 26; j++)
                f[0][i][j] = f[1][i][j];
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) cs[i] += cs[i-1];
        for (int j = 0; j < 26; j++)
            if (j != a[i]-'a')
                c[i][j] += cs[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 26; j++) {
            ans = max(ans, c[i][j]);
        }
    cout << g+ans << "\n";
}