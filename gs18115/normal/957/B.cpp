#include <bits/stdc++.h>
using namespace std;

int i, j, n, m, k, c[100][100], check[100], p[100], flag;

int main()
{
    scanf ("%d %d", &n, &m);
    for (i = 0; i < n; i ++)
    {
        scanf ("\n");
        for (j = 0; j < m; j ++)
        {
            scanf ("%c", &c[i][j]);
            if (c[i][j] == '#')
            {
                c[i][j] = 1;
            }
            else
            {
                c[i][j] = 0;
            }
        }
    }
    for (i = 0; i < n; i ++)
    {
        if (check[i]) continue;
        flag = 1;
        for (j = 0; j < m; j ++)
        {
            if (c[i][j] == 1)
            {
                p[j] = 1;
                flag = 0;
            }
            else
            {
                p[j] = 0;
            }
        }
        for (j = i + 1; j < n; j ++)
        {
            flag = 0;
            for (k = 0; k < m; k ++)
            {
                if ((c[j][k] ^ p[k]) && flag)
                {
                    printf ("No");
                    return 0;
                }
                if (!(c[j][k] ^ p[k]) && p[k] && !flag)
                {
                    flag = 1;
                    k = -1;
                }
            }
            if (flag) check[j] = 1;
        }
    }
    printf ("Yes");
    return 0;
}