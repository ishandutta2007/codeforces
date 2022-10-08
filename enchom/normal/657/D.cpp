#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;
typedef long double Double;

const Double EPS=0.000000001;
const Double cEPS=0.00000000001;

struct task
{
    Int p,t;
    int id;
};

int n;
task tasks[200111];
task porder[200111];
Int TOTALTIME;

Double FABS(Double a)
{
    if (a<0.0)
    return -a;
    else
    return a;
}

Double Equal(Double a,Double b)
{
    return FABS(a-b)<cEPS;
}

bool SP(task a,task b)
{
    return a.p<b.p;
}

bool SQ(task a,task b)
{
    if (a.p*b.t > b.p*a.t)
    return true;
    else if (a.p*b.t < b.p*a.t)
    return false;
    else
    return a.p<b.p;
}

Double minscore[200111];
Double maxscore[200111];

int group[200111];
int L=0;

Int SolveGroup(Int T,Double c)
{
    int i;
    Int tm;
    Double pts;
    int g;
    Int cursum=0;

    for (i=1;i<=L;i++)
    {
        cursum+=tasks[ group[i] ].t;
    }

    for (i=1;i<=L;i++)
    {
        g=group[i];

        tm=T+tasks[g].t;

        pts=(Double)tasks[g].p * (1.0 - c*( (Double)tm/(Double)TOTALTIME ));

        maxscore[ tasks[g].id ]=pts;

        ///

        tm=T+cursum;

        pts=(Double)tasks[g].p * (1.0 - c*( (Double)tm/(Double)TOTALTIME ));

        minscore[ tasks[g].id ]=pts;
    }

    return T+cursum;
}

bool Paradoxal()
{
    int i;
    Double curmaxval=0.0;
    Double midmax=0.0;

    for (i=1;i<=n;i++)
    {
        if (minscore[ porder[i].id ]<curmaxval)
        {
            return true;
        }

        if (maxscore[ porder[i].id ]>midmax)
        midmax=maxscore[ porder[i].id ];

        if (i<n)
        {
            if (porder[i].p != porder[i+1].p)
            curmaxval=midmax;
        }
    }

    return false;
}

bool Paradox(Double c)
{
    int i;
    Int T=0;

    L=1;
    group[1]=1;

    for (i=2;i<=n;i++)
    {
        if (tasks[i].p*tasks[i-1].t == tasks[i].t*tasks[i-1].p)
        {
            L++;
            group[L]=i;
        }
        else
        {
            T=SolveGroup(T,c);

            L=1;
            group[1]=i;
        }
    }

    SolveGroup(T,c);

    return Paradoxal();
}

int main()
{
    int i;
    Double l,r,mid,best;

    TOTALTIME=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&tasks[i].p);
        tasks[i].id=i;
    }

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&tasks[i].t);

        TOTALTIME+=tasks[i].t;

        porder[i]=tasks[i];
    }

    sort(tasks+1,tasks+1+n,SQ);
    sort(porder+1,porder+1+n,SP);

    best=0.0;
    l=0.0;
    r=1.0;

    while(r-l>EPS)
    {
        mid=(l+r)/2.0;

        if (Paradox(mid))
        {
            r=mid;
        }
        else
        {
            l=mid;
            best=mid;
        }
    }

    printf("%.8f\n",(double)best);

    return 0;
}