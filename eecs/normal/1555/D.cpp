#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
const int perm[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
int n, m, s[maxn][6];
char str[maxn];

int main() {
    scanf("%d %d %s", &n, &m, str + 1);
    for (int i = 1; i <= n; i++) {
        for (int p = 0; p < 6; p++) {
            s[i][p] = s[i - 1][p] + (str[i] != perm[p][i % 3] + 'a');
        }
    }
    while (m--) {
        int l, r, ans = INT_MAX;
        scanf("%d %d", &l, &r);
        for (int p = 0; p < 6; p++) {
            ans = min(ans, s[r][p] - s[l - 1][p]);
        }
        printf("%d\n", ans);
    }
    return 0;
}