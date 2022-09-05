#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, l[maxn], suf[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &l[i]);
        if (i + l[i] - 1 > n) printf("-1\n"), exit(0);
    }
    for (int i = m; i; i--) {
        suf[i] = min(n, suf[i + 1] + l[i]);
    }
    if (suf[1] < n) printf("-1\n"), exit(0);
    for (int i = 1; i <= m; i++) {
        printf("%d ", max(i, n - suf[i] + 1));
    }
    return 0;
}