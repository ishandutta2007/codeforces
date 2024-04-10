#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, cnt[26];
char s[maxn];

int main() {
    scanf("%d", &T);
    auto solve = [&]() {
        for (int i = 0; i < 26; i++) if (cnt[i] == n) {
            while (n--) putchar('a' + i);
            return;
        }
        for (int i = 0; i < 26; i++) if (cnt[i] == 1) {
            putchar('a' + i);
            for (int j = 0; j < 26; j++) if (i ^ j) {
                while (cnt[j]--) putchar('a' + j);
            }
            return;
        }
        int fir = -1, sec = -1;
        for (int i = 0; i < 26; i++) if (cnt[i]) {
            if (!~fir) fir = i;
            else if (!~sec) sec = i;
        }
        if (n - cnt[fir] >= cnt[fir] - 2) {
            putchar('a' + fir), cnt[fir]--;
            int cur = 0;
            for (int i = 1; i < n; i++, cur ^= 1) {
                if (!cur && !cnt[fir]) cur = 1;
                if (!cur) {
                    putchar('a' + fir), cnt[fir]--;
                } else {
                    for (int j = fir + 1; j < 26; j++) if (cnt[j]) {
                        putchar('a' + j), cnt[j]--; break;
                    }
                }
            }
        } else {
            if (cnt[fir] + cnt[sec] == n) {
                putchar('a' + fir), cnt[fir]--;
                while (cnt[sec]--) putchar('a' + sec);
                while (cnt[fir]--) putchar('a' + fir);
            } else {
                putchar('a' + fir), cnt[fir]--;
                putchar('a' + sec), cnt[sec]--;
                while (cnt[fir]--) putchar('a' + fir);
                for (int j = sec + 1; j < 26; j++) if (cnt[j]) {
                    putchar('a' + j), cnt[j]--; break;
                }
                for (int j = fir + 1; j < 26; j++) {
                    while (cnt[j]--) putchar('a' + j);
                }
            }
        }
    };
    while (T--) {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            cnt[s[i] - 'a']++;
        }
        solve(), putchar('\n');
    }
    return 0;
}