#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        vector<tuple<int, int, int>> ans;
        for (int i = 1; i <= n; i += 2) {
            int x = i, y = i + 1;
            for (int k = 0; k < 6; k++) {
                if (9 >> k & 1) ans.emplace_back(1, x, y);
                else ans.emplace_back(2, x, y);
            }
        }
        printf("%d\n", ans.size());
        for (auto p : ans) {
            printf("%d %d %d\n", get<0>(p), get<1>(p), get<2>(p));
        }
    }
    return 0;
}