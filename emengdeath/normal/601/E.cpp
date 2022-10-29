#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 3e4+ 10;
const int M = 1e3 + 10;
vector<pair<int, int> > f[N * 4];
int w[20][M], tmp[M];
pair<int, int> a[N * 2];
int l[N * 2], r[N * 2];
int ans[N];
int n, m, t;
void ins(int l, int r, int s, int ll, int rr, pair<int, int> v) {
    if (rr < l || r < ll) return;
    if (ll <= l && r <= rr) {
        f[s].push_back(v);
        return;
    }
    ins(l, (l + r) / 2, s + s, ll, rr, v);
    ins((l + r) / 2 + 1, r, s + s + 1, ll, rr, v);
}
void work(int l, int r, int s, int x) {
    for (int i = 0; i <= m;i ++)
        w[x][i] = w[x - 1][i];
    for (auto u:f[s]) {
        for (int i = 0; i <= m; i ++)
            if (w[x][i]) {
                if (i + u.second <= m && (!tmp[i + u.second] || tmp[i + u.second] < w[x][i] + u.first) )
                    tmp[i + u.second] = w[x][i] + u.first;
                if (!tmp[i] || tmp[i] < w[x][i])
                    tmp[i] = w[x][i];
            }
        for (int i = 0; i <= m; i ++)
            w[x][i] = tmp[i], tmp[i] = 0;
    }
    if (l == r) {
        const int p = 1e7 + 19, mod = 1e9 + 7;
        for (int i = 1; i <= m;i ++)
            w[x][i] = max(w[x][i - 1], w[x][i]);
        int v = 1;
        for (int i = 1; i <=m; i ++) {
            ans[l] = (ans[l] + 1ll * v * (w[x][i] - 1)) % mod;
            v = 1ll * v * p % mod;
        }
        return;
    }
    work(l, (l + r)  / 2, s + s, x + 1);
    work((l + r) / 2 + 1, r, s + s + 1, x + 1);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%d %d", &a[i].first, &a[i].second);
        l[i] = t +1;
        r[i] = 1e9;
    }
    int q;
    scanf("%d", &q);
    while (q --) {
        int sig, x, y;
        scanf("%d", &sig);
        switch (sig) {
            case 1:
                ++n;
                scanf("%d %d", &a[n].first, &a[n].second);
                l[n] = t + 1;
                r[n] = 1e9;
                break;
            case 2:
                scanf("%d", &x);
                r[x] = t;
                break;
            case 3:
                ++t;
                break;
        }
    }
    for (int i = 1; i <= n;i ++) {
        ins(1, t, 1, l[i], r[i], a[i]);
    }
    w[0][0] = 1;
    work(1, t, 1, 1);
    for (int i= 1; i <= t; i ++)
        printf("%d\n", ans[i]);
    return 0;
}