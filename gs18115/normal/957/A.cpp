#include <bits/stdc++.h>
using namespace std;

int n, i, flag;
char c[1234];

int main()
{
    scanf ("%d\n", &n);
    c[0] = '?';
    for (i = 1; i <= n; i ++)
    {
        scanf ("%c", &c[i]);
        if (flag == 0)
        {
            if (c[i] == '?')
            {
                flag = 1;
            }
        }
        else if (flag == 1)
        {
            if (c[i] == '?' || c[i] == c[i - 2])
            {
                flag = 2;
            }
            else
            {
                flag = 0;
            }
        }
        if (c[i] == c[i - 1] && c[i] != '?')
        {
            printf ("No");
            return 0;
        }
        else if (c[i] == c[i - 1] && c[i] == '?')
        {
            flag = 2;
        }
    }
    if (flag)
    {
        printf ("Yes");
    }
    else
    {
        printf ("No");
    }
    return 0;
}