#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

const int maxn = 505;
ll a[maxn], b[maxn], c[maxn], p[maxn];
ll dp[maxn][maxn] = {};

struct fastmod {
    __int128_t b, m;
    fastmod(int64_t x) : b(x), m(((__int128_t)1<<64) / x) {}
    int64_t reduce(int64_t x) {
        __int128_t q = (m*x)>>64;
        __int128_t r = x - q*b;
        return r >= b ? r - b : r;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, k; cin >> n >> k;
    fastmod f(k);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for (int i = n; i >= 0; i--) {
        c[i] = a[i]+b[i];
        p[i] = c[i] + (i == n-1 ? 0 : p[i+1]);
    }
    for (int i = 0; i < n; i++)
        for (int x = 0; x < k; x++) {
            int y = f.reduce(p[i+1]-x);
            if (y < 0) continue;
            ll ck = f.reduce(c[i]);
            ll mx = 0;
            ll bnd = min(k, a[i]+1);
            for (int dx = 0; dx < bnd; dx++) {
                int dy = f.reduce(c[i]-dx);
                if (dy > b[i]) continue;
                mx = max(mx, dp[i][f.reduce(x+dx)] + (x+dx >= k) + (y+dy >= k) - (dx+dy > ck));
            }
            dp[i+1][x] = mx+c[i]/k;
        }
    cout << dp[n][0] << "\n";
}