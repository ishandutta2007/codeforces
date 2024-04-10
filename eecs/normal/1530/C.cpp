#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn], b[maxn], _a[maxn], _b[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
        }
        copy(a + 1, a + n + 1, _a + 1);
        copy(b + 1, b + n + 1, _b + 1);
        int l = 0, r = n, ans;
        while (l <= r) {
            int mid = (l + r) >> 1;
            for (int i = n + 1; i <= n + mid; i++) a[i] = 100;
            for (int i = n + 1; i <= n + mid; i++) b[i] = 0;
            sort(a + 1, a + n + mid + 1, greater<int>()), sort(b + 1, b + n + mid + 1, greater<int>());
            int s1 = 0, s2 = 0;
            for (int i = 1; i <= n + mid - (n + mid) / 4; i++) s1 += a[i], s2 += b[i];
            if (s1 >= s2) r = (ans = mid) - 1;
            else l = mid + 1;
            copy(_a + 1, _a + n + 1, a + 1);
            copy(_b + 1, _b + n + 1, b + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}