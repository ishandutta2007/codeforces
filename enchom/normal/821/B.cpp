#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int ans=0;
Int cur;

int main()
{
    int x,y;
    int m,b;

    scanf("%d %d",&m,&b);

    for (y=0;y<=b;y++)
    {
        x=(b-y)*m;

        cur=(Int)(x+1)*(Int)(y+1)*(Int)(x+y);
        cur/=2;

        if (ans<cur)
        ans=cur;
    }

    printf("%lld\n",ans);

    return 0;
}