#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 5e5+ 10;
vector<pair<int, int> > g[N];
struct node{
    int mn, tag, mx;
    long long all;
}f[N * 4];
pair<int, int> a[N];
int n, p, q, w;
void down(int l, int r, int s) {
    if (l != r) {
        f[s+s].tag = max(f[s+s].tag, f[s].tag);
        f[s+s+1].tag = max(f[s+s+1].tag, f[s].tag);
    }
    if (f[s].tag >= f[s].mx) {
        f[s].mn = f[s].mx = f[s].tag;
        f[s].all = 1ll * (r - l + 1) * f[s].tag;
    }
}
void upd(int s) {
    f[s].mn = min(f[s+s].mn, f[s+s+1].mn);
    f[s].mx = max(f[s+s].mx, f[s+s+1].mx);
    f[s].all = f[s+s].all + f[s+s+1].all;
}
void ins(int l, int r, int s, int ll, int v) {
    down(l, r, s);
    if (l > ll || f[s].mn >= v) return;
    if (r <= ll && f[s].mx <= v) {
        f[s].tag = v;
        down(l, r, s);
        return;
    }
    ins(l, (l + r) / 2, s + s, ll, v);
    ins((l + r) / 2 + 1, r, s +s + 1, ll, v);
    upd(s);
}
long long ans;
void get(int l, int r, int s, int ll, int v) {
    down(l, r, s);
    if (r < ll) return;
    if (l >= ll) {
        if (f[s].mx <= v) {
            ans += 1ll * (r - l + 1) * (w - v + 1);
            return;
        }
        if (f[s].mn >= v) {
            ans += 1ll * (r - l + 1) * (w + 1) - f[s].all;
            return;
        }
    }
    get(l, (l + r) /2, s + s, ll, v);
    get((l + r) /2 + 1, r, s + s +1, ll, v);
}
int main() {
    scanf("%d %d %d %d", &n, &p, &q, &w);
    for (int i = 1 ; i <= n; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back({y, z});
    }
    a[p + 1] = {1, 1};
    for (int i = p; i >=1; i --)
    {
        a[i] = a[i + 1];
        for (auto u:g[i])
            a[i].first = max(a[i].first, u.first + 1), a[i].second = max(a[i].second, u.second + 1);
    }
    for (int i = 1; i <= p; i ++) {
        for (auto u:g[i - 1])
            ins(1, q, 1, u.first, u.second + 1);
        get(1, q, 1, a[i].first, a[i].second);
    }
    printf("%lld", ans);
    return 0;
}