#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 3e5 + 10;
const long long inf = 1e18;
struct node{
    long long v[2][2];
    void init(int x) {
        v[0][0] = x;
        v[1][1] = -x;
        v[0][1] = v[1][0] = -1e18;
    }
    long long get() {
        long long w = -inf;
        for (int i = 0; i < 2; i ++)
            for (int j = 0; j < 2; j ++)
                w = max(w, v[i][j]);
        return w;
    }
}f[N * 4];
int a[N];
int n, m, T;
void upd(int s) {
    f[s].v[0][0] = f[s].v[0][1] = f[s].v[1][0] = f[s].v[1][1] = -inf;
    for (int i = 0; i < 2; i ++)
        for (int j = 0; j < 2; j ++) {
            f[s].v[i][j] = max(f[s].v[i][j], max(f[s + s].v[i][j], f[s+s+1].v[i][j]));
            for (int k = 0; k < 2; k++)
                f[s].v[i][k] = max(f[s].v[i][k], f[s + s].v[i][j] + f[s + s + 1].v[j ^ 1][k]);
        }
}
void build(int l, int r, int s) {
    if (l == r) {
        f[s].init(a[l]);
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s + s + 1);
    upd(s);
}
void change(int l, int r, int s, int ll) {
    if (l == r) {
        f[s].init(a[l]);
        return;
    }
    if ((l + r)  / 2 >= ll) change(l, (l + r) / 2, s + s, ll);
    else
        change((l + r) / 2 +1 , r, s + s + 1, ll);
    upd(s);
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        build(1, n, 1);
        printf("%lld\n", f[1].get());
        while (m --) {
            int x, y;
            scanf("%d %d", &x ,&y);
            swap(a[x], a[y]);
            change(1, n, 1, x);
            change(1, n, 1, y);
            printf("%lld\n", f[1].get());
        }
    }
    return 0;
}