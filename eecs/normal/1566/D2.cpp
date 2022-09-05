#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, m, a[maxn], id[maxn], ord[maxn], cnt[310][310];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n * m; i++) {
            scanf("%d", &a[i]);
        }
        iota(id + 1, id + n * m + 1, 1);
        sort(id + 1, id + n * m + 1, [&](int x, int y) {
            return make_pair(a[x], x) < make_pair(a[y], y);
        });
        for (int i = 1, j; i <= n * m; i = j) {
            vector<int> V;
            for (j = i; j <= n * m && a[id[i]] == a[id[j]]; j++) {
                V.push_back(j);
            }
            sort(V.begin(), V.end(), [&](int x, int y) {
                return make_pair(-((x + m - 1) / m), (x - 1) % m) >
                    make_pair(-((y + m - 1) / m), (y - 1) % m);
            });
            for (int k = i; k < j; k++) {
                ord[id[k]] = V[k - i];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) cnt[i][j] = 0;
        }
        for (int i = 1; i <= n * m; i++) {
            int r = (ord[i] + m - 1) / m, c = (ord[i] - 1) % m + 1;
            for (int j = 1; j < c; j++) ans += cnt[r][j];
            cnt[r][c]++;
        }
        printf("%d\n", ans);
    }
    return 0;
}