#include <bits/stdc++.h>
using namespace std;
int T;
int n, m;
char s[510][510];
inline void rmain() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        if (i % 3 == 1 || n == 1) {
            for (int j = 0; j < m; j++) s[i][j] = 'X';
        }
    }
    for (int i = 2; i + 2 < n; i += 3) {
        int tag1 = -1, tag2 = 0;
        for (int j = 0; j < m; j++) if (s[i][j] == 'X') tag1 = j;
        for (int j = 0; j < m; j++) if (s[i + 1][j] == 'X') tag2 = j;
        if (tag1 != -1) s[i + 1][tag1] = 'X';
        else s[i][tag2] = s[i + 1][tag2] = 'X';
    }
    if (n % 3 == 1 && n != 1) {
        for (int j = 0; j < m; j++) if (s[n - 1][j] == 'X') s[n - 2][j] = 'X';
    }
    for (int i = 0; i < n; i++) puts(s[i]);
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}