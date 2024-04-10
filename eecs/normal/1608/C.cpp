#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, ans[maxn];
array<int, 2> a[maxn], b[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i][0]), a[i][1] = i;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i][0]), b[i][1] = i;
        }
        sort(a + 1, a + n + 1, greater<>());
        sort(b + 1, b + n + 1, greater<>());
        fill(ans + 1, ans + n + 1, 0);
        set<int> S;
        for (int i = 1; i <= n; i++) {
            S.insert(a[i][1]), S.insert(b[i][1]);
            if (S.size() == i) {
                for (int x : S) ans[x] = 1;
                break;
            }
        }
        for (int i = 1; i <= n; i++) putchar(ans[i] + '0');
        putchar('\n');
    }
    return 0;
}