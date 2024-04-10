#include <iostream>
#include <stdio.h>
using namespace std;

int n;
char s[1000111];

int main()
{
    int i,j;

    scanf("%d",&n);

    scanf("%s",s+1);

    int cost = 0;

    int sum = 0;
    int cur = 1;
    while(cur <= n)
    {
        int subsum = 0;

        for (i=cur;i<=n;i++)
        {
            if (s[i] == '(')
                subsum++;
            else
                subsum--;

            if (sum + subsum >= 0)
                break;
        }

        if (sum + subsum < 0)
        {
            sum = -1;
            break;
        }
        else if (i != cur)
        {
            sum += subsum;
            cost += (i - cur + 1);
            cur = i + 1;
        }
        else
        {
            sum += subsum;
            cur++;
        }
    }

    if (sum != 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",cost);
    }

    return 0;
}