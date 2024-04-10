#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 2000 + 5

int n, x1, y1, x2, y2, A[N][N], id[N][N];
LL ans = -1, Sum[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            scanf("%d", A[i] + j);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
        {
            if (id[i][j] == 1) continue ;
            LL sum = 0;
            for (int k = 0; i + k <= n && j + k <= n; k ++)
                sum += A[i + k][j + k], id[i + k][j + k] = 1;
            for (int k = 0; i + k <= n && j + k <= n; k ++)
                Sum[i + k][j + k] = sum;
        }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
        {
            if (id[i][j] == 2) continue ;
            LL sum = 0;
            for (int k = 0; i + k <= n && j - k > 0; k ++)
                sum += A[i + k][j - k], id[i + k][j - k] = 2;
            for (int k = 0; i + k <= n && j - k > 0; k ++)
                Sum[i + k][j - k] = Sum[i + k][j - k] + sum - A[i + k][j - k];
        }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (Sum[i][j] > ans)
                ans = Sum[i][j], x1 = i, y1 = j;
    LL _ans = -1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (Sum[i][j] > _ans && ((x1 + y1 & 1) != (i + j & 1)))
                _ans = Sum[i][j], x2 = i, y2 = j;
    cout << ans + _ans << endl;
    printf("%d %d %d %d\n", x1, y1, x2, y2);
    return 0;
}