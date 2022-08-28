#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod1 = 998244353, mod2 = 1000000007;
char ans[1000010];
int n;
char s[1000010];
int base1, base2;
int b1[1000010], b2[1000010];
int len;
int main() {
    ios :: sync_with_stdio(false);
    srand(time(0));
    cin >> n;
    base1 = rand() % mod1, base2 = rand() % mod2;
    b1[0] = b2[0] = 1;
    for(int i = 1; i <= 1000000; i++) b1[i] = 1ll * base1 * b1[i - 1] % mod1;
    for(int i = 1; i <= 1000000; i++) b2[i] = 1ll * base2 * b2[i - 1] % mod2;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        int m = strlen(s);
        int cnt = -1;
        ll d1 = 0, d2 = 0, c1 = 0, c2 = 0;
        for(int i = 0; i < min(m, len); i++) {
            c1 = (c1 * base1 + s[i]) % mod1;
            c2 = (c2 * base2 + s[i]) % mod2;
            d1 = (d1 + 1ll * ans[len - i] * b1[i]) % mod1;
            d2 = (d2 + 1ll * ans[len - i] * b2[i]) % mod2;
            if(c1 == d1 && c2 == d2) cnt = i;
        }
        for(int i = cnt + 1; i < m; i++) {
            ans[++len] = s[i];
        }
    }
    cout << ans + 1 << endl;
    return 0;
}