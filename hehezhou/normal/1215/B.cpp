#include <bits/stdc++.h>
using namespace std;
int a[200010], s[200010], n;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i), a[i] /= abs(a[i]);
    s[0] = 1;
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] * a[i];
    }
    int cnt = 1;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == 1) ans += cnt, cnt++;
        else ans += i - cnt;
    }
    return cout << 1ll * n * (n + 1) / 2 - ans << ' ' << ans << endl, 0;
}