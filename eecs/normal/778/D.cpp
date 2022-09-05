#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
int n, m, cnt[256];
char s[maxn][maxn];

int main() {
    scanf("%d %d", &n, &m);
    char t = n & 1 ? 'U' : 'L';
    auto solve = [&]() {
        cnt['U'] = cnt['L'] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%s", s[i] + 1);
            for (int j = 1; j <= m; j++) cnt[s[i][j]]++;
        }
        vector<pair<int, int>> V;
        for (int dir = 0; cnt[t]; dir ^= 1) {
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    if (!dir && s[i][j] == 'U' && s[i][j + 1] == 'U') {
                        V.emplace_back(i, j);
                        s[i][j] = s[i + 1][j] = 'L';
                        s[i][j + 1] = s[i + 1][j + 1] = 'R';
                        cnt['U'] -= 2, cnt['L'] += 2;
                    } else if (dir && s[i][j] == 'L' && s[i + 1][j] == 'L') {
                        V.emplace_back(i, j);
                        s[i][j] = s[i][j + 1] = 'U';
                        s[i + 1][j] = s[i + 1][j + 1] = 'D';
                        cnt['L'] -= 2, cnt['U'] += 2;
                    }
                }
            }
        }
        return V;
    };
    auto V1 = solve(), V2 = solve();
    printf("%d\n", V1.size() + V2.size());
    for (auto p : V1) printf("%d %d\n", p.first, p.second);
    reverse(V2.begin(), V2.end());
    for (auto p : V2) printf("%d %d\n", p.first, p.second);
    return 0;
}