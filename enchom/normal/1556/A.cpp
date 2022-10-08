#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    int i, j;
    int c, d;

    scanf("%d", &t);

    for (i=1;i<=t;i++)
    {
        scanf("%d %d", &c, &d);

        if (c == 0 && d == 0)
        {
            printf("0\n");
        }
        else if (c == d)
        {
            printf("1\n");
        }
        else if ( (c + d) % 2 == 1 )
        {
            printf("-1\n");
        }
        else
        {
            printf("2\n");
        }
    }

    return 0;
}