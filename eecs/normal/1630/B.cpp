#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, K, a[maxn], b[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &K);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        copy(a + 1, a + n + 1, b + 1);
        sort(b + 1, b + n + 1);
        // num >= n - num + K
        // 2 * num >= n + K
        int num = (n + K + 1) / 2;
        int mn = INT_MAX, x, y;
        for (int i = 1; i + num - 1 <= n; i++) {
            if (b[i + num - 1] - b[i] < mn) {
                mn = b[i + num - 1] - b[i];
                x = b[i], y = b[i + num - 1];
            }
        }
        printf("%d %d\n", x, y);
        for (int i = 1; i <= n; i++) {
            if (K == 1) { printf("%d %d\n", i, n); break; }
            K--;
            int j = i, s = 0;
            while (s <= 0) {
                if (a[j] >= x && a[j] <= y) s++;
                else s--;
                j++;
            }
            printf("%d %d\n", i, j - 1);
            i = j - 1;
        }
    }
    return 0;
}