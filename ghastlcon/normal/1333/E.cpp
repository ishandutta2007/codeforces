#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 520
using namespace std;

int a[N][N];

int main()
{
    int n;
    int c;

    c = 0;
    scanf("%d", &n);
    if (n <= 2) {
        puts("-1");
        return 0;
    }
    if (n == 3) {
        puts("1 2 4");
        puts("5 3 8");
        puts("9 6 7");
        return 0;
    }

    if (n == 4) {
        puts("4 3 6 12");
        puts("7 5 9 15");
        puts("14 1 11 10");
        puts("13 8 16 2");
        return 0;
    }

    for (int i = 1; i <= n - 2; i++) {
        int from = (i + n) % 2 ? 1 : n;
        int to = n + 1 - from;
        int delta = from == 1 ? 1 : -1;
        for (int j = from; j != to; j += delta)
            a[i][j] = ++c;
        a[i][to] = ++c;
    }

    int flag = 1;
    for (int j = 1; j <= n - 4; j++) {
        if (flag) {
            a[n - 1][j] = ++c;
            a[n][j] = ++c;
        } else {
            a[n][j] = ++c;
            a[n - 1][j] = ++c;
        }
        flag = !flag;
    }

    int x = n - 1, y = n;
    if (!flag)
        swap(x, y);

    a[x][n - 3] = 1 + c;
    a[x][n - 2] = 3 + c;
    a[x][n - 1] = 5 + c;
    a[x][n - 0] = 7 + c;
    a[y][n - 3] = 2 + c;
    a[y][n - 2] = 8 + c;
    a[y][n - 1] = 4 + c;
    a[y][n - 0] = 6 + c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        puts("");
    }

    return 0;
}