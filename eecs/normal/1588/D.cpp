#include <bits/stdc++.h>
using namespace std;

int T, n, a[110], cnt[55], id[10][110], pos[10][55][2];
int f[55][1 << 10], nxt[10][110][55];
pair<int, int> pre[55][1 << 10];
bool inq[55][1 << 20];
char s[110];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", s + 1);
            memset(nxt[i], -1, sizeof(nxt[i]));
            int len = strlen(s + 1);
            memset(cnt, 0, sizeof(cnt));
            for (int j = 1; j <= len; j++) {
                if (s[j] >= 'a' && s[j] <= 'z') a[j] = s[j] - 'a';
                else a[j] = s[j] - 'A' + 26;
                id[i][j] = cnt[a[j]], pos[i][a[j]][cnt[a[j]]++] = j;
            }
            for (int j = len; j; j--) {
                memcpy(nxt[i][j], nxt[i][j + 1], sizeof(nxt[i][j]));
                nxt[i][j][a[j]] = j;
            }
        }
        memset(f, -1, sizeof(f));
        queue<pair<int, int>> Q;
        Q.emplace(52, 0), f[52][0] = 0;
        while (!Q.empty()) {
            int c = Q.front().first, S = Q.front().second;
            Q.pop(), inq[c][S] = 0;
            for (int _c = 0; _c < 52; _c++) {
                int _S = 0;
                bool flag = 1;
                for (int i = 0; i < n; i++) {
                    int p = pos[i][c][S >> i & 1] + 1;
                    if (!~nxt[i][p][_c]) { flag = 0; break; }
                    if (id[i][nxt[i][p][_c]]) _S |= 1 << i;
                }
                if (!flag) continue;
                if (f[_c][_S] >= f[c][S] + 1) continue;
                if (!inq[_c][_S]) Q.emplace(_c, _S), inq[_c][_S] = 1;
                f[_c][_S] = f[c][S] + 1, pre[_c][_S] = {c, S};
            }
        }
        int ans = 0, fc = -1, fs = -1;
        for (int c = 0; c < 52; c++) {
            for (int S = 0; S < 1 << n; S++) if (f[c][S] > ans) {
                ans = f[c][S], fc = c, fs = S;
            }
        }
        printf("%d\n", ans);
        string str;
        if (ans) {
            while (ans) {
                if (fc < 26) str.push_back('a' + fc);
                else str.push_back('A' + fc - 26);
                int _fc = pre[fc][fs].first, _fs = pre[fc][fs].second;
                ans--, fc = _fc, fs = _fs;
            }
            reverse(str.begin(), str.end());
        }
        printf("%s\n", str.c_str());
    }
    return 0;
}