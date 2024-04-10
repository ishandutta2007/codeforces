#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn], nxt[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = n - 1; ~i; i--) {
            nxt[i] = min(n - 1, i + 1);
            if (i + 1 < n && a[i] == a[i + 1]) nxt[i] = nxt[i + 1];
        }
        sort(a, a + n);
        int ans = 2;
        for (int i = 0; i + 1 < n; i++) {
            int cur = nxt[i], cnt = cur - i + 1;
            while (cur < n) {
                int j = lower_bound(a + cur + 1, a + n, a[cur] + a[cur] - a[i]) - a;
                if (j >= n) break;
                cur = j, cnt++;
            }
            ans = max(ans, cnt);
        }
        printf("%d\n", n - ans);
    }
    return 0;
}