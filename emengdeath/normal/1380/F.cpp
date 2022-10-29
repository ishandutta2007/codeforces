#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 5e5 + 10;
int sum[100];
int n, m;
struct node{
    int v[2][2];
    int l, r;
}f[N * 4];
int v[N];
const int mod = 998244353;
int mul(int x, int y) {
    return 1ll * x  * y % mod;
}
int add(int x, int y) {
    x += y;
    return x >= mod ? x - mod : x;
}
void merge(node&a, node b, node c) {
    for (int i = 0; i < 2; i ++)
        for (int j = 0; j < 2; j ++) {
            a.v[i][j] = add(mul(b.v[i][0], c.v[0][j]), mul(mul(mul(b.v[i][1], c.v[1][j]), sum[v[b.r] * 10 + v[c.l]]), v[b.r] > 0));

        }
}
void build(int l, int r, int s) {
    if (l == r) {
        f[s].v[0][0] = sum[v[l]];
        f[s].v[0][1] = 1;
        f[s].v[1][0] = 1;
        f[s].l = l, f[s].r = r;
        return;
    }
    f[s].l = l;
    f[s].r = r;
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s + s + 1);
    merge(f[s], f[s+s], f[s+s+1]);
}
void change(int l, int r ,int s, int ll) {
    if (l == r) {
        f[s].v[0][0] = sum[v[l]];
        f[s].v[0][1] = 1;
        f[s].v[1][0] = 1;
        f[s].l = l, f[s].r = r;
        return;
    }
    if ((l + r) / 2 >= ll) change(l, (l + r) / 2, s + s, ll);
    else
        change((l + r) / 2 + 1, r, s + s + 1, ll);
    merge(f[s], f[s+s], f[s+s+1]);
}
int main() {
    for (int i = 0; i < 10; i ++)
        for (int j = 0; j < 10; j ++)
            sum[i + j] ++;
    scanf("%d %d", &n, &m);
    for (int i = 1;i <= n; i ++) {
        char c;
        scanf(" %c", &c);
        v[i] = c - '0';
    }

    /*if (n == 3 && m == 500000 && v[1] == 7) {
        for (int i = 1; i <= 50; i ++)
        {
            int x ,y;
            scanf("%d %d", &x, &y);
            v[x] = y;
        }
        printf("%d%d%d", v[1], v[2] ,v[3]);
        return 0;
    }*/
    build(1, n, 1);
    while (m -- ){
        int x, y;
        scanf("%d %d", &x, &y);
        v[x] = y;
        change(1, n, 1, x);
        printf("%d\n", f[1].v[0][0]);
    }
    return 0;
}