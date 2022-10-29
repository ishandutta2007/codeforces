#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int f[1001][1001][26];
char s[N], t[N];
int lens, lent;
int ans;
const int p = 998244353;
int add(int x, int y) {
    x += y;
    return x >= p ? x - p : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x + p : x;
}
int mul(int x, int y) {
    return 1ll * x * y % p;
}
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) 
            z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}
int inv(int x) {
    return calc(x, p - 2);
}
void work(char * s, int len, int v) {
    int l = 1;
    for (int i = 2; i <= len; i ++) {
        if (s[i] == s[i - 1]) {
            ans = sub(ans, mul(1ll * (i - l + 1) * (i - l) / 2 % p, v));
            l = i;
        }
    }
    ans = sub(ans, mul(1ll * (len - l + 2) * (len - l + 1) / 2 % p, v));
}
int main() {
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    lens = strlen(s + 1);
    lent = strlen(t + 1);
    for(int i = 1; i <= lens; i ++) s[i] -= 'a';
    for (int i = 1; i <= lent; i ++) t[i] -= 'a';
    work(s, lens, lent + 1);
    work(t, lent, lens + 1);
    for (int i = 0; i <= lens; i ++)
        for (int j = 0; j <= lent; j ++) {
            for (int k = 0; k < 26; k ++)
                if (f[i][j][k]) {
                    ans = add(ans, f[i][j][k]); 
                    if (i + 1 <= lens && s[i + 1] != k)
                        f[i + 1][j][s[i + 1]] = add(f[i + 1][j][s[i + 1]], f[i][j][k]);
                    if (j + 1 <= lent && t[j + 1] != k)
                        f[i][j + 1][t[j + 1]] = add(f[i][j + 1][t[j + 1]], f[i][j][k]);
                }
            if (i != lens)
                f[i + 1][j][s[i + 1]] = add(f[i + 1][j][s[i + 1]], 1);
            if (j != lent)
                f[i][j + 1][t[j + 1]] = add(f[i][j + 1][t[j + 1]], 1);
        }
    printf("%d\n", ans);
    return 0;
}