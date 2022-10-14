#include <bits/stdc++.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n, l, r, k;
        scanf("%d%d%d%d", &n, &l, &r, &k);
        std::vector<int> a;
        a.reserve(n);
        for (int i = 0, x; i < n; ++ i) {
            scanf("%d", &x);
            if (l <= x && x <= r) {
                a.push_back(x);
            }
        }
        std::sort(a.begin(), a.end());
        int result = 0;
        while (result < static_cast<int>(a.size()) && a[result] <= k) {
            k -= a[result ++];
        }
        printf("%d\n", result);
    }
}