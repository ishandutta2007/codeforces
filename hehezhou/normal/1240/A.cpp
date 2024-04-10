#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n, p[200010];
ll k;
int x, y, a, b;
inline int check(int m) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= m; i++) {
        if (i % a == 0 && i % b == 0) cnt0++;
        else if (i % a == 0) cnt1++;
        else if (i % b == 0) cnt2++;
    }
    ll qwq = 0;
    for (int i = 1; i <= cnt0; i++) qwq += p[i] * (x + y);
    for (int i = cnt0 + 1; i <= cnt0 + cnt1; i++) qwq += p[i] * x;
    for (int i = cnt0 + cnt1 + 1; i <= cnt0 + cnt1 + cnt2; i++) qwq += p[i] * y;
    return qwq >= k;
}
inline void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", p + i), p[i] /= 100;
    sort(p + 1, p + 1 + n, greater < int > ());
    scanf("%d%d%d%d", &x, &a, &y, &b);
    if (x < y) swap(x, y), swap(a, b);
    scanf("%lld", &k);
    int L = 1, R = n, ans = -1;
    while (L <= R) {
        int mid = L + R >> 1;
        if (check(mid)) ans = mid, R = mid - 1;
        else L = mid + 1;
    }
    printf("%d\n", ans);
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}