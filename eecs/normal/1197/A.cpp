#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, a[maxn];

bool chk(int x) {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt1 < 2 && a[i] >= x + 1) cnt1++;
        else cnt2++;
    }
    return cnt1 == 2 && cnt2 >= x;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int l = 0, r = n, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            chk(mid) ? l = (ans = mid) + 1 : r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}