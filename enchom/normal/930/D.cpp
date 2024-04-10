#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
typedef long long llong;

int n;
pair<int,int> black[200111];

int L=0;
pair<int,int> active[200111];

vector<int> diag[500111];

set< pair<int,int> > myset;
set< pair<int,int> >::iterator myit;

llong Solve(int rem)
{
    int i,j;
    int p;
    int Lh=1000000,Rh=-1000000,Lt,Rt;
    int realL,realR;
    llong ans=0;

    for (i=1;i<=L;i++)
    {
        diag[ active[i].first+active[i].second ].push_back(i);
    }

    for (i=1;i<=L;i++)
    {
        myset.insert( make_pair( active[i].second-active[i].first, i) );
    }

    for (i=0;i<=500000;i++)
    {
        if (i%2==rem)
        {
            for (j=0;j<diag[i].size();j++)
            {
                p=diag[i][j];

                myset.erase(make_pair( active[p].second-active[p].first,p ));

                if (active[p].second-active[p].first > Rh)
                    Rh = active[p].second-active[p].first;

                if (active[p].second-active[p].first < Lh)
                    Lh = active[p].second-active[p].first;
            }
        }
        else
        {
            if (myset.empty() || Lh>=Rh)
                continue;

            myit=myset.begin();
            Lt = (*myit).first;
            myit=myset.end();
            myit--;
            Rt = (*myit).first;

            realL=Lh;
            if (Lt>realL)
                realL=Lt;

            realR=Rh;
            if (Rt<realR)
                realR=Rt;

            if (realL<realR)
                ans+=(llong)(realR-realL)/2LL;
        }
    }

    return ans;
}

int main()
{
    int i,j;
    llong ans=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&black[i].first,&black[i].second);

        black[i].first+=100001;
        black[i].second+=100001;
    }

    ///Part 1
    L=0;
    for (i=1;i<=n;i++)
    {
        if ( (black[i].first+black[i].second)%2==0 )
        {
            L++;
            active[L]=black[i];
        }
    }

    ans+=Solve(0);

    ///Part 2
    L=0;
    for (i=1;i<=n;i++)
    {
        if ( (black[i].first+black[i].second )%2==1 )
        {
            L++;
            active[L]=black[i];
        }
    }

    ans+=Solve(1);

    printf("%lld\n",ans);

    return 0;
}