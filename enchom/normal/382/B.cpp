#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int a,b,w,x,c;

int main()
{
    Int l,r,mid;
    Int newc,newa;
    Int subtracted;
    Int newb;
    Int p;
    Int best;

    l=0;
    r=10000000000000;

    scanf("%I64d %I64d %I64d %I64d %I64d",&a,&b,&w,&x,&c);

    while(l<=r)
    {
        mid=(l+r)/2;

        newc=c-mid;
        subtracted=mid*x;

        newb=b-subtracted;
        p=(-newb)/w;

        newb=newb+p*w;
        newa=a-p;

        if (newb<0)
        {
            newb+=w;
            newa--;
        }

        if (newc<=newa)
        {
            best=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

    printf("%I64d\n",best);

    return 0;
}