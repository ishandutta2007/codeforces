#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int mod = 1e9  +7;
const int N = 1e6 + 1;
struct node{
    int v, tag;
}f[N * 4];
int a[N], b[N], c[N];
int n , m ;
void update(int s) {
    f[s].v = min(f[s+s].v, f[s+s+1].v);
}
void down(int l, int r, int s) {
    if (f[s].tag) {
        f[s].v += f[s].tag;
        if (l != r)
            f[s+s].tag += f[s].tag, f[s+s+1].tag += f[s].tag;
        f[s].tag = 0;
    }
}
void build(int l, int r, int s) {
    if (l == r) {
        f[s].v = c[l];
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s + s + 1);
    update(s);
}
void change(int l, int r, int s, int ll, int rr, int v) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr ){
        f[s].tag += v;
        down(l, r, s);
        return;
    }
    change(l, (l + r) / 2, s+s, ll, rr, v);
    change((l + r) / 2+1, r, s+s+1, ll, rr, v);
    update(s);
}
int ans;
void search(int l, int r, int s) {
    down(l, r, s);
    if (f[s].v >= 0 || ans != -1) return;
    if (l == r) {
        ans = l;
        return;
    }
    search((l + r) / 2 + 1, r, s +s + 1);
    search(l, (l + r) / 2, s +s);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i ++) {
        scanf("%d", &a[i]);
        c[a[i]] --;
    }
    for (int i = 1; i <= m ; i ++) {
        scanf("%d", &b[i]);
        c[b[i]] ++;
    }
    for (int i = 1000000 - 1; i >= 1; i --)
        c[i] += c[i + 1];
    build(1, 1000000, 1);
    int q;
    scanf("%d", &q);
    while (q --) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if (x == 1) {
            change(1, 1000000, 1, 1, a[y], 1);
            change(1, 1000000, 1, 1, a[y] = z, -1);
        } else {
            change(1, 1000000, 1, 1, b[y], -1);
            change(1, 1000000, 1, 1, b[y] = z, 1);
        }
        ans = -1;
        search(1, 1000000, 1);
        printf("%d\n", ans);
    }
    return 0;
}