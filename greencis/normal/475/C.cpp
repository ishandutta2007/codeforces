#include <bits/stdc++.h>
using namespace std;

char s[1005][1005];
int cnt[1005][1005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int ans = 1e9;
    for (int zzz = 0; zzz < 2; ++zzz) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cnt[i][j] = (s[i][j] == 'X') + (i > 0 ? cnt[i - 1][j] : 0) + (j > 0 ? cnt[i][j - 1] : 0)
                        - (i > 0 && j > 0 ? cnt[i - 1][j - 1] : 0);
            }
        }
        int sy = -1, sx = -1;
        for (int i = 0; sy == -1 && i < n; ++i) {
            for (int j = 0; sy == -1 && j < m; ++j) {
                if (s[i][j] == 'X') {
                    sy = i;
                    sx = j;
                }
            }
        }
        int w = 1;
        while (sx + w < m && s[sy][sx + w] == 'X')
            ++w;
        int total = cnt[n - 1][m - 1];
        int h = 1;
        auto getArea = [&](int y, int x) {
            return cnt[y][x] - (y >= h ? cnt[y - h][x] : 0) - (x >= w ? cnt[y][x - w] : 0)
                + (y >= h && x >= w ? cnt[y - h][x - w] : 0);
        };
        for (; h <= n - sy; ++h) {
            int bottom = sy + h - 1;
            int right = sx + w - 1;
            int cur = getArea(bottom, right);
            if (cur != h * w)
                continue;
            while (true) {
                if (right + 1 < m && getArea(bottom, right + 1) == h * w) {
                    ++right;
                    cur += h;
                } else if (bottom + 1 < n && getArea(bottom + 1, right) == h * w) {
                    ++bottom;
                    cur += w;
                } else break;
            }
            if (cur == total)
                ans = min(ans, h * w);
        }

        for (int i = 0; i < max(n, m); ++i) {
            for (int j = i + 1; j < max(n, m); ++j) {
                swap(s[i][j], s[j][i]);
            }
        }
        swap(n, m);
    }
    if (ans == 1e9) ans = -1;
    cout << ans << endl;
}