#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

const Int OFFSET=10000000000LL;

Int ABS(Int a)
{
    if (a<0)
    return -a;
    else
    return a;
}

void EnchomSolve()
{
    Int x1,y1,x2,y2;
    Int step;
    Int ans;

    scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);

    //if ( ( (x2-x1+1)*(y2-y1+1) )%2==0 )
    ans=( (x2-x1+1)*(y2-y1+1)+1 )/2;
    /*else
    {
        ans=( (x2-x1+1)*(y2-y1+1) )/2;

        if ( ABS(x1-y1)%2==0 )
        {
            ans++;
        }
    }*/

    printf("%lld\n",ans);

    return;
}

int main()
{
    EnchomSolve();
    return 0;
}