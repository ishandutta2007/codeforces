#include <bits/stdc++.h>
using namespace std;

int w, n, m, cnt[1 << 12], pw[12], coef[531441];
int foo[2][6], mp[1 << 6][46656], num[46656][6];
bool chk[1 << 6][46656];
char s[15];

int main() {
    scanf("%d %d %d", &w, &n, &m), w = 12;
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x), cnt[x]++;
    }
    for (int i = pw[0] = 1; i < w; i++) {
        pw[i] = 3 * pw[i - 1];
    }
    function<void(int, int, int)> dfs = [&](int i, int id, int take) {
        if (i == w) { coef[id] += cnt[take]; return; }
        dfs(i + 1, id, take);
        dfs(i + 1, id + pw[i], take | (1 << i));
        dfs(i + 1, id + 2 * pw[i], take);
        dfs(i + 1, id + 2 * pw[i], take | (1 << i));
    };
    dfs(0, 0, 0);
    for (int i = 0; i < 46656; i++) {
        int k = i;
        for (int j = 5; ~j; j--) {
            num[i][j] = k % 6, k /= 6;
        }
    }

    foo[0][0] = 2; // 0, A
    foo[1][0] = 0; // 1, A

    foo[0][1] = 0; // 0, O

    foo[0][2] = 0; // 0, X
    foo[1][2] = 1; // 1, X

    foo[1][3] = 1; // 1, a

    foo[0][4] = 1; // 0, o
    foo[1][4] = 2; // 1, o

    foo[0][5] = 1; // 0, x
    foo[1][5] = 0; // 1, x

    for (int i = 0; i < 1 << 6; i++) {
        for (int j = 0; j < 46656; j++) {
            chk[i][j] = 1;
            for (int k = 0; k < 6; k++) {
                mp[i][j] += foo[i >> k & 1][num[j][k]] * pw[k];
                if ((i >> k & 1) == 1 && num[j][k] == 1) chk[i][j] = 0;
                if ((i >> k & 1) == 0 && num[j][k] == 3) chk[i][j] = 0;
            }
        }
    }
    while (m--) {
        scanf("%s", s);
        int tmp = strlen(s);
        reverse(s, s + tmp);
        for (int i = tmp; i < w; i++) s[i] = 'A';
        int ans = 0, L = 0, R = 0;
        for (int i = 0; i < w; i++) {
            int t;
            if (s[i] == 'A') t = 0;
            if (s[i] == 'O') t = 1;
            if (s[i] == 'X') t = 2;
            if (s[i] == 'a') t = 3;
            if (s[i] == 'o') t = 4;
            if (s[i] == 'x') t = 5;
            if (i < 6) L = L * 6 + t;
            else R = R * 6 + t;
        }
        for (int i = 0; i < 1 << w; i++) {
            if (!chk[i & 63][L] || !chk[i >> 6][R]) continue;
            ans += cnt[i] * coef[mp[i & 63][L] + mp[i >> 6][R] * pw[6]];
        }
        printf("%d\n", ans);
    }
    return 0;
}