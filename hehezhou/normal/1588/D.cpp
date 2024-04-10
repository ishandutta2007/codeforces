#include <bits/stdc++.h>
using namespace std;
int T, n;
char s[150];
int nxt[11][150][52];
int pos[11][52][2];
int dp[52][1024];
pair < int, int > trans[52][1024];
int calc(int c, int tag) {
    if (dp[c][tag] != -1) return dp[c][tag];
    int curpos[10], topos[10];
    for (int i = 0; i < n; i++) {
        curpos[i] = pos[i][c][(tag >> i) & 1];
        if (curpos[i] == 0) return 0;
    }
    dp[c][tag] = 0;
    for (int tc = 0; tc < 52; tc++) {
        int able = 1;
        for (int i = 0; i < n; i++) {
            topos[i] = nxt[i][curpos[i]][tc];
            if (topos[i] == 0) {
                able = 0;
                break;
            }
        }
        if (able == 0) continue;
        int totag = 0;
        for (int i = 0; i < n; i++) if (topos[i] == pos[i][tc][1]) totag |= 1 << i;
        int tmp = calc(tc, totag);
        if (tmp > dp[c][tag]) dp[c][tag] = tmp, trans[c][tag] = {tc, totag};
    }
    dp[c][tag]++;
    return dp[c][tag];
}
inline void rmain() {
    scanf("%d", &n);
    memset(pos, 0, sizeof pos);
    memset(nxt, 0, sizeof nxt);
    memset(dp, -1, sizeof dp);
    memset(trans, -1, sizeof trans);
    for (int i = 0; i < n; i++) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        for (int j = 1; j <= len; j++) {
            if (s[j] >= 'a' && s[j] <= 'z') s[j] -= 'a';
            else s[j] -= 'A' - 26;
            if (pos[i][s[j]][0]) pos[i][s[j]][1] = j;
            else pos[i][s[j]][0] = j;
        }
        for (int j = len; j > 0; j--) {
            memcpy(nxt[i][j - 1], nxt[i][j], sizeof(nxt[i][j]));
            nxt[i][j - 1][s[j]] = j;
        }
    }
    int ans = 0, ansc = -1;
    for (int i = 0; i < 52; i++) {
        int tmp = calc(i, 0);
        if (tmp > ans) ans = tmp, ansc = i;
    }
    printf("%d\n", ans);
    for (int tag = 0; ansc != -1; ) {
        putchar(ansc < 26 ? ansc + 'a' : ansc - 26 + 'A');
        pair < int, int > tmp = trans[ansc][tag];
        ansc = tmp.first, tag = tmp.second;
    }
    puts("");
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}