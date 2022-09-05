#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, m, mn[maxn][maxn], a[maxn], d1[maxn], d2[maxn];
char s[maxn][maxn];
long long ans;

int main() {
    scanf("%d %d", &n, &m);
    n++, m++;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    memset(mn, 0x3f, sizeof(mn));
    for (int i = 1; i <= n; i++) {
        for (int j = 1, lst = 0; j <= m; j++) {
            if (s[i][j] == '1') lst = j;
            if (lst) mn[i][j] = (j - lst) * (j - lst);
        }
        for (int j = m, lst = 0; j; j--) {
            if (s[i][j] == '1') lst = j;
            if (lst) mn[i][j] = min(mn[i][j], (j - lst) * (j - lst));
        }
    }
    auto solve = [&](int d[maxn]) {
        for (int i = 1; i <= n; i++) a[i] += i * i;
        auto slope = [&](int i, int j) { return 1.0 * (a[i] - a[j]) / (i - j); };
        auto calc = [&](int i, int k) { return k * i + a[i]; };
        deque<int> Q;
        for (int i = 1; i <= n; i++) {
            while (Q.size() > 1 && slope(Q[Q.size() - 2], Q.back()) > slope(Q.back(), i)) Q.pop_back();
            Q.push_back(i);
            while (Q.size() > 1 && calc(Q[0], -2 * i) > calc(Q[1], -2 * i)) Q.pop_front();
            d[i] = calc(Q[0], -2 * i) + i * i;
        }
        for (int i = 1; i <= n; i++) a[i] -= i * i;
    };
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) a[j] = mn[j][i];
        solve(d1);
        reverse(a + 1, a + n + 1), solve(d2);
        for (int j = 1; j <= n; j++) ans += min(d1[j], d2[n - j + 1]);
    }
    printf("%lld\n", ans);
    return 0;
}