#include <cstdio>
#include <algorithm>
using namespace std;
int n, q, a[200005], f[2][200005];
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        char tmp;
        scanf(" %c", &tmp);
        a[i] = tmp - '0';
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1])
            f[a[i]][i] = 1;
        f[0][i] += f[0][i - 1];
        f[1][i] += f[1][i - 1];
    }
    for (int i = 1; i <= q; i++)
    {
        int L, R;
        scanf("%d%d", &L, &R);
        int x = f[0][R] - f[0][L];
        int y = f[1][R] - f[1][L];
        printf("%d\n", max(x, y) + 1);
    }
}