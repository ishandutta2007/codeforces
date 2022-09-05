#include <bits/stdc++.h>
using namespace std;

const int maxn = 600010;
int m, n, p[maxn];
pair<int, int> a[maxn], b[maxn];

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].first), a[i].second = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i].first), b[i].second = i;
        b[i + n] = make_pair(b[i].first + m, i);
        b[i + n * 2] = make_pair(b[i].first - m, i);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + 3 * n + 1);
    auto chk = [&](int x) {
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += abs(a[i].first - b[i + x - 1].first);
        }
        return sum;
    };
    int l = 1, r = 2 * n, ans = 2 * n + 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid) < chk(mid + 1) ? r = (ans = mid) - 1 : l = mid + 1;
    }
    printf("%lld\n", chk(ans));
    for (int i = 1; i <= n; i++) {
        p[a[i].second] = b[i + ans - 1].second;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", p[i]);
    }
    return 0;
}