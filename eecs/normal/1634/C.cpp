#include <bits/stdc++.h>
using namespace std;

int T, n, K;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &K);
        vector<int> odd, even;
        for (int i = 1; i <= n * K; i++) {
            (i % 2 ? odd : even).push_back(i);
        }
        if (K == 1) {
            puts("YES");
            for (int i = 1; i <= n; i++) {
                printf("%d\n", i);
            }
        } else if (odd.size() % K) {
            puts("NO");
        } else {
            puts("YES");
            for (int i = 1; i <= n; i++) {
                if (!odd.empty()) {
                    for (int j = 0; j < K; j++) {
                        printf("%d ", odd.back()), odd.pop_back();
                    }
                } else {
                    for (int j = 0; j < K; j++) {
                        printf("%d ", even.back()), even.pop_back();
                    }
                }
                putchar('\n');
            }
        }
    }
    return 0;
}