#include <bits/stdc++.h>
using namespace std;

int i, j, k, n, m, p, c[123];

int x(int y, int z)
{
    int cnt = 0;
    int y2 = y;
    int z2 = z;
    for (k = 0; k < n; k ++)
    {
        if (y2 == z)
        {
            return cnt;
        }
        else if (y2 > z || c[y2] != c[z2])
        {
            return 1;
        }
        else
        {
            cnt ++;
            y2 ++;
            z2 ++;
        }
    }
}

int main()
{
    scanf ("%d\n", &n);
    m = 1;
    for (i = 0; i < n; i ++)
    {
        scanf ("%c", &c[i]);
    }
    for (i = 0; i < n - 1; i ++)
    {
        p = x(0, i);
        if (p > m) m = p;
    }
    printf ("%d", n - m + 1);
    return 0;
}