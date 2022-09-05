#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, cl[maxn], cr[maxn], L[maxn], R[maxn], pre[maxn][26], nxt[maxn][26];
int num, cnt[maxn], fl[20][maxn], fr[20][maxn], mxr[maxn], s[maxn];
char str[maxn];
ll ans, sl[20][maxn], sr[20][maxn];

int main() {
    scanf("%s", str + 1), n = strlen(str + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = str[i] - 'a', cl[i] = cr[i] = i;
    }
    for (int i = 0; i < 26; i++) {
        pre[0][i] = 1, nxt[n + 1][i] = n;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) pre[i][j] = pre[i - 1][j];
        L[i] = pre[i][s[i]], pre[i][s[i]] = i;
    }
    for (int i = n; i; i--) {
        for (int j = 0; j < 26; j++) nxt[i][j] = nxt[i + 1][j];
        R[i] = nxt[i][s[i]], nxt[i][s[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        sort(pre[i], pre[i] + 26), sort(nxt[i], nxt[i] + 26);
        fl[0][i] = n;
    }
    for (int t = 1; t <= 26; t++) {
        for (int i = 1; i <= n; i++) {
            fl[0][i] = min(fl[0][i], L[nxt[i][t - 1]]);
            fr[0][i] = max(fr[0][i], R[pre[i][26 - t]]);
            sl[0][i] = i - 1, sr[0][i] = n - i;
        }
        for (int j = 1; j < 18; j++) {
            for (int i = 1; i <= n; i++) {
                fl[j][i] = fl[j - 1][fl[j - 1][i]];
                fr[j][i] = fr[j - 1][fr[j - 1][i]];
                sl[j][i] = sl[j - 1][i] + sl[j - 1][fl[j - 1][i]];
                sr[j][i] = sr[j - 1][i] + sr[j - 1][fr[j - 1][i]];
            }
        }
        for (int i = 1, j = 1; i <= n; i++) {
            while (j <= n && num + !cnt[s[j]] <= t) num += !cnt[s[j]]++, ++j;
            mxr[i] = j - 1;
            num -= !--cnt[s[i]];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 17; ~j; j--) {
                if (mxr[fl[j][cl[i]]] >= fr[j][cr[i]]) {
                    ans += sl[j][cl[i]] + sr[j][cr[i]];
                    cl[i] = fl[j][cl[i]], cr[i] = fr[j][cr[i]];
                }
            }
            if (mxr[cl[i]] >= cr[i]) {
                ans += sl[0][cl[i]] + sr[0][cr[i]];
                cl[i] = fl[0][cl[i]], cr[i] = fr[0][cr[i]];
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}