#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 200101;
int n, q;
int a[N], v, ans;
long long b[N];
long long f[N * 4], g[N * 4], mx[N * 4];
void down(int l, int r, int s) {
    if (f[s] && l != r) {
        f[s +s] += f[s], f[s+s+1] += f[s];
        mx[s + s] += f[s], mx[s+s+1] += f[s];
        f[s] = 0;
    }
}
void ins(int l, int r, int s, int ll, int v) {
    down(l, r, s);
    if (r < ll) return;
    if (l >= ll) {
        f[s] += v;
        mx[s] += v;
        down(l, r, s);
        return;
    }
    ins(l, (l + r) / 2, s + s, ll, v);
    ins((l + r) / 2 + 1, r, s + s  +1, ll, v);
    mx[s] = mx[s+s+1];
}
long long get(int l, int r, int s, int ll) {
    while (l!=r) {
        down(l, r, s);
        if ((l + r) / 2 >= ll)  r = (l + r) / 2, s += s;
        else
            l = (l +r) /2 + 1, s += s  +1;
    }
    return f[s];
}
void change(int l, int r, int s, int ll) {
    if (l == r) {
        g[s] = l;
        return;
    }
    if ((l + r) / 2 >= ll)
        change(l, (l + r) / 2, s + s, ll);
    else
        change((l + r) / 2 + 1, r, s + s + 1, ll);
    if (a[g[s+s]] > a[g[s+s+1]])
        g[s] = g[s+s];
    else
        g[s] = g[s+s+1];
}
void search(int l, int r, int s, int ll, int rr) {
    if (r < ll || rr < l || (v && a[g[s]] <= a[v])) {
        return;
    }
    if (ll<=g[s] && g[s] <= rr) {
        v = g[s];
        return;
    }
    if (a[g[s+s]] > a[g[s+s+1]]) {
        search(l, (l + r) / 2, s + s, ll, rr);
        search((l + r) / 2 + 1, r, s + s + 1, ll, rr);
    } else {
        search((l + r) / 2 + 1, r, s + s + 1, ll, rr);
        search(l, (l + r) / 2, s + s, ll, rr);
    }
}
void build(int l, int r, int s) {
    if (l == r) {
        mx[s] = f[s] = b[l];
        return;
    }
    build(l, (l + r) / 2, s +s);
    build((l + r) / 2+ 1, r, s +s+ 1);
    mx[s] = mx[s+s+1];
}

void buildg(int l, int r, int s) {
    if (l == r) {
        g[s] = l;
        return;
    }
    buildg(l, (l + r) / 2, s +s);
    buildg((l + r) / 2+ 1, r, s +s + 1);
    if (a[g[s+s]] > a[g[s+s+1]])
        g[s] = g[s+s];
    else
        g[s] = g[s+s+1];
}
int get1(int l, int r, int s, long long v) {
    while (l!=r) {
        down(l, r, s);
        if (mx[s + s] > v)
            r = (l + r ) / 2, s += s;
        else
            l = (l + r) / 2 + 1, s += s + 1;
    }
    return l;
}
void work(int l, int r) {
    if (ans || l > r) return;
    v = 0;
    search(1, n, 1, l, r);
    int x = v;
    long long y = get(0, n - 1, 1, x - 1);
    if (y == a[x]) {
        ans = x;
        return;
    }
    if (!y)
        work(x + 1, r);
    if (y > a[x]) {
        int z = get1(0, n - 1, 1, a[x]);
        work(l, min(x - 1, z + 1));
    } else
        work(l, x - 1);
}
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++)
        b[i] += b[i - 1] + a[i];
    build(0, n - 1, 1);
    buildg(1, n, 1);
    for (int i =1; i <= q; i ++){
        int p, x;
        scanf("%d %d", &p, &x);
        int diff = x - a[p];
        ins(0, n - 1, 1, p, diff);
        ans = 0;
        a[p] = x;
        change(1, n, 1, p);
        work(1, n);
        ans?printf("%d\n", ans):puts("-1");
    }
    return 0;
}