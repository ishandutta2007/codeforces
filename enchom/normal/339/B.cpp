#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int curhouse=1;
    Int n,m;
    Int i;
    Int house;
    Int totaltime=0;

    scanf("%I64d %I64d",&n,&m);

    for (i=1;i<=m;i++)
    {
        scanf("%I64d",&house);

        if (house>=curhouse)
        {
            totaltime=totaltime+(house-curhouse);
            curhouse=house;
        }
        else
        {
            totaltime=totaltime+(house+n-curhouse);
            curhouse=house;
        }
    }

    printf("%I64d\n",totaltime);

    return 0;
}