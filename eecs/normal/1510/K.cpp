#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, ans = INT_MAX, a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%d", &a[i]);
    }
    auto op1 = [&]() {
        for (int i = 1; i <= 2 * n; i += 2) swap(a[i], a[i + 1]);
    };
    auto op2 = [&]() {
        for (int i = 1; i <= n; i++) swap(a[i], a[i + n]);
    };
    auto chk = [&](int x) {
        bool flag = 1;
        for (int i = 1; i <= 2 * n; i++) flag &= a[i] == i;
        if (flag) ans = min(ans, x);
    };
    function<void(int, int)> dfs = [&](int cur, int lst) {
        if (cur > 2 * n) return;
        chk(cur);
        vector<int> V(2 * n + 1);
        for (int i = 1; i <= 2 * n; i++) V[i] = a[i];
        if (lst != 0) op1(), dfs(cur + 1, 0);
        for (int i = 1; i <= 2 * n; i++) a[i] = V[i];
        if (lst != 1) op2(), dfs(cur + 1, 1);
        for (int i = 1; i <= 2 * n; i++) a[i] = V[i];
    };
    dfs(0, -1);
    printf("%d\n", ans == INT_MAX ? -1 : ans);
    return 0;
}