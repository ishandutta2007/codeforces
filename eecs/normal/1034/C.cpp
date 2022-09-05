#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000010, P = 1000000007;
int n, p[maxn], cnt[maxn], f[maxn];
ll a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 2; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = n; i > 1; i--) {
        a[p[i]] += a[i];
    }
    for (int i = 1; i <= n; i++) {
        ll x = a[1] / __gcd(a[1], a[i]);
        if (x <= n) cnt[x]++;
    }
    for (int i = n; i; i--) {
        for (int j = i + i; j <= n; j += i) cnt[j] += cnt[i];
    }
    for (int i = n; i; i--) if (i == cnt[i]) {
        f[i] = 1;
        for (int j = i + i; j <= n; j += i) {
            if ((f[i] += f[j]) >= P) f[i] -= P;
        }
    }
    printf("%d\n", f[1]);
    return 0;
}