#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int sum1[1010], sum2[1010], cnt1[1010], cnt2[1010], k;
int n, m;
inline int power(int a, int b) {
    long long res = a, ans = 1;
    for(; b; b >>= 1, res = res * res % mod) if(b & 1) ans = ans * res % mod;
    return ans;
}
int main() {
/*
    scanf("%d%d", &n, &m);
    if((n ^ m) & 1) return puts("0"), 0;
    for(int d, i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            scanf("%d", &d);
            if(d) sum1[i]++, sum2[j]++;
            if(d == -1) cnt1[i] ^= 1, cnt2[j] ^= 1;
        }
*/
    scanf("%d%d", &n, &m);
    if((n ^ m) & 1) return puts("0"), 0;
    scanf("%d", &k);
    for(int i = 1, x, y, d; i <= k; i++) {
        scanf("%d%d%d", &x, &y, &d);
        sum1[x]++, sum2[y]++;
        if(d == -1) cnt1[x] ^= 1, cnt2[y] ^= 1;
    }
    scanf("%d", &mod);
    int ans = 1;
    for(int i = 1; i <= n; i++) if(sum1[i] == m) ans = ans * cnt1[i];
    for(int i = 1; i <= m; i++) if(sum2[i] == n) ans = ans * cnt2[i];
    if(n > m) {
        int flag = 0;
        for(int i = 1; i <= n; i++) {
            if(sum1[i] == 0 && flag == 0) flag = 1;
            else if(sum1[i] == m) ans = ans * cnt1[i];
            else ans = 1ll * ans * power(2, m - sum1[i] - 1) % mod;
        }
    }
    else {
        int flag = 0;
        for(int i = 1; i <= m; i++) {
            if(sum2[i] == 0 && flag == 0) flag = 1;
            else if(sum2[i] == n) ans = ans * cnt2[i];
            else ans = 1ll * ans * power(2, n - sum2[i] - 1) % mod;
        }
    }
    return cout << ans << endl, 0;
}