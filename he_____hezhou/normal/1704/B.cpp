#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[200010];
void rmain() {
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int ans = 0;
    for (int l = 1, r = 1; l <= n; l = r) {
        int _min = a[l], _max = a[r];
        for (; _max - _min <= 2 * x; r++, _min = min(_min, a[r]), _max = max(_max, a[r]));
        ans++;
    }
    printf("%d\n", ans - 1);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}