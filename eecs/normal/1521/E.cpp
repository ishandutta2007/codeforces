#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, m, K, a[maxn], id[maxn], ans[1010][1010];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &m, &K);
        for (int i = 1; i <= K; i++) {
            scanf("%d", &a[i]), id[i] = i;
        }
        sort(id + 1, id + K + 1, [&](int x, int y) { return a[x] > a[y]; });
        int l = 0, r = 100000, n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            long long cnt = 1LL * mid * mid;
            cnt -= 1LL * (mid / 2) * (mid / 2);
            long long mx = 1LL * (mid + 1) / 2 * mid;
            if (cnt >= m && mx >= a[id[1]]) r = (n = mid) - 1;
            else l = mid + 1;
        }
        printf("%d\n", n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) ans[i][j] = 0;
        }
        for (int i = 1, p = 1; i <= n; i += 2) {
            for (int j = 2; j <= n; j += 2) {
                while (p <= K && !a[id[p]]) p++;
                if (p > K) break;
                ans[i][j] = id[p], a[id[p]]--;
            }
        }
        for (int i = 1, p = 1; i <= n; i += 2) {
            for (int j = 1; j <= n; j += 2) {
                while (p <= K && !a[id[p]]) p++;
                if (p > K) break;
                ans[i][j] = id[p], a[id[p]]--;
            }
        }
        for (int i = 2, p = 1; i <= n; i += 2) {
            for (int j = 1; j <= n; j += 2) {
                while (p <= K && !a[id[p]]) p++;
                if (p > K) break;
                ans[i][j] = id[p], a[id[p]]--;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%d%c", ans[i][j], " \n"[j == n]);
            }
        }
    }
    return 0;
}