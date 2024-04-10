#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6;
long long c[N], a[N];
int n;
long long da, db;
void upd(long long x, int v) {
    if (x > 0)
        da += x * v;
    else
        db -= x * v;
}
long long work(long long da, long long db, long long s, long long t) {
    return (da + s + 1) >> 1;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &c[i]);
        a[i] = c[i];
    }
    for (int i = 1; i < n; i ++) {
        c[i] = c[i + 1] - c[i];
        upd(c[i], 1);
    }
    printf("%lld\n", work(da, db, a[1], a[n]));
    int m;
    scanf("%d", &m);
    while (m --) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        if (l > 1) {
            upd(c[l - 1], -1);
            upd(c[l - 1] += x, 1);
        } else {
            a[1] += x;
        }
        if (r < n) {
            upd(c[r], -1);
            upd(c[r] -= x, 1);
        } else {
            if (n != 1)
                a[n] += x;
        }
        printf("%lld\n", work(da, db, a[1], a[n]));
    }
    return 0;
}