#include <bits/stdc++.h>
using namespace std;

double m, m2;
int i, n, flag, ee, u, e[123456];

int bi (int st, int en, double fi)
{
    if (st >= en) return st;
    if (e[(st + en - 1) / 2] <= fi)
    {
        if (e[(st + en + 1) / 2] > fi)
        {
            return (st + en - 1) / 2;
        }
        else
        {
            return bi ((st + en + 1) / 2, en, fi);
        }
    }
    else
    {
        return bi (st, (st + en - 1) / 2, fi);
    }
}

int main()
{
    scanf ("%d%d", &n, &u);
    for (i = 0; i < n; i ++)
    {
        scanf ("%d", &e[i]);
        if (i > 1 && !flag)
        {
            if (e[i] - e[i - 2] <= u) flag = 1;
        }
    }
    if (!flag)
    {
        printf ("-1");
        return 0;
    }
    for (i = 0; i < n - 2; i ++)
    {
        ee = bi (i + 1, n - 1, e[i] + u);
        m2 = double(e[ee] - e[i + 1]) / double(e[ee] - e[i]);
        if (m < m2) m = m2;
    }
    printf ("%.9lf", m);
    return 0;
}