#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int nxt[1000010], n;
int ans[1000010];
int dp[350][33];
pair <int, int> ddp[350][33];
int realplace[350], tag[1000010];
void rmain() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int cnt = 0;
    nxt[n + 1] = n + 1;
    for (int i = n; i > 0; i--) {
        if (s[i] == '1') nxt[i] = i, cnt++;
        else nxt[i] = nxt[i + 1];
        ans[i] = 0;
    }
    if (cnt == 0) return puts("-1\n"), void();
    if (cnt > 16) {
        int tar = cnt;
        while (tar & (tar - 1)) tar++;
        int pos = nxt[1];
        int pos1 = pos;
        pos = nxt[pos + 1];
        pos = nxt[pos + 1];
        int pos2 = pos;
        pos = nxt[pos + 1];
        pos = nxt[pos + 1];
        int cur = cnt;
        if (cur + 2 >= tar) {
            if (cur != tar) ans[pos1] = 1, cur++;
            if (cur != tar) ans[pos2] = 1, cur++;
        }
        else while (1) {
            int a = s[pos + 1] - '0';
            ans[pos] = 1;
            cur += 1;
            if (cur + 2 >= tar) {
                if (cur != tar) ans[pos1] = 1, cur++;
                if (cur != tar) ans[pos2] = 1, cur++;
                break;
            }
            ans[pos + 1] = 1;
            cur += a + 2;
            if (cur + 2 >= tar) {
                if (cur != tar) ans[pos1] = 1, cur++;
                if (cur != tar) ans[pos2] = 1, cur++;
                break;
            }
            pos = nxt[pos + 3];
        }
        vector < pair <int, int> > out;
        for (int l = 1, r; l <= n; l = r + 1) {
            for (r = l; ans[r]; r++);
            out.push_back({l, r});
        }
        printf("%d\n", out.size());
        for (auto i : out) printf("%d %d\n", i.first, i.second);
        puts("");
    }
    else {
        for (int i = 1; i <= n; i++) tag[i] = 0;
        for (int i = 1; i <= n; i++) if (s[i] == '1')
            for (int j = max(1, i - 3); j <= min(n, i + 3); j++) tag[j] = 1;
        int lst = 0;
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        vector < pair <int, int> > out;
        for (int l = 1, r; l <= n; l = r + 1) {
            if (tag[l] == 0) {
                out.push_back({l, l});
                r = l;
                continue;
            }
            r = l;
            while (r < n && tag[r + 1] == 1) r++;
            int nxt = lst + r - l + 1;
            for (int i = l; i <= r; i++) realplace[lst + i - l + 1] = i;
            for (int i = lst + 1; i <= nxt; i++) {
                int sum = 0, qwq = 1;
                for (int j = i; j > lst && j > i - 5; j--) {
                    if (s[realplace[j]] == '1') sum += qwq;
                    qwq <<= 1;
                    for (int t = 0; t + sum <= 32; t++) if (dp[j - 1][t]) dp[i][t + sum] = 1, ddp[i][t + sum] = {j, t};
                }
            }
            lst = nxt;
        }
        for (int i = 1; i <= 32; i <<= 1) if (dp[lst][i]) {
            for (int x = lst, y = i; x; ) {
                auto tmp = ddp[x][y];
                out.push_back({realplace[tmp.first], realplace[x]});
                x = tmp.first - 1;
                y = tmp.second;
            }
            break;
        }
        else if (i == 32) assert(0);
        printf("%d\n", out.size());
        for (auto i : out) printf("%d %d\n", i.first, i.second);
        puts("");
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}