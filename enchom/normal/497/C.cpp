#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct e
{
    int x;

    bool song;
    int r,id;
};

int n;
vector< pair<int,int> > song[100011];

int m;
vector< pair<int,int> > singer[100011];

int limit[100011];
e events[200011];
int L=0;

int ans[100011];

bool SE(e a,e b)
{
    if (a.x<b.x)
    return true;
    else if (a.x>b.x)
    return false;
    else
    {
        if (!a.song && b.song)
        return true;
        else
        return false;
    }
}

multimap<int,int> active;
multimap<int,int>::iterator myit;

int main()
{
    int i;
    int l,r;
    int cur;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&l,&r);

        L++;
        events[L].x=l;
        events[L].song=true;
        events[L].r=r;
        events[L].id=i;
    }

    scanf("%d",&m);

    for (i=1;i<=m;i++)
    {
        scanf("%d %d %d",&l,&r,&limit[i]);

        L++;
        events[L].x=l;
        events[L].song=false;
        events[L].r=r;
        events[L].id=i;
    }

    sort(events+1,events+1+L,SE);

    for (i=1;i<=L;i++)
    {
        cur=events[i].x;

        if (!events[i].song) ///adding a singer
        {
            active.insert(make_pair(events[i].r,events[i].id));
        }

        ///Removing useless singers
        while(!active.empty())
        {
            myit=active.begin();

            if ( (*myit).first<cur )
            {
                active.erase(myit);
            }
            else
            break;
        }

        if (events[i].song) ///calculating a song
        {
            myit=active.lower_bound(events[i].r);

            if (myit==active.end())
            {
                printf("NO\n");
                return 0;
            }

            ans[ events[i].id ]=(*myit).second;

            limit[ (*myit).second ]--;

            if (limit[ (*myit).second ]==0)
            {
                active.erase(myit);
            }
        }
    }

    printf("YES\n");

    for (i=1;i<=n;i++)
    {
        printf("%d",ans[i]);
        if (i!=n)
        printf(" ");
    }
    printf("\n");

    return 0;
}