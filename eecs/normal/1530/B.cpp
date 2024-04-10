#include <bits/stdc++.h>
using namespace std;

int T, h, w, s[25][25], ans[25][25];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &h, &w);
        vector<pair<int, int>> V;
        for (int i = 1; i <= w; i++) {
            V.emplace_back(1, i);
        }
        for (int i = 2; i <= h; i++) {
            V.emplace_back(i, w);
        }
        for (int i = w - 1; i; i--) {
            V.emplace_back(h, i);
        }
        for (int i = h - 1; i > 1; i--) {
            V.emplace_back(i, 1);
        }
        int mx = 0;
        for (int sy = 1; sy <= 3; sy++) {
            memset(s, 0, sizeof(s));
            int num = 0;
            for (auto p : V) {
                if (p.first == 1 && p.second < sy) continue;
                int x = p.first, y = p.second;
                bool flag = 1;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) if (dx || dy) {
                        flag &= !s[x + dx][y + dy];
                    }
                }
                if (flag) s[x][y] = 1, num++;
            }
            if (num > mx) mx = num, swap(s, ans);
        }
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                putchar(ans[i][j] + '0');
            }
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}