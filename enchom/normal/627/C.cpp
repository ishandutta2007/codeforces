#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
typedef long long Int;

struct event
{
    int x;
    int id,cost;
    bool beg;
};

event events[400111];
int L=0;
bool flag=false;

int d,n,m;

set< pair<int,int> > myset;
set< pair<int,int> >::iterator myit;

int x[200111];
int p[200111];

bool SE(event a,event b)
{
    return a.x<b.x;
}

Int Solve(int L,int R)
{
    if (L==R)
    return 0;

    if (myset.empty())
    {
        flag=true;
        return 0;
    }

    Int costperliter=(*myset.begin()).first;

    return costperliter*(Int)(R-L);
}

int main()
{
    int i;
    int lastplace;
    Int ans=0;

    scanf("%d %d %d",&d,&n,&m);

    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&x[i],&p[i]);

        L++;
        events[L].beg=true;
        events[L].x=x[i];
        events[L].id=i;
        events[L].cost=p[i];

        L++;
        events[L].beg=false;
        events[L].id=i;
        events[L].cost=p[i];
        events[L].x=x[i]+n;
    }

    L++;
    events[L].x=n;
    events[L].beg=false;
    events[L].cost=0;
    events[L].id=0;

    L++;
    events[L].x=d;
    events[L].beg=true;

    sort(events+1,events+1+L,SE);

    myset.insert(make_pair(0,0));

    lastplace=0;

    for (i=1;i<=L;i++)
    {
        if (events[i].beg)
        {
            ans+=Solve(lastplace,events[i].x);
            lastplace=events[i].x;

            if (flag)
            {
                printf("-1\n");
                return 0;
            }

            if (events[i].x==d)
            break;

            myset.insert(make_pair( events[i].cost,events[i].id ));
        }
        else
        {
            ans+=Solve(lastplace,events[i].x);
            lastplace=events[i].x;

            if (flag)
            {
                printf("-1\n");
                return 0;
            }

            myset.erase(make_pair( events[i].cost,events[i].id ));
        }
    }

    printf("%lld\n",ans);

    return 0;
}