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

struct dsu {

    vector<int> p, sz;

    dsu(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int rep(int x) {
        while (x != p[x]) x = p[x] = p[p[x]];
        return x;
    }

    void unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (a != b) p[b] = a, sz[a] += sz[b];
    }

    // returns true if a and b are in the same set.
    bool query(int a, int b) {
        return rep(a) == rep(b);
    }

    // returns the size of the set containing x
    int size(int x) {
        return sz[rep(x)];
    }
};

const int N = 55;
__int128_t f[N], dp[N];

vector<ll> kthcycle(ll n, __int128_t k) {
    vector<bool> out(n);
    vector<ll> ans(n, -1);
    ans[0] = n-1, out[n-1] = 1;
    dsu u(n); u.unite(0, n-1);
    for (int i = 1; i < n-1; i++) {
        if (n-i >= 22) ans[i] = i-1, out[i-1] = 1, u.unite(i, i-1);
        else {
            auto b = f[n-i-2];
            auto x = k/b;
            k %= b;
            for (int j = 0; j < n; j++)
                if (!out[j] && j != i && !u.query(i, j) && x-- == 0) {
                    out[j] = 1, ans[i] = j, u.unite(i, j);
                    break;
                }
        }
    }
    for (int i = 0; i < n; i++)
        if (!out[i]) ans[n-1] = i;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    f[0] = 1;
    for (int i = 1; i <= 50; i++)
        f[i] = f[i-1]*i;
    dp[0] = 1;
    for (int i = 1; i <= 50; i++)
        for (int j = 0; j < i; j++)
            dp[i] += dp[j]*f[max(0, i-j-2)];
    while (t--) {
        ll n, _k; cin >> n >> _k;
        __int128_t k = _k-1;
        if (n <= 24 && dp[n] <= k) {
            cout << "-1\n";
            continue;
        }
        ll p = 1;
        vector<ll> ans;
        while (n > 0) {
            if (n >= 25) ans.pb(p++), n--;
            else {
                for (int i = 1; i <= n; i++) {
                    if (dp[n-i]*f[max(0, i-2)] <= k) k -= dp[n-i]*f[max(0, i-2)];
                    else {
                        auto b = dp[n-i];
                        for (auto& x : kthcycle(i, k/b))
                            ans.pb(x+p);
                        p += i;
                        k %= b;
                        n -= i;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " \n"[i == ans.size()-1];
    }
}