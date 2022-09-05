#include <bits/stdc++.h>
using namespace std;

int T, a, b;
bool f[6][6][205][205];
pair<int, int> pre[6][6][205][205];

int main() {
    f[0][0][0][0] = 1;
    for (int i = 0; i < 5; i++) {
        int all = i < 4 ? 25 : 15;
        auto chk = [&](int z, int x, int y, int p, int q) {
            if (x > 200 || y > 200) return;
            if (!f[i + 1][z][x][y]) pre[i + 1][z][x][y] = {p, q};
            f[i + 1][z][x][y] = 1;
        };
        for (int j = 0; j <= i; j++) {
            if (j == 3 || i - j == 3) continue;
            for (int x = 0; x <= 200; x++) {
                for (int y = 0; y <= 200; y++) if (f[i][j][x][y]) {
                    for (int p = 0; p <= all - 2; p++) {
                        chk(j, x + p, y + all, p, all);
                        chk(j + 1, x + all, y + p, all, p);
                    }
                    for (int p = 26; p <= 200; p++) {
                        chk(j, x + p - 2, y + p, p - 2, p);
                        chk(j + 1, x + p, y + p - 2, p, p - 2);
                    }
                }
            }
        }
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &a, &b);
        int mx = INT_MIN, ansi, ansj;
        for (int i = 1; i <= 5; i++) {
            for (int j = 0; j <= i; j++) if (f[i][j][a][b]) {
                if (j != 3 && i - j != 3) continue;
                if (j - (i - j) > mx) mx = j - (i - j), ansi = i, ansj = j;
            }
        }
        if (mx == INT_MIN) { puts("Impossible"); continue; }
        printf("%d:%d\n", ansj, ansi - ansj);
        vector<pair<int, int>> V;
        while (ansi) {
            auto p = pre[ansi][ansj][a][b];
            V.push_back(p);
            a -= p.first, b -= p.second;
            ansi--, ansj -= p.first > p.second;
        }
        reverse(V.begin(), V.end());
        for (auto &p : V) printf("%d:%d ", p.first, p.second);
        putchar('\n');
    }
    return 0;
}