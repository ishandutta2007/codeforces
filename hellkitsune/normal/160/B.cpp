#include <stdio.h>

using namespace std;

int main()
{
    bool flag1, flag2, tominus;
    int n, i, k;
    char c;
    int a[10] = {0}, b[10] = {0};
    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
    {
        c = getchar();
        ++a[c - '0'];
    }
    for (i = 0; i < n; i++)
    {
        c = getchar();
        ++b[c - '0'];
    }
    k = 9;
    flag1 = true;
    flag2 = true;
    for (i = 9; i >= 0; i--)
        while (a[i] > 0)
            if (b[k] == 0)
                k--;
            else
            {
                if (b[k] > a[i])
                {
                    b[k] -= a[i];
                    a[i] = 0;
                    tominus = false;
                }
                else
                {
                    a[i] -= b[k];
                    b[k] = 0;
                    tominus = true;
                }
                if (k >= i)
                    flag1 = false;
                if (k <= i)
                    flag2 = false;
                if (tominus)
                    --k;
            }
    if (flag1 || flag2)
        printf("YES");
    else
        printf("NO");
    return 0;
}