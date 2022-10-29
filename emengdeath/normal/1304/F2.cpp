#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 2e4 + 10;
struct node{
    int tag, mx;
}f[N * 4];
int w[N], v[N];
int n, m, k;
int a[N], b[N];
void build(int l, int r, int s) {
    f[s].tag = 0;
    if (l == r) {
        f[s].mx = w[l] - (b[l + k - 1] - b[l - 1]);
        return;
    }
    build(l, (l + r) >> 1, s << 1);
    build(((l + r) >> 1) + 1, r, (s << 1) |1);
    f[s].mx = max(f[s + s].mx, f[s+s+1].mx);
}
void down(int l, int r, int s) {
    if (f[s].tag) {
        f[s].mx += f[s].tag;
        if (l != r)
            f[s + s].tag += f[s].tag, f[s+s+1].tag += f[s].tag;
        f[s].tag = 0;
    }
}
void add(int l, int r, int s, int ll, int rr, int v) {
    down(l, r, s);
    if (rr < l || r < ll) return;
    if (ll <= l && r <= rr) {
        f[s].tag += v;
        down(l, r, s);
        return;
    }
    add(l, (l + r) >> 1, s << 1,  ll, rr, v);
    add(((l + r) >> 1) + 1, r, (s << 1) | 1,  ll, rr, v);
    f[s].mx = max(f[s+s].mx, f[s+s+1].mx);
}
int main() {
  //  freopen("input", "r", stdin);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++)
            scanf("%d", &a[j]), b[j] = b[j - 1] + a[j];
        for (int j = 1; j + k - 1 <= m; j ++)
            w[j] += b[j + k - 1] - b[j - 1];
        if (i == 1) continue;
        build(1, m - k + 1, 1);
        for (int j = 1; j + k - 1 <= m; j ++) {
            v[j] = max(v[j], f[1].mx + b[j + k - 1] - b[j - 1]);
            add(1, m - k + 1, 1, j - k + 1, j,a[j]);
        }
        build(1, m - k + 1, 1);
        for (int j = m - k + 1; j >= 1; j --) {
            v[j] = max(v[j], f[1].mx + b[j + k - 1] - b[j - 1]);
            add(1, m - k + 1, 1, j, j + k - 1, a[j + k - 1]);
        }
        for (int j = 1; j <= m - k + 1; j ++)
            w[j] = v[j], v[j] = 0;
    }
    int ans = 0;
    for (int i  =1; i <= m - k + 1;i  ++)
        ans = max(ans, w[i]);
    printf("%d\n",ans);
    return 0;
}