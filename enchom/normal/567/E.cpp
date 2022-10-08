#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
typedef long long Int;

struct edge
{
    int a,b,c;
};

int n,m,s,t;
vector<int> Graph[100111];
edge edges[100111];

Int D[100111];
bool TFO[100111];
priority_queue< pair<Int,int> > pq;

void Dijkstra(int ver)
{
    int i,j;
    pair<Int,int> mytop;
    int v,nv,dd;

    while(!pq.empty())
    pq.pop();

    for (i=1;i<=n;i++)
    {
        D[i]=-1;
        TFO[i]=false;
    }

    D[ver]=0;
    pq.push(make_pair(0,ver));

    for (i=1;i<=n;i++)
    {
        if (pq.empty())
        break;

        do
        {
            if (pq.empty())
            break;

            mytop=pq.top();
            pq.pop();
        }while( TFO[mytop.second] );

        v=mytop.second;

        if (TFO[v])
        break;

        TFO[v]=true;

        for (j=0;j<Graph[v].size();j++)
        {
            nv=edges[ Graph[v][j] ].b;
            dd=edges[ Graph[v][j] ].c;

            if (TFO[nv])
            continue;

            if (D[nv]>D[v]+(Int)dd || D[nv]==-1)
            {
                D[nv]=D[v]+(Int)dd;

                pq.push(make_pair(-D[nv],nv));
            }
        }
    }

    return;
}

vector<int> Path;
int order[100111];
int edgeid[100111];
bool tokill[100111];

bool FindPath(int ver)
{
    if (TFO[ver])
    return false;

    TFO[ver]=true;

    int i;

    order[ver]=Path.size();
    Path.push_back(ver);

    if (ver==t)
    return true;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (FindPath( edges[ Graph[ver][i] ].b ))
        {
            edgeid[ver]=Graph[ver][i];

            Graph[ver][i]=Graph[ver].back();
            Graph[ver].pop_back();

            return true;
        }
    }

    Path.pop_back();
    order[ver]=-1;

    return false;
}

int memreach[100111];

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int MaxReach(int ver)
{
    if (memreach[ver]!=-2)
    return memreach[ver];

    int i;
    int ans;

    ans=order[ver];

    for (i=0;i<Graph[ver].size();i++)
    {
        ans=MAX(ans,MaxReach( edges[ Graph[ver][i] ].b ));
    }

    memreach[ver]=ans;

    return ans;
}

int thectr[100111];

Int D1[100111];

int main()
{
    int i;
    Int themaxlen;
    int reach;
    int sum=0;
    int h;
    Int bestlen;
    bool isbad;

    scanf("%d %d %d %d",&n,&m,&s,&t);

    for (i=1;i<=m;i++)
    {
        scanf("%d %d %d",&edges[i].a,&edges[i].b,&edges[i].c);

        Graph[ edges[i].a ].push_back(i);
    }

    Dijkstra(s);

    bestlen=D[t];

    memset(order,-1,sizeof(order));
    for (i=1;i<=n;i++)
    {
        Graph[i].clear();
    }

    for (i=1;i<=m;i++)
    {
        if (D[ edges[i].a ]==-1 || D[ edges[i].b ]==-1)
        continue;

        if (D[ edges[i].a ]+(Int)edges[i].c==D[ edges[i].b ])
        {
            Graph[ edges[i].a ].push_back(i);
        }
    }

    memset(TFO,false,sizeof(TFO));
    FindPath(s);

    for (i=1;i<=n;i++)
    {
        memreach[i]=-2;
    }

    for (i=0;i<Path.size();i++)
    {
        reach=MaxReach(Path[i]);

        if (reach<=i)
        continue;

        thectr[i]++;
        thectr[reach]--;
    }

    sum=0;
    for (i=0;i<Path.size();i++)
    {
        sum+=thectr[i];

        if (sum>0)
        {
            tokill[i]=true;
        }
    }

    for (i=1;i<=n;i++)
    {
        D1[i]=D[i];
        Graph[i].clear();
    }

    for (i=1;i<=m;i++)
    {
        Graph[ edges[i].b ].push_back(i);

        h=edges[i].a;
        edges[i].a=edges[i].b;
        edges[i].b=h;
    }

    Dijkstra(t);

    for (i=1;i<=m;i++)
    {
        h=edges[i].a;
        edges[i].a=edges[i].b;
        edges[i].b=h;
    }

    for (i=1;i<=m;i++)
    {
        if (D1[ edges[i].a ]==-1 || D[ edges[i].b ]==-1)
        {
            printf("NO\n");
            continue;
        }

        themaxlen=bestlen-(D1[ edges[i].a ]+D[ edges[i].b ]);

        if (themaxlen!=(Int)edges[i].c)
        {
            if (themaxlen<2)
            printf("NO\n");
            else
            printf("CAN %lld\n",(Int)edges[i].c-(themaxlen-1LL));
        }
        else
        {
            isbad=false;

            if (order[ edges[i].a ]==-1 || order[ edges[i].b ]==-1)
            isbad=true;
            else if (order[ edges[i].a ]+1!=order[ edges[i].b ])
            isbad=true;
            else
            {
                if (tokill[ order[ edges[i].a ] ])
                isbad=true;
            }

            if (isbad)
            {
                if (edges[i].c==1)
                printf("NO\n");
                else
                printf("CAN 1\n");
            }
            else
            printf("YES\n");
        }
    }

    return 0;
}