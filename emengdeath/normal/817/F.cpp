#include <cstdio>
#include <algorithm>
using namespace std;
const long long maxn = 2e18;
const int N = 1e5 + 10;
struct node{
    long long mn1, mn0;
    int tag;
}f[N * 20];
long long c[N * 4][2];
long long x[N * 4];
int n, tot;
void down(long long l, long long r, int s) {
    if (f[s].tag == 1) {
        f[s].mn0 = maxn;
        f[s].mn1 = c[l][0];
        if (l!=r) {
            f[s+s].tag = 1;
            f[s+s+1].tag = 1;
        }
        f[s].tag = 0;
    }

    if (f[s].tag == 2) {
        f[s].mn1 = maxn;
        f[s].mn0 = c[l][0];
        if (l!=r) {
            f[s+s].tag = 2;
            f[s+s+1].tag = 2;
        }
        f[s].tag = 0;
    }

    if (f[s].tag == 3) {
        swap(f[s].mn0, f[s].mn1);
        if (l!=r) {
            f[s+s+1].tag ^= 3;
            f[s+s].tag ^= 3;
        }
        f[s].tag = 0;
    }
}
void change(long long l, long long r, int s, int sig, long long L, long long R) {
    down(l, r, s);
    if (c[r][1] < L || R < c[l][0]) return;
    if (L <= c[l][0] && c[r][1] <= R) {
        f[s].tag = sig;
        down(l, r, s);
        return;
    }
    change(l, (l + r) / 2, s+s, sig, L, R);
    change((l + r) / 2 + 1, r, s+s+1, sig, L, R);
    f[s].mn0 = min(f[s+s].mn0, f[s+s+1].mn0);
    f[s].mn1 = min(f[s+s].mn1, f[s+s+1].mn1);
}
struct node1{
    long long l, r;
    int sig;
}q[N];
void build(int l, int r, int s) {
    f[s].mn0 = c[l][0];
    f[s].mn1 = maxn;
    if (l == r)return;
    build(l, (l + r) /2 ,  s+s);
    build((l + r) /2 +1, r,  s+s +1);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d %lld %lld", &q[i].sig, &q[i].l, &q[i].r), x[++x[0]] = q[i].l, x[++x[0]] = q[i].r;
    x[++x[0]] = 1;
    x[++x[0]] = maxn;
    sort(x+1, x + x[0] + 1);
    int tmp = x[0];
    x[0] = 1;
    for (int i = 1; i <= tmp; i ++)
        if (x[x[0]] != x[i])
            x[++x[0]] = x[i];
    int tot = 0;
    for (int i = 1; i < x[0]; i ++)
    {
        c[++tot][0] = x[i];
        c[tot][1] = x[i];
        if (x[i] + 1 != x[i + 1])
        {
            c[++tot][0] = x[i] + 1;
            c[tot][1] = x[i + 1] - 1;
        }
    }
    c[++tot][0] = x[x[0]];
    c[tot][1] = x[x[0]];
    build(1, tot, 1);
    for (int i= 1; i <= n; i ++){
        change(1, tot, 1, q[i].sig, q[i].l, q[i].r);
        printf("%lld\n", f[1].mn0);
    }
    return 0;
}