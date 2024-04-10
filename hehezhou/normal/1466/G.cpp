#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
inline int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
int n, q, l;
string s[100];
int cnt;
char t[100010], S[1000010];
int sum[100010][26];
int nxt[1000010];
inline void build() {
    nxt[0] = -1;
    for (int i = 0, j = -1; i < l; ) {
        if (j == -1 || S[i + 1] == S[j + 1]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}
inline int calc(const char *s, int n) {
    int ans = 0;
    for (int i = 0, j = 0; i < n; ) {
        if (j == -1 || s[i] == S[j + 1]) i++, j++, ans += j == l;
        else j = nxt[j];
    }
    return ans;
}
char tmp[2000010];
int pwinv2[100010];
int main() {
    scanf("%d%d", &n, &q);
    cin >> s[0];
    scanf("%s", t + 1);
    for (cnt = 0; s[cnt].length() < 10000000; cnt++) s[cnt + 1] = s[cnt] + t[cnt + 1] + s[cnt];
    pwinv2[0] = 1;
    for (int i = 1; i <= n; i++) {
        memcpy(sum[i], sum[i - 1], sizeof sum[i]);
        pwinv2[i] = 1ll * pwinv2[i - 1] * (mod + 1) / 2 % mod;
        if (i > cnt) sum[i][t[i] - 'a'] = (sum[i][t[i] - 'a'] + pwinv2[i]) % mod;
    }
    for (int i = 1; i <= q; i++) {
        int k;
        scanf("%d", &k);
        scanf("%s", S + 1);
        l = strlen(S + 1);
        build();
        int ans = calc(s[0].data(), s[0].length());
        int cur = 0;
        for (int j = 0; j < cnt && j < k; j++) {
            cur = 0;
            for (int d = 0; d < l - 1 && d < s[j].size(); d++) tmp[cur++] = s[j][s[j].size() - d - 1];
            reverse(tmp, tmp + cur);
            tmp[cur++] = t[j + 1];
            for (int d = 0; d < l - 1 && d < s[j].size(); d++) tmp[cur++] = s[j][d];
            ans = (ans + 1ll * pwinv2[j + 1] * calc(tmp, cur)) % mod;
        }
        cur = 0;
        for (int d = 0; d < l - 1; d++) tmp[cur++] = s[cnt][s[cnt].size() - d - 1];
        reverse(tmp, tmp + cur);
        cur++;
        for (int d = 0; d < l - 1; d++) tmp[cur++] = s[cnt][d];
        for (int c = 0; c < 26; c++) if (sum[k][c]) {
            tmp[l - 1] = c + 'a';
            ans = (ans + 1ll * sum[k][c] * calc(tmp, cur)) % mod;
        }
        ans = 1ll * ans * power(2, k) % mod;
        printf("%d\n", ans);
    }
}