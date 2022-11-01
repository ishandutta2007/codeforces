#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 1e5 + 5, S = 1e6 + 5;

int n, q, a[N], tot;

LL s[N], d[S];

void inline work(int l, int r) {
    d[++tot] = s[r] - s[l - 1];
    if (a[l] == a[r]) return;
    int mid = (a[l] + a[r]) >> 1;
    int pos = upper_bound(a + 1, a + 1 + n, mid) - a;
    work(l, pos - 1), work(pos, r);
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        tot = 0;
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
        work(1, n);
        sort(d + 1, d + 1 + tot);
        while (q--) {
            int t; scanf("%d", &t);
            int pos = lower_bound(d + 1, d + 1 + tot, t) - d;
            puts(pos >= 1 && pos <= tot && d[pos] == t ? "Yes" : "No");
        }
    }   
    return 0;
}