#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 51;
typedef long long ll;
const ll MAXN = 1ll * 1000000000 * 1000000000 + 1;
ll mul(ll x, ll y) {
    if (!x || !y) return 0;
    if (MAXN / x < y) return MAXN;
    return x * y;
}
ll add(ll x, ll y) {
    return x + y <= MAXN?x + y : MAXN;
}
ll f[N], g[N], w[N];
int d[N];
bool bz[N];
int main() {
    int T;
    scanf("%d", &T);
    f[0] = 1;
    f[1] = 1;
    g[0] = 1;
    g[1] = 1;
    w[0] = 1;
    w[1] = 1;
    for (int i = 2; i < N ; i ++) {
        f[i] = mul(f[i - 1], i - 1);
        w[i] = f[i - 1];
        for (int j = 1; j <= i ; j ++)
            g[i] = add(g[i], mul(w[j], g[i - j]));
    }
    while (T --) {
        int n;
        ll k;
        scanf("%d %lld", &n, &k);
        memset(bz, 0, sizeof(bz));;
        memset(d, 0, sizeof(d));
        int r = 0;
        if (k > g[n]) {
            printf("-1\n");
            continue;
        }
        int sum = 0;
        for (int i = 1; i <= n ; i ++) {
            for (int j = 1; j <= n; j ++)
                if (!bz[j] && !(r >= i && j > r)) {
                    int x = j;
                    int cnt = 0;
                    d[i] = j;
                    while (d[x]) {
                        ++cnt;
                        x = d[x];
                        if (x == j) break;
                    }
                    if (x == j && d[x] && cnt != i - sum) continue;
                    int rr = max(r, j);
                    ll all = 0;
                    if (i == sum + 1) {
                        all = mul(w[rr - i + 1], g[n - rr]);
                    } else {
                        all = mul(f[rr - i], g[n - rr]);
                    }
                    if (all >= k) {
                        r = rr;
                        if (rr == i) sum = i;
                        bz[j ] =1;
                        break;
                    }
                    k -= all;
                }
        }
        for (int i = 0; i < n; i ++)
            printf("%d%c", d[i + 1], " \n"[i == n - 1]);
    }
    return 0;
}