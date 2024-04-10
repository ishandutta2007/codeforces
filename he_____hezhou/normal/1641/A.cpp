#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int a[200010];
void rmain() {
    multiset < ll > s;
    int n, x;
    scanf("%d%d", &n, &x);
    int ans = n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + 1 + n);
    for (int i = n; i > 0; i--) {
        ll cur = 1ll * a[i] * x;
        if (s.count(cur)) s.erase(s.lower_bound(cur)), ans -= 2;
        else s.insert(a[i]);
    }
    printf("%d\n", ans);
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}