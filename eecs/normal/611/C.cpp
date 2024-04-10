#include <bits/stdc++.h>
using namespace std;

int h, w, q, s1[510][510], s2[510][510];
char s[510][510];

int main() {
    scanf("%d %d", &h, &w);
    for (int i = 1; i <= h; i++) {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            s1[i][j] = s1[i - 1][j] + s1[i][j - 1] - s1[i - 1][j - 1] + (s[i][j]
                == '.' && s[i + 1][j] == '.');
            s2[i][j] = s2[i - 1][j] + s2[i][j - 1] - s2[i - 1][j - 1] + (s[i][j]
                == '.' && s[i][j + 1] == '.');
        }
    }
    auto query = [&](int s[510][510], int r1, int c1, int r2, int c2) {
        return s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] + s[r1 - 1][c1 - 1];
    };
    scanf("%d", &q);
    for (int _ = 1, r1, c1, r2, c2; _ <= q; _++) {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        int ans = 0;
        if (r1 < r2) ans += query(s1, r1, c1, r2 - 1, c2);
        if (c1 < c2) ans += query(s2, r1, c1, r2, c2 - 1);
        printf("%d\n", ans);
    }
    return 0;
}