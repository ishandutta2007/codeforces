#include <bits/stdc++.h>
using namespace std;

int T, n, m;
char s[110][110];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", s[i] + 1);
        }
        if (s[1][1] == '1') { puts("-1"); continue; }
        vector<array<int, 4>> V;
        for (int i = n; i; i--) {
            for (int j = m; j; j--) if (s[i][j] == '1') {
                if (i > 1) V.push_back({i - 1, j, i, j});
                else V.push_back({i, j - 1, i, j});
            }
        }
        printf("%d\n", V.size());
        for (auto &p : V) printf("%d %d %d %d\n", p[0], p[1], p[2], p[3]);
    }
    return 0;
}