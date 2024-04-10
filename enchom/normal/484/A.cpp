#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int Count(Int k)
{
    Int i;
    Int ctr=0;

    for (i=0;i<=62;i++)
    {
        if ( (k&(1LL<<i))>0 )
        ctr++;
    }

    return ctr;
}

int main()
{
    Int n;
    Int l,r;
    Int i,j;
    Int firstdif;
    Int preones;
    Int num;

    scanf("%lld",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%lld %lld",&l,&r);

        if (l==r)
        {
            printf("%lld\n",l);
            continue;
        }

        firstdif=-1;
        num=0;
        for (j=62;j>=0;j--)
        {
            if ( (l&(1LL<<j))!=(r&(1LL<<j)) )
            {
                firstdif=j;
                break;
            }
            else if ( (l&(1LL<<j))>0 )
            {
                num=num+(1LL<<j);
            }
        }

        if (firstdif==0)
        {
            printf("%lld\n",r);
        }
        else
        {

            for (j=firstdif-1;j>=0;j--)
            {
                num=num+(1LL<<j);
            }

            num=num+(1LL<<firstdif);

            if (num>=l && num<=r)
            {
                printf("%lld\n",num);
            }
            else
            {
                num=num-(1LL<<firstdif);

                printf("%lld\n",num);
            }
        }
    }

    return 0;
}