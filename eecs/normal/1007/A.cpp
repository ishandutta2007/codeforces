#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    auto chk = [&](int x) {
        for (int i = 1; i <= x; i++) {
            if (a[i] >= a[n - x + i]) return 0;
        }
        return 1;
    };
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid) ? l = (ans = mid) + 1 : r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}