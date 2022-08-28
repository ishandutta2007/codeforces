#include <bits/stdc++.h>
using namespace std;
int n, m, t;
char a[1010][1010];
int b[1010][1010];
int main() {
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    queue < pair < int, int > > q;
    memset(b, -1, sizeof b);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int tag = 0;
            if (i > 1 && a[i - 1][j] == a[i][j]) tag = 1;
            if (j > 1 && a[i][j - 1] == a[i][j]) tag = 1;
            if (i < n && a[i + 1][j] == a[i][j]) tag = 1;
            if (j < m && a[i][j + 1] == a[i][j]) tag = 1;
            if (tag) q.push(make_pair(i, j)), b[i][j] = 0;
        }
    if (q.empty()) {
        for (int i = 1; i <= t; i++) {
            int x, y;
            long long p;
            scanf("%d%d%lld", &x, &y, &p);
            putchar(a[x][y]);
            putchar('\n');
        }
    }
    else {
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i > 1 && b[i - 1][j] == -1) {
                q.push(make_pair(i - 1, j));
                b[i - 1][j] = b[i][j] + 1;
            }
            if (j > 1 && b[i][j - 1] == -1) {
                q.push(make_pair(i, j - 1));
                b[i][j - 1] = b[i][j] + 1;
            }
            if (i < n && b[i + 1][j] == -1) {
                q.push(make_pair(i + 1, j));
                b[i + 1][j] = b[i][j] + 1;
            }
            if (j < m && b[i][j + 1] == -1) {
                q.push(make_pair(i, j + 1));
                b[i][j + 1] = b[i][j] + 1;
            }
        }
        for (int i = 1; i <= t; i++) {
            int x, y;
            long long p;
            scanf("%d%d%lld", &x, &y, &p);
            if (p <= b[x][y]) {
                putchar(a[x][y]);
                putchar('\n');
            }
            else {
                putchar(a[x][y] ^ ((p - b[x][y]) & 1));
                putchar('\n');
            }
        }
    }
}