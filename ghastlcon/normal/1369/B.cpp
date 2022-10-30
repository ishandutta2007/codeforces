#include <bits/stdc++.h>
using namespace std;

char a[1000000];

int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        int n;
        scanf("%d %s", &n, a);
        int cx = 0, cy = 0;

        for(int i = 0; i < n && a[i] == '0'; i ++, cx ++)
            ;
        for(int i = n - 1; i > -1 && a[i] == '1'; i --, cy ++)
            ;
        if(cx + cy == n)
        {
            printf("%s\n", a);
        }
        else
        {
            while(cx --)
                putchar('0');
            putchar('0');
            while(cy --)
                putchar('1');
            putchar('\n');
        }
    }
    return 0;
}