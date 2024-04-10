#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;
const int mod = 998244353l;
typedef long long ll;
const int N = 60;
ll f[N][N * 4][N];
int l[N], r[N], d[N * 2], ni[N];
int n;
vector<pair<int, int> > w;
unordered_map<int, int> g[N];
ll get(ll n, ll k) {
    if (g[k].find(n) != g[k].end())
        return g[k][n];
    ll v = 1;
    for (int i = 1; i <= k; i ++)
        v = v * (n + i - 1) % mod * ni[i] % mod;
    g[k][n] = v;
    return v;
}
ll calc(ll x, ll y) {
    ll z= 1;
    while (y) {
        if (y & 1) z = z * x % mod;
        x = x * x %mod, y/= 2;
    }
    return z;
}
int main() {
    scanf("%d", &n);
    ll all = 1;
    for (int i = 1; i <= n; i ++)
        ni[i] = calc(i, mod - 2);
    for (int i = 1; i <= n; i ++)
        scanf("%d %d", &l[n - i + 1], &r[n - i + 1]);
    for (int i = 1; i <= n; i ++) d[i] = l[i], d[i + n] = r[i], all = (all *(r[i] - l[i] + 1)) % mod;
    sort(d + 1, d + n + n + 1);
    d[0] = -1;
    int tot = 0;
    for (int i = 1; i <= n + n ; i ++)
        if (d[i] != d[tot])
            d[++tot] = d[i];
    for (int i = 0; i <= tot; i ++) {
        w.push_back(make_pair(d[i],d[i]));
        if (i != tot && d[i] + 1 <= d[i + 1] - 1)
            w.push_back(make_pair(d[i] + 1, d[i + 1] - 1));
    }
    f[0][0][1] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < w.size(); j ++)
            for (int k = 1; k <= i ;k ++)
                if (f[i -1][j][k])
                    for (int x = j; x < w.size(); x ++)
                        if (l[i]<=w[x].first && w[x].second <= r[i]) {
                            if (x == j)
                                f[i][j][k+1] = (f[i][j][k + 1] + f[i - 1][j][k]) % mod;
                            else
                                f[i][x][1] = (f[i][x][1] + f[i - 1][j][k] * get(w[j].second - w[j].first+ 1, k)) % mod;
                        }
    ll ans = 0;
    for (int j = 0; j < w.size(); j ++)
        for (int k = 1; k <= n; k ++)
            ans = (ans + f[n][j][k] * get(w[j].second - w[j].first + 1, k)) % mod;
    printf("%lld\n", ans * calc(all, mod - 2) % mod);
    return 0;
}