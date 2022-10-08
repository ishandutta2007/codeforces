#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int IT[262144];
bool OR[262144];
const Int LEAFOFFSET=131071;
Int n,q;

void Update(Int p,Int b)
{
    Int ind;

    IT[p+LEAFOFFSET]=b;

    ind=(p+LEAFOFFSET)/2;

    while(ind>0)
    {
        if (OR[ind])
        {
            IT[ind]=IT[2*ind]|IT[2*ind+1];
        }
        else
        {
            IT[ind]=IT[2*ind]^IT[2*ind+1];
        }

        ind/=2;
    }

    return;
}

int main()
{
    Int i;
    Int b,p;

    for (i=LEAFOFFSET+1;i<=LEAFOFFSET*2+1;i++)
    {
        OR[i]=false;
    }
    for (i=LEAFOFFSET;i>=1;i--)
    {
        OR[i]=!OR[2*i];
    }

    scanf("%I64d %I64d",&n,&q);

    n=(1<<n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&IT[i+LEAFOFFSET]);
    }

    for (i=LEAFOFFSET;i>=1;i--)
    {
        if (OR[i])
        {
            IT[i]=IT[2*i]|IT[2*i+1];
        }
        else
        {
            IT[i]=IT[2*i]^IT[2*i+1];
        }
    }

    for (i=1;i<=q;i++)
    {
        scanf("%I64d %I64d",&p,&b);

        Update(p,b);
        printf("%I64d\n",IT[1]);
    }

    return 0;
}