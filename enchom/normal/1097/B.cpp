#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int a[21];

int main()
{
    int i,j;
    int sum = 0;

    scanf("%d",&n);

    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for (i=0;i<(1<<n);i++)
    {
        sum = 0;
        for (j=0;j<n;j++)
        {
            if ( (i&(1<<j)) > 0 )
                sum += a[j];
            else
                sum -= a[j];

            while(sum < 0)
                sum += 360;
            while(sum >= 360)
                sum -= 360;
        }

        if (sum == 0)
        {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");

    return 0;
}