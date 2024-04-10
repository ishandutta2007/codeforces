#include <bits/stdc++.h>
using namespace std;

const int maxn = 50010;
int T, n, a[maxn][5];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 5; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        auto comp = [&](int i, int j) {
            int s = 0;
            for (int k = 0; k < 5; k++) {
                if (a[i][k] < a[j][k]) s++;
            }
            return s >= 3;
        };
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            if (!comp(ans, i)) ans = i;
        }
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            if (i ^ ans) flag &= comp(ans, i);
        }
        if (!flag) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}