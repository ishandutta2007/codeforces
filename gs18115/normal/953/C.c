#include <stdio.h>
#include <stdlib.h>

int i, n, a2, a, cnt, cnt2;

int main()
{
    scanf ("%d", &n);
    a2 = -1;
    for (i = 0; i < n; i ++)
    {
        scanf ("%d", &a);
        if (a != a2 && a2 != -1)
        {
            if (cnt == cnt2)
            {
                cnt = 0;
                a2 = a;
            }
            else if (cnt2 == 0)
            {
                cnt2 = cnt;
                cnt = 0;
                a2 = a;
            }
            else
            {
                printf ("NO");
                return 0;
            }
        }
        else if (a2 == -1)
        {
            a2 = a;
        }
        cnt ++;
    }
    if (cnt != cnt2 && cnt2 != 0)
    {
        printf ("NO");
        return 0;
    }
    printf ("YES");
    return 0;
}