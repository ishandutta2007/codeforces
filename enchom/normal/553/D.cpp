#include <iostream>
#include <stdio.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;
typedef long long Int;

struct frac
{
    Int a,b;

    bool operator<( const frac& other ) const
    {
        return a*other.b<other.a*b;
    }
};

set< pair<frac,int> > myset;
set< pair<frac,int> >::iterator myit;

frac cost[100111];
int n,m,k;
bool fortress[100111];
vector<int> Graph[100111];
vector<int> removed;
int bestmoment=-1;
frac bestcost;

vector<int> ans;

int main()
{
    int i;
    int a,b;
    bool first=true;
    frac curcost;
    int ctr=0;
    int ver,nver;

    memset(fortress,false,sizeof(fortress));

    scanf("%d %d %d",&n,&m,&k);

    for (i=1;i<=n;i++)
    {
        cost[i].a=0;
        cost[i].b=0;
    }

    for (i=1;i<=k;i++)
    {
        scanf("%d",&a);

        fortress[a]=true;
    }

    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);

        cost[a].b++;
        cost[b].b++;

        if (!fortress[a])
        cost[b].a++;
        if (!fortress[b])
        cost[a].a++;
    }

    for (i=1;i<=n;i++)
    {
        if (!fortress[i])
        {
            myset.insert( make_pair(cost[i],i) );
        }
    }

    while(!myset.empty())
    {
        myit=myset.begin();

        if (first)
        {
            bestcost=(*myit).first;
            bestmoment=0;

            first=false;
        }
        else
        {
            curcost=(*myit).first;

            if (bestcost<curcost)
            {
                bestcost=curcost;
                bestmoment=ctr;
            }
        }

        ver=(*myit).second;
        fortress[ver]=true;
        removed.push_back(ver);
        myset.erase(myit);

        for (i=0;i<Graph[ver].size();i++)
        {
            nver=Graph[ver][i];
            if (!fortress[nver])
            {
                myset.erase( make_pair(cost[nver],nver) );

                cost[nver].a--;

                myset.insert( make_pair(cost[nver],nver) );
            }
        }

        ctr++;
    }

    for (i=bestmoment;i<removed.size();i++)
    {
        fortress[ removed[i] ]=false;
    }

    for (i=1;i<=n;i++)
    {
        if (!fortress[i])
        {
            ans.push_back(i);
        }
    }

    printf("%d\n",(int)ans.size());

    for (i=0;i<ans.size();i++)
    {
        if (i!=0)
        printf(" ");

        printf("%d",ans[i]);
    }
    printf("\n");

    return 0;
}