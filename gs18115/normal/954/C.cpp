#include <bits/stdc++.h>
using namespace std;

int ab (int x)
{
    if (x > 0) return x;
    return -1 * x;
}

int n, i, b, cnt, m, a[345678];

int main()
{
    scanf ("%d", &n);
    cnt = 1;
    scanf ("%d", &a[0]);
    m = a[0];
    for (i = 1; i < n; i ++)
    {
        scanf ("%d", &a[i]);
        b = ab (a[i] - a[i - 1]);
        if (b == 0)
        {
            printf ("NO");
            return 0;
        }
        if (b != 1)
        {
            if (cnt == 1)
            {
                cnt = b;
            }
            else if (b != cnt)
            {
                printf ("NO");
                return 0;
            }
        }
        else
        {
            if (a[i - 1] % cnt == 0 && a[i] % cnt == 1 && a[i] == a[i - 1] + 1 || a[i - 1] % cnt == 1 && a[i] % cnt == 0 && a[i - 1] == a[i] + 1)
            {
                printf ("NO");
                return 0;
            }
        }
        if (a[i] > m) m = a[i];
    }
    for (i = 1; i < n; i ++)
    {
        b = ab (a[i] - a[i - 1]);
        if (b == 0)
        {
            printf ("NO");
            return 0;
        }
        if (b != 1)
        {
            if (b != cnt)
            {
                printf ("NO");
                return 0;
            }
        }
        else
        {
            if (a[i - 1] % cnt == 0 && a[i] % cnt == 1 && a[i] == a[i - 1] + 1 || a[i - 1] % cnt == 1 && a[i] % cnt == 0 && a[i - 1] == a[i] + 1)
            {
                printf ("NO");
                return 0;
            }
        }
        if (a[i] > m) m = a[i];
    }
    m = (m - 1) / cnt + 1;
    if (cnt == 1) cnt = m;
    printf ("YES\n%d %d", m, cnt);
    return 0;
}