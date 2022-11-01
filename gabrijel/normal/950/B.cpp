#include <bits/stdc++.h>
using namespace std;

int n, m, rj = 0;
int a [1000100];
int b [1000100];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a [i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b [i]);
    }
    int x = 0, y = 0, sa = 0, sb = 0;
    while (x < n && y < m)
    {
        if (sa == sb)
        {
            if (sa != 0) rj++;
            sa = a [x]; sb = b [y];
            x++; y++;
        }
        else if (sa < sb)
        {
            sa += a [x];
            x++;
        }
        else
        {
            sb += b [y];
            y++;
        }
        if (x == n && y == m) break;
    }
    printf("%d", rj + 1);
    return 0;
}