#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 +10;
int n, k;
long long ans;
int a[N], b[N][2], f[N];
struct node{
    int v[2];
    bool tag;
    void clear() {
        v[0] = v[1] = tag = 0;
    }
}w[N*4];
vector<int> g[N];
long long choose(int x) {
    return 1ll * x * (x - 1) / 2;
}
void upd(int s) {
    w[s].v[0] = w[s+s].v[0] + w[s+s+1].v[0];
    w[s].v[1] = w[s+s].v[1] + w[s+s+1].v[1];
}
void down(int l, int r, int s) {
    if (w[s].tag) {
        swap(w[s].v[0], w[s].v[1]);
        if (l!=r) w[s+s].tag ^= 1, w[s+s+1].tag^=1;
        w[s].tag = 0;
    }
}
void build(int l, int r, int s) {
    w[s].clear();
    if (l == r) {
        w[s].v[0] = 1;
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s + s + 1);
    upd(s);
}
void change(int l, int r, int s, int ll, int rr) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        w[s].tag ^= 1;
        down(l, r, s);
        return;
    }
    change(l, (l + r) / 2, s +s, ll, rr);
    change((l + r) / 2 + 1, r, s +s+1, ll, rr);
    upd(s);
}
int get(int l, int r, int s, int ll, int rr) {
    down(l, r, s);
    if (r < ll || rr < l) return 0;
    if (ll <= l && r <= rr) return w[s].v[0];
    return get(l, (l + r) / 2, s +s, ll, rr) + get((l +r ) / 2 + 1, r, s + s + 1, ll, rr);
}
void work() {
    build(1, n, 1);
    for (int i = 1; i <= n ; i ++) {
        for (auto u:g[i])
            if (u >= i)
                change(1, n, 1, i, u);
            else
                change(1, n, 1, u, i - 1);
        a[i] = get(1, n, 1, 1, i - 1);
    }
}
int main() {
    scanf("%d %d", &n, &k);
    ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= k; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x = lower_bound(a + 1, a + n + 1, x) - a;
        y = upper_bound(a + 1, a + n + 1, y) - a - 1;
        if (x > y) {
            i --;
            k --;
            continue;
        }
        b[i][0] = x;
        b[i][1] = y;
    }
    for (int i = 1; i <= k; i++)
        g[b[i][0]].push_back(b[i][1]), g[b[i][1] + 1].push_back(b[i][0]);
    memset(a, 0, sizeof(a));
    work();
    for (int i = 1; i <= n;i ++)
        f[i] = a[i], g[i].clear();
    for (int i = 1; i <= k; i++) {
        int l = n - b[i][1] + 1, r = n - b[i][0] + 1;
        g[l].push_back(r), g[r + 1].push_back(l);
    }
    g[1].push_back(n);
    memset(a, 0, sizeof(a));
    work();
    for (int i= 1; i <= n;i ++) {
        ans -= choose(f[i] + a[n - i + 1]);
    }
    cout << ans;
    return 0;
}