#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, h1[maxn], h2[maxn];
ll ans, f[maxn][2];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h1[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h2[i]);
    }
    ll mx0 = 0, mx1 = 0;
    for (int i = 1; i <= n; i++) {
        f[i][0] = h1[i] + mx1;
        f[i][1] = h2[i] + mx0;
        mx0 = max(mx0, f[i][0]);
        mx1 = max(mx1, f[i][1]);
        ans = max(ans, max(f[i][0], f[i][1]));
    }
    printf("%lld\n", ans);
    return 0;
}