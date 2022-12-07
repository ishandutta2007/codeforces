#include <stdio.h>

using namespace std;

int main(void)
{
    int n, i, j, k = 0;
    int x[200], y[200];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d%d", x + i, y + i);
    bool u, d, l, r;
    for (i = 0; i < n; i++)
    {
        u = d = l = r = false;
        for (j = 0; j < n; j++)
        {
            if (x[j] == x[i])
            {
                if (y[j] > y[i])
                    u = true;
                if (y[j] < y[i])
                    d = true;
            }
            if (y[j] == y[i])
            {
                if (x[j] > x[i])
                    r = true;
                if (x[j] < x[i])
                    l = true;
            }
        }
        if (u && d && l && r)
            ++k;
    }
    printf("%d", k);
    return 0;
}