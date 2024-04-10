#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int rems[4];

int main()
{
    Int n;
    Int i;
    Int add=0;

    scanf("%I64d",&n);

    if (n<=2)
    {
        printf("-1\n");
        return 0;
    }
    if (n==3)
    {
        printf("210\n");
        return 0;
    }

    rems[0]=1;
    rems[1]=1;
    rems[2]=1;
    rems[3]=1;

    for (i=1;i<=n-1;i++)
    {
        rems[0]=(rems[0]*10)%2;
        rems[1]=(rems[1]*10)%3;
        rems[2]=(rems[2]*10)%5;
        rems[3]=(rems[3]*10)%7;
    }

    while(rems[0]+rems[1]+rems[2]+rems[3]!=0)
    {
        rems[0]=(rems[0]+1)%2;
        rems[1]=(rems[1]+1)%3;
        rems[2]=(rems[2]+1)%5;
        rems[3]=(rems[3]+1)%7;

        add++;
    }

    printf("1");
    if (add<10)
    {
        for (i=1;i<=n-2;i++)
        {
            printf("0");
        }
        printf("%I64d\n",add);
    }
    else if (add<100)
    {
        for (i=1;i<=n-3;i++)
        {
            printf("0");
        }
        printf("%I64d\n",add);
    }
    else
    {
        for (i=1;i<=n-4;i++)
        {
            printf("0");
        }
        printf("%I64d\n",add);
    }

    return 0;
}