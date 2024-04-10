#include <bits/stdc++.h>
#pragma GCC optimize("Ofast","-funroll-loops")
#pragma GCC target("sse4.1","sse4.2","ssse3","sse3","sse2","sse","avx2","avx","popcnt","tune=native")
using namespace std;
const int mod = 998244353;
typedef long long ll;
int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
int pw[100010];
int n, m;
int a[100010], tag[100010];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= m; i++) {
        int p;
        scanf("%d", &p);
        tag[p] = 1;
    }
    for (int i = 1; i <= m; i++) pw[i] = (pw[i - 1] * 2 + 1) % mod;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll sum = 0;
        int cur = m - tag[i];
        if (i * 2 <= n) {
            for (int j = 1; j < i; j++) {
                sum += pw[cur];
                cur -= tag[i - j];
                cur -= tag[i + j];
            }
            for (int j = i; j <= n - i; j++) {
                sum += pw[cur];
                cur -= tag[i + j];
            }
        }
        else {
            for (int j = 1; j <= n - i; j++) {
                sum += pw[cur];
                cur -= tag[i - j];
                cur -= tag[i + j];
            }
            for (int j = n - i + 1; j <= i - 1; j++) {
                sum += pw[cur];
                cur -= tag[i - j];
            }
        }
        ans = (ans + sum % mod * a[i]) % mod;
    }
    ans = 1ll * ans * power(pw[m], mod - 2) % mod;
    cout << ans << endl;
}