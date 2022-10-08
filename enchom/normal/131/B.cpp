#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long Int;

Int OFFSET=10;

Int t[21];

Int ABS(Int a)
{
    if (a<0)
    return a*-1;
    else
    return a;
}

int main()
{
    Int n;
    Int i;
    Int a;
    Int couples=0;
    
    for (i=0;i<=20;i++)
    {
        t[i]=0;
    }
    scanf("%I64d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a);
        t[a+OFFSET]++;
    }
    for (i=-10;i<=0;i++)
    {
        if (i!=0)
        {
            if (t[i+OFFSET]>0 && t[ ABS(i)+OFFSET ]>0)
            {
                couples=couples+( t[i+OFFSET]*t[ ABS(i)+OFFSET ] );
            }
        }
        else
        {
            couples=couples+( ( (t[i+OFFSET]-1)*t[i+OFFSET] )/2 );
        }
    }
    printf("%I64d\n",couples);
    return 0;
}