#include <bits/stdc++.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        std::vector<int> x(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &x[i]);
        }
        std::set<int> lengths;
        for (int i = 0; i < n; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                lengths.insert(x[j] - x[i]);
            }
        }
        printf("%d\n", static_cast<int>(lengths.size()));
    }
}