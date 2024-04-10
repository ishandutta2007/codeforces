#include <bits/stdc++.h>
using namespace std;

const int maxn = 150010;
int T, n, a[maxn], mp[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        auto chk = [&](int len) {
            for (int i = 1; i <= n; i++) {
                mp[a[i]] = 0;
            }
            for (int i = 1; i <= n; i++) {
                if (mp[a[i]]) {
                    int pos = mp[a[i]];
                    int l = max(1, pos - len + 1);
                    int r = i - (pos - l);
                    if (r + len - 1 <= n) return 1;
                }
                mp[a[i]] = i;
            }
            return 0;
        };
        int l = 1, r = n, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            chk(mid) ? l = (ans = mid) + 1 : r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}