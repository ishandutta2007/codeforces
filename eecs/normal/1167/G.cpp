#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, d, m, a[maxn];
bitset<7010> L, R;

int main() {
    scanf("%d %d", &n, &d), d++;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    int i = 1, j = 1, lst = 0;
    while (m--) {
        int x;
        scanf("%d", &x);
        L <<= x - lst;
        for (; i <= n && a[i] < x; i++) {
            if (x - a[i] <= d) L[x - a[i] - 1] = 1;
        }
        R >>= x - lst;
        for (; j <= n && a[j] < x + d; j++) {
            if (a[j] >= x) R[a[j] - x] = 1;
        }
        lst = x;
        auto cand = (L | L << 1) & (R | R << 1);
        printf("%.12f\n", max(atan2(1, min(L._Find_first(), R._Find_first())),
            atan2(1, cand._Find_first()) * 2));
    }
    return 0;
}