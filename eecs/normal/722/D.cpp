#include <bits/stdc++.h>
using namespace std;

const int maxn = 50010;
int n, y[maxn];
unordered_set<int> S;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &y[i]);
    }
    sort(y + 1, y + n + 1, greater<>());
    auto chk = [&](int lim) {
        S.clear();
        for (int i = 1; i <= n; i++) {
            int x = y[i];
            bool flag = 0;
            for (; x; x /= 2) {
                if (x <= lim && !S.count(x)) {
                    S.insert(x), flag = 1; break;
                }
            }
            if (!flag) return 0;
        }
        return 1;
    };
    int l = 0, r = 1e9, ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        chk(mid) ? r = (ans = mid) - 1 : l = mid + 1;
    }
    chk(ans);
    for (int x : S) printf("%d ", x);
    return 0;
}