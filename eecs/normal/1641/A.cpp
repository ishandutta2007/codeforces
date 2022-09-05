#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, x, a[maxn];
bool del[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        set<pair<int, int>> S;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            S.emplace(a[i], i);
        }
        fill(del + 1, del + n + 1, 0);
        int ans = n;
        for (int i = n; i; i--) if (!del[i]) {
            if (1LL * a[i] * x > INT_MAX) continue;
            auto it = S.lower_bound({a[i] * x, 0});
            if (it != S.end() && it->first == a[i] * x) {
                ans -= 2;
                del[i] = del[it->second] = 1, S.erase(it);
                S.erase({a[i], i});
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}