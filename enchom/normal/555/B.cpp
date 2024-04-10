#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;
typedef long long Int;

struct event
{
    Int x;
    int tp;
    int id;
};

int n,m;
pair<Int,Int> island[200111];
Int a[200111];

event events[1000001];
int L=0;

bool SE(event a,event b)
{
    if (a.x<b.x)
    return true;
    else if (a.x>b.x)
    return false;
    else
    {
        if (a.tp==0 && b.tp==1)
        return true;
        else if (a.tp==1 && b.tp==0)
        return false;
        else
        {
            if (a.tp==0 && b.tp==2)
            return true;
            else if (a.tp==2 && b.tp==0)
            return false;
            else
            {
                if (a.tp==2 && b.tp==1)
                return true;
                else
                return false;
            }
        }
    }
}

int bridge[200111];

multimap<Int,int> mymap;
multimap<Int,int>::iterator myit;

int main()
{
    int i,j;
    Int theend;
    bool bad=false;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%lld %lld",&island[i].first,&island[i].second);
    }

    for (i=1;i<=m;i++)
    {
        scanf("%lld",&a[i]);
    }

    for (i=1;i<n;i++)
    {
        L++;
        events[L].x=island[i+1].first-island[i].second;
        events[L].tp=0;
        events[L].id=i;

        L++;
        events[L].x=island[i+1].second-island[i].first;
        events[L].tp=1;
        events[L].id=i;
    }

    for (i=1;i<=m;i++)
    {
        L++;
        events[L].x=a[i];
        events[L].tp=2;
        events[L].id=i;
    }

    sort(events+1,events+1+L,SE);

    memset(bridge,-1,sizeof(bridge));

    for (i=1;i<=L;i++)
    {
        if (events[i].tp==0)
        {
            theend=island[ events[i].id+1 ].second-island[ events[i].id ].first;

            mymap.insert( make_pair( theend,events[i].id ) );
        }
        else if (events[i].tp==1)
        {
            if (bridge[ events[i].id ]==-1)
            {
                bad=true;
                break;
            }
        }
        else
        {
            if (!mymap.empty())
            {
                myit=mymap.begin();

                bridge[ (*myit).second ]=events[i].id;

                mymap.erase(myit);
            }
        }
    }

    if (bad)
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");

        for (i=1;i<n;i++)
        {
            printf("%d",bridge[i]);

            if (i!=n-1)
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}