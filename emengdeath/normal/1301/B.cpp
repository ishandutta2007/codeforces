#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e6;
int t, n;
int a[N];
int ans, ansx;
void update(int&l, int &r, int ll, int rr) {
    l = max(l ,ll);
    r = min(r, rr);
}
pair<int, int> check(int x) {
    int l = 0, r = 1e9;
    for (int i = 1; i <= n; i ++) {
        if (a[i] == - 1&& i != 1 && a[i - 1] != -1) {
            update(l, r, a[i - 1] - x, a[i - 1] + x);
        }

        if (a[i] == - 1&& i != n && a[i + 1] != -1) {
            update(l, r, a[i + 1] - x, a[i +1] + x);
        }
    }
    return make_pair(l, r);
}
int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i= 1; i<= n; i ++)
            scanf("%d", &a[i]);
        int org = 0;
        for (int i = 1; i <= n; i ++) {
            if (i != 1 && a[i] != -1 && a[i - 1] != -1)
                org = max(org, abs(a[i] - a[i- 1]));
        }
        ans = 2e9;
        int l = org, r = 1e9, mid;
        while (l <= r) {
            auto u=check(mid = (l+ r) / 2);
            if (u.first <= u.second) {
                if (ans > mid) ans = mid, ansx = u.first;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        printf("%d %d\n", ans, ansx);
    }
    return 0;
}