#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010, U = 5000;
int n, tot = U, cnt[maxn], p[maxn], mx[maxn];
int d[maxn][maxn], tmp[maxn][maxn], num[maxn][maxn], coef[maxn];
long long ans = LLONG_MAX;

int main() {
    scanf("%d", &n);
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a), cnt[max(1, a)]++;
    }
    for (int i = 2; i <= U; i++) if (!p[i]) {
        for (int j = i; j <= U; j += i) {
            int k = j;
            while (!(k % i)) num[i][j]++, coef[j]++, k /= i;
            mx[j] = max(mx[j], i);
            if (j > i) p[j] = 1;
        }
        for (int j = 1; j <= U; j++) {
            num[i][j] += num[i][j - 1], tmp[i][j] = num[i][j];
        }
    }
    for (int i = 1; i <= U; i++) {
        for (int j = 1; j <= U; j++) num[j][i] += num[j - 1][i];
    }
    for (int i = 1; i <= U; i++) {
        for (int j = i - 1, k = 1; j >= 1; j--) {
            k = max(k, mx[j + 1]);
            d[i][j] = d[j][i] = num[k - 1][i] + num[k - 1][j] + tmp[k][i] - tmp[k][j];
        }
    }
    for (int i = 1; i <= U; i++) {
        long long sum = 0;
        for (int j = 1; j <= U; j++) {
            sum += 1LL * cnt[j] * d[i][j];
        }
        ans = min(ans, sum);
    }
    long long foo = 0;
    for (int i = 1; i <= U; i++) {
        for (int j = i + 1; j <= U; j++) {
            foo += 1LL * cnt[i] * cnt[j] * d[i][j];
        }
    }
    ans = min(ans, foo / 2);
    printf("%lld\n", ans);
    return 0;
}