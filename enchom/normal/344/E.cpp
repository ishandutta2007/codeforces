#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int people[100002];
Int goals[100002];
Int n,m;

Int MIN(Int a,Int b)
{
    if (a<b)
    return a;
    else
    return b;
}

bool AnswerExists(Int k)
{
    Int i;
    Int uk=1;
    Int timeneeded;

    ///cout<<k<<"-------------"<<endl;

    for (i=1;i<=n;i++)
    {
        if (uk>m)
        break;

        if (goals[uk]<people[i])
        {
            ///cout<<"here"<<endl;
            if (people[i]-goals[uk]>k)
            {
                return false;
            }

            timeneeded=people[i]-goals[uk];

            ///cout<<timeneeded<<endl;

            while(goals[uk]<people[i] && uk<=m)
            {
                uk++;
            }

            ///cout<<"reaching "<<uk<<endl;

            while( MIN( (goals[uk]-people[i])*2+timeneeded, timeneeded*2+(goals[uk]-people[i]) )<=k && uk<=m )
            {
                uk++;
            }
        }
        else
        {
            while(goals[uk]-people[i]<=k)
            {
                uk++;
            }
        }

        ///cout<<"After end of "<<i<<" = "<<uk<<endl;
    }

    if (uk>m)
    return true;
    else
    return false;
}

int main()
{
    Int i,j;
    Int l,r,mid,best;

    scanf("%I64d %I64d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&people[i]);
    }

    for (i=1;i<=m;i++)
    {
        scanf("%I64d",&goals[i]);
    }

    l=0;
    r=20000000000;

    while(l<=r)
    {
        mid=(l+r)/2;

        if (AnswerExists(mid))
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