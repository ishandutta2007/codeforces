#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, INF = 1e9;
int L, n, a[maxn], res[maxn];
pair<int, int> f[maxn];

int main() {
    scanf("%d %d", &L, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    a[n + 1] = L;
    auto chk = [&](int x, int y) -> bool {
        if (x > y) return 0;
        f[1] = {0, 0};
        for (int i = 1; i <= n; i++) {
            if (a[i] < f[i].first || a[i] > f[i].second + y) return 0;
            f[i + 1] = {max(a[i], f[i].first + x), min(a[i + 1], f[i].second + y)};
        }
        return f[n + 1].first <= L && L <= f[n + 1].second;
    };
    int l = 0, r = INF, lb, rb;
    while (l <= r) {
        int mid = (l + r) / 2;
        chk(mid, INF) ? l = (lb = mid) + 1 : r = mid - 1;
    }
    l = 0, r = INF;
    while (l <= r) {
        int mid = (l + r) / 2;
        chk(lb, mid) ? r = (rb = mid) - 1 : l = mid + 1;
    }
    chk(lb, rb), res[n + 1] = L;
    for (int i = n; i; i--) {
        for (int x : {f[i].first, f[i].second, res[i + 1] - lb, res[i + 1] - rb}) {
            if (x <= a[i] && x <= res[i + 1] && res[i + 1] - x >= lb && res[i + 1] - x <= rb) {
                res[i] = x; break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", res[i], res[i + 1]);
    }
    return 0;
}