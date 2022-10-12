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

// given an array a of length n, returns an array b of length n-k+1
// such that b[i] = op(a[i], a[i+1], ..., a[i+k-1])
template<typename it1, typename it2, typename bin_op>
void sliding_window_fold(it1 first, it1 last, it2 result, int width, bin_op op) {
    int n = distance(first, last);
    vector p(first, last), s(first, last);
    for (int i = n-1; i >= 0; i--)
        if (i%width != width-1 && i != n-1) s[i] = op(s[i], s[i+1]);
    for (int i = 0; i < n; i++)
        if (i%width) p[i] = op(p[i], p[i-1]);
    for (int i = 0; i <= n-width; i++, result++)
        *result = i%width ? op(s[i], p[i+width-1]) : s[i];
}

ll n, k;
string s;

bool solve(ll x) {
    debug(x);
    vector<int> dp(1<<k, inf);
    vector<int> tmp(n, 0), m;
    vector<vector<int>> val(n, vector<int>(k, inf));
    for (int i = 0; i < n; i++)
        tmp[i] = s[i] == '?' ? 0 : 1<<(s[i]-'a');
    sliding_window_fold(all(tmp), back_inserter(m), x,
        [&](int i, int j){ return i|j; }
    );
    for (int i = n-x; i >= 0; i--) {
        if (m[i] == 0) {
            for (int j = 0; j < k; j++)
                val[i][j] = i+x;
        } else if (__builtin_popcount(m[i]) == 1) {
            val[i][__builtin_ctz(m[i])] = i+x;
        }
        if (i < n-1)
            for (int j = 0; j < k; j++)
                cmin(val[i][j], val[i+1][j]);
    }
    debug(val);
    dp[0] = 0;
    for (int i = 0; i < 1<<k; i++) {
        for (int j = 0; j < k; j++) {
            if (i&(1<<j)) continue;
            if (dp[i] < n)
                cmin(dp[i|(1<<j)], val[dp[i]][j]);
        }
    }
    debug(dp);
    return dp[(1<<k)-1] <= n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> s;
    ll ans = 0;
    for (int i = 1<<20; i > 0; i >>= 1)
        if ((ans+i)*k <= n && solve(ans+i)) ans += i;
    cout << ans << "\n";
}