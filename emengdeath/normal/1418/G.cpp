#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6;
int f1[N], f2[N], f3[N];
struct node{
    int tag;
    int sum;
}f[N * 4];
int n;
int a[N];
void upd(int l, int r, int s) {
    if (f[s].tag)
        f[s].sum = 0;
    else {
        if (l == r) f[s].sum = 1;
        else {
            f[s].sum = f[s+s].sum + f[s+s+1].sum;
        }
    }
}
void search(int l, int r, int s, int ll) {
    if (l == r) {
        upd(l, r, s);
        return;
    }
    if ((l +r) / 2 >= ll)
        search(l, (l + r) / 2, s + s, ll);
    else
        search((l + r) / 2 + 1, r, s + s + 1, ll);
    upd(l, r, s);
}
void add(int l, int r, int s, int ll, int rr, int v) {
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        f[s].tag += v;
        upd(l, r, s);
        return;
    }
    add(l, (l + r) / 2, s + s, ll, rr, v);
    add((l + r) / 2 + 1, r, s + s + 1, ll ,rr, v);
    upd(l, r, s);
}
int main() {
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        search(1, n, 1, i);
        add(1, n, 1, f1[x]+ 1, i, 1);
        add(1, n, 1, f3[x] + 1, f2[x], -1);
        add(1, n, 1, 1, f3[x], 1);
        f3[x] = f2[x];
        f2[x] = f1[x];
        f1[x] = i;
        ans += f[1].sum;
    }
    printf("%lld\n", ans);
    return 0;
}