#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, a[maxn];
bool vis[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    long long g = 1;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        int len = 0;
        for (int j = a[i]; !vis[j]; j = a[j]) {
            vis[j] = 1, len++;
        }
        if (!vis[i]) puts("-1"), exit(0);
        g = g / __gcd(g, 1LL * len) * len;
    }
    if (!(g & 1)) g >>= 1;
    printf("%lld\n", g);
    return 0;
}