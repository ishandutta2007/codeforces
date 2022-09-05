#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, K, ans, x[maxn], fir[maxn], lst[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= K; i++) {
        scanf("%d", &x[i]);
        lst[x[i]] = i;
        if (!fir[x[i]]) fir[x[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = max(1, i - 1); j <= min(n, i + 1); j++) {
            if (!fir[i] || lst[j] < fir[i]) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}