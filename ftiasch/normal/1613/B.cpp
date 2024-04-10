#include <bits/stdc++.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        std::vector<int> a(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a[i]);
        }
        std::sort(a.begin(), a.end());
        for (int i = 1; i < 1 + n / 2; ++ i) {
            printf("%d %d\n", a[i], a[0]);
        }
    }
}