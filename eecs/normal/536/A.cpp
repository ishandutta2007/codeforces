#include <bits/stdc++.h>
using namespace std;

int A, B, n;

int main() {
    scanf("%d %d %d", &A, &B, &n);
    auto sum = [&](int l, int r) {
        return 1LL * (l + r) * (r - l + 1) / 2;
    };
    while (n--) {
        int l, t, m;
        scanf("%d %d %d", &l, &t, &m);
        int lb = l, rb = 2e6, ans = -1;
        while (lb <= rb) {
            int mid = (lb + rb) >> 1;
            long long mx = A + 1LL * (mid - 1) * B;
            long long s = 1LL * A * (mid - l + 1) + 1LL * B * sum(l - 1, mid - 1);
            if (mx <= t && s <= 1LL * t * m) lb = (ans = mid) + 1;
            else rb = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}