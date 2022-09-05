#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010, P = 998244353;
int w, h, f[maxn][maxn][2];

int main() {
    scanf("%d %d", &w, &h);
    int ans = 1;
    while (w--) ans = 2LL * ans % P;
    while (h--) ans = 2LL * ans % P;
    printf("%d\n", ans);
    return 0;
}