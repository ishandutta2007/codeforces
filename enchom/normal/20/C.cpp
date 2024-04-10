#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
typedef long long Int;

struct gr
{
    Int ver,val;
};

vector<gr> Graph[100001];
Int n,m;
bool TFO[100001];
Int LU[100001];
Int Path[100001];
Int L=0;
priority_queue< pair<Int,Int> > pq;
Int D[100001];

void Djikstra()
{
    Int i;
    pair<Int,Int> mytop;

    for (i=2;i<=n;i++)
    {
        D[i]=999999999999999;
    }
    D[1]=0;

    pq.push( make_pair(0,1) );

    while(!pq.empty())
    {
        mytop=pq.top();
        pq.pop();

        if (TFO[mytop.second])
        continue;

        TFO[mytop.second]=true;

        for (i=0;i<Graph[mytop.second].size();i++)
        {
            if (TFO[ Graph[mytop.second][i].ver ])
            continue;

            if (D[ Graph[mytop.second][i].ver ]>(Graph[mytop.second][i].val-mytop.first))
            {
                D[ Graph[mytop.second][i].ver ]=(Graph[mytop.second][i].val-mytop.first);
                LU[ Graph[mytop.second][i].ver ]=mytop.second;
            }

            pq.push( make_pair( -(Graph[mytop.second][i].val-mytop.first),Graph[mytop.second][i].ver ) );
        }
    }

    return;
}

int main()
{
    Int i,j;
    Int a,b,c;
    gr help;
    Int cur;

    memset(LU,0,sizeof(LU));
    memset(TFO,false,sizeof(TFO));

    scanf("%I64d %I64d",&n,&m);

    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d %I64d",&a,&b,&c);

        help.ver=a;
        help.val=c;

        Graph[b].push_back(help);

        help.ver=b;

        Graph[a].push_back(help);
    }

    Djikstra();

    if (LU[n]==0)
    {
        printf("-1\n");
        return 0;
    }

    cur=n;

    while(cur!=0)
    {
        L++;
        Path[L]=cur;

        cur=LU[cur];
    }

    for (i=L;i>=1;i--)
    {
        printf("%I64d ",Path[i]);
    }
    printf("\n");

    return 0;
}