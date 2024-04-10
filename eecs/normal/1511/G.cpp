#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, q, c[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    sort(c + 1, c + n + 1);
    scanf("%d", &q);
    while (q--) {
        int l, r, x = 0; scanf("%d %d", &l, &r);
        int a = lower_bound(c + 1, c + n + 1, l) - c;
        int b = upper_bound(c + 1, c + n + 1, r) - c;
        for (int i = a; i < b; i++) x ^= c[i] - l;
        putchar(x ? 'A' : 'B');
    }
    return 0;
}