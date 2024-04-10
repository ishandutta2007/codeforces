#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn], b[maxn];
vector<int> V[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &a[i], &b[i]);
        }
        auto chk = [&](int lim) {
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                int l = max(1, lim - a[i]), r = min(lim, b[i] + 1);
                if (cnt + 1 >= l && cnt + 1 <= r) cnt++;
            }
            return cnt >= lim;
        };
        int l = 1, r = n, ans;
        while (l <= r) {
            int mid = (l + r) / 2;
            chk(mid) ? l = (ans = mid) + 1 : r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}