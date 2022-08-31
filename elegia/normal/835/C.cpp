#include <cstdio>

using namespace std;

int s[100010], x[100010], y[100010];
int a[11][110][110];

int n, q, c;

int main() {
    int x1, y1, x2, y2, t;
    scanf("%d%d%d", &n, &q, &c);
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d", &x[i], &y[i], &s[i]);
    for (int i = 0; i <= c; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][x[j]][y[j]] += s[j];
            if (++s[j] > c)
               s[j] = 0;
        }
        for (int j = 1; j <= 100; ++j)
            for (int k = 1; k <= 100; ++k)
                a[i][j][k] += a[i][j - 1][k] + a[i][j][k - 1] - a[i][j - 1][k - 1];
    }
    while (q--) {
          scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
          t %= c + 1;
          printf("%d\n", a[t][x2][y2] - a[t][x1 - 1][y2]
                        -a[t][x2][y1 - 1] + a[t][x1 - 1][y1 - 1]);
    }
    return 0;
}