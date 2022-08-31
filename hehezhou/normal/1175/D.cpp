#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll a[300010];
ll st[300010][20];
int lg2[300010];
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%I64d", a + i);
    }
    for(int i = n; i >= 1; i--) a[i] += a[i + 1];
    ll ans = a[1];
    sort(a + 2, a + 1 + n);
    for(int i = 1; i < k; i++) ans += a[n + 1 - i];
    return cout << ans << endl, 0;
}