#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
inline int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
int T, n, m;
inline void rmain() {
    scanf("%d%d", &n, &m);
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%*d%*d%d", &x);
        sum |= x;
    }
    printf("%lld\n", 1ll * sum * power(2, n - 1) % mod);
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}