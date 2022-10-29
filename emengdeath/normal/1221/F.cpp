#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
const int N = 5e5 + 10;
struct node{
    int x;
    long long tag;
    long long v;
}f[N * 4], d;
int n;
int c[N];
pair<int, pair<int, int> > a[N];
set<pair<int, int> > w;
void down(int l, int r, int s) {
    if (f[s].tag) {
        f[s].v += f[s].tag;
        if (l != r)
            f[s+s].tag += f[s].tag, f[s+s+1].tag += f[s].tag;
        f[s].tag = 0;
    }
}
void merge(node&a, node b, node c) {
    a.v = max(b.v, c.v);
    if (b.v == a.v)
        a.x = b.x;
    else
        a.x = c.x;
}
void build(int l, int r, int s) {
    if (l == r) {
        f[s].x = c[l];
        f[s].v = -c[l];
        return;
    }
    build(l, (l + r) / 2, s +s);
    build((l + r) / 2 + 1, r, s + s + 1);
    merge(f[s], f[s+s], f[s+s+1]);
}
void add(int l, int r ,int s, int ll, int v) {
    down(l, r, s);
    if (c[r] < ll) return;
    if (c[l] >= ll) {
        f[s].tag += v;
        down(l, r, s);
        return;
    }
    add(l, (l + r)/ 2, s + s, ll, v);
    add((l + r) / 2 + 1, r, s + s + 1,ll, v);
    merge(f[s], f[s+s],f[s+s+1]);
}
void get(int l, int r, int s, int ll) {
    if (c[r] < ll) return;
    down(l, r, s);
    if (c[l] >= ll) {
        merge(d, d, f[s]);
        return;
    }
    get(l, (l + r) / 2, s + s, ll);
    get((l + r) / 2 + 1, r, s + s+ 1, ll);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if (x <= y)
            a[i] = {x, {y, z}};
        else
            a[i] = {y, {x, z}};
        w.insert({x, y});
        c[i] = a[i].second.first;
    }
    sort(c + 1, c + n + 1);
    c[0] = 1;
    for (int i = 1; i <= n; i ++)
        if (c[i] != c[c[0]]) c[++c[0]] = c[i];
    pair<pair<int, int>, pair<int, int> > ans1 = {{0, 0}, {0, 0}};
    long long ans2 = 0;
    for (int i = 0; ; i ++)
        if (w.find({i, i}) == w.end())
        {
            ans1 = {{i, i}, {i, i}};
            break;
        }
    build(1, c[0], 1);
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int l = 1;
    while (l <= n) {
        int r = l;
        while (r + 1 <= n && a[r + 1].first == a[l].first) ++r;
        for (int i = l ;i <= r; i ++)
            add(1, c[0], 1, a[i].second.first, a[i].second.second);
        d.v = -1e18;
        get(1, c[0], 1, a[l].first);
        d.v += a[l].first;
        if (d.v > ans2) {
            ans2 = d.v;
            ans1 = {{a[l].first, a[l].first}, {d.x, d.x}};
        }
        l = r + 1;
    }
    printf("%lld\n%d %d %d %d\n", ans2, ans1.first.first, ans1.first.second, ans1.second.first, ans1.second.second);
    return 0;
}