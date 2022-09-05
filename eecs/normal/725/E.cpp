#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int C, n, a[maxn];
ll sum[maxn];

int main() {
    scanf("%d %d", &C, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= C; i++) {
        int x = C, j = n;
        bool flag = 1;
        while (x) {
            if (a[j] > x) j = upper_bound(a + 1, a + n + 1, x) - a - 1;
            if (i >= a[j] && x >= i && flag) { x -= i, flag = 0; continue; }
            if (!j) printf("%d\n", i), exit(0);
            int l = 1, r = j, p;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (flag && a[mid] <= i && x >= i) { l = mid + 1; continue; }
                if (sum[j] - sum[mid - 1] <= x) r = (p = mid) - 1;
                else l = mid + 1;
            }
            x -= sum[j] - sum[p - 1], j = p - 1;
        }
    }
    puts("Greed is good");
    return 0;
}