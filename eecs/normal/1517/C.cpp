#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int n, p[maxn], a[maxn][maxn], b[maxn][maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]), a[i][i] = b[i][i] = p[i];
    }
    for (int i = 2; i <= n; i++) {
        int pos;
        for (int j = i - 1; j <= n; j++) {
            if (a[j][j - (i - 1) + 1] == 1) pos = j;
        }
        for (int j = i; j <= n; j++) {
            if (j <= pos) {
                a[j][j - i + 1] = a[j - 1][j - i + 1] - 1;
                b[j][j - i + 1] = b[j - 1][j - i + 1];                
            } else  {
                a[j][j - i + 1] = a[j][j - i + 2] - 1;
                b[j][j - i + 1] = b[j][j - i + 2];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d%c", b[i][j], " \n"[j == n]);
        }
    }
    return 0;
}