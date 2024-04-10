#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, p[maxn], c[maxn];

void add(int x) {
    for (; x <= n; x += x & -x) c[x]++;
}

int query(int x) {
    int s = 0;
    for (; x; x -= x & -x) s += c[x];
    return s;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1, x; i <= n; i++) {
            scanf("%d", &x), p[x] = i;
        }
        fill(c + 1, c + n + 1, 0);
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            int v = query(p[i + 1]) - query(p[i]);
            if (p[i] > p[i + 1]) v += i - 1;
            ans += 1LL * v * (n - i), add(p[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}