#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
int n, a[maxn][maxn], r[maxn][maxn], c[maxn][maxn], ans[maxn];
bool used[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            r[i][a[i][j]]++, c[j][a[i][j]]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        int sum = -1, bar;
        for (int j = 1; j <= n; j++) if (!used[j]) {
            int foo = r[j][i] + c[j][i];
            if (foo > sum) sum = foo, bar = j;
        }
        ans[bar] = i, used[bar] = 1;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}