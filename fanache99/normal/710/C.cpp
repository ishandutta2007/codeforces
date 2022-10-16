#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int a[60][60], n;

int Value(int x) {
    if (x == 0)
        return n;
    if (x == n + 1)
        return 1;
    return x;
}

void Solve() {
    int l = 1, c = n / 2 + 1;
    a[l][c] = 1;
    for (int i = 2; i <= n * n; i++) {
        if (a[Value(l - 1)][Value(c + 1)] == 0) {
            l = Value(l - 1);
            c = Value(c + 1);
        }
        else
            l = Value(l + 1);
        a[l][c] = i;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            printf("%d",a[i][j]);
            if (j == n)
                printf("\n");
            else
                printf(" ");
        }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%d", &n);
    Solve();
    return 0;
}