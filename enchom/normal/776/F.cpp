#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n,m;
pair<int,int> diags[100111];

bool MS(pair<int,int> a,pair<int,int> b)
{
    return (a.second-a.first+1)<(b.second-b.first+1);
}

int NextBFF[100111];
int PrevBFF[100111];

void Kill(int x)
{
    NextBFF[ PrevBFF[x] ]=NextBFF[x];
    PrevBFF[ NextBFF[x] ]=PrevBFF[x];

    return;
}

vector<int> Regions[100111];
int Order[100111];

bool SO(int a,int b)
{
    int uk1=(int)Regions[a].size()-1;
    int uk2=(int)Regions[b].size()-1;

    while(uk1>=0 && uk2>=0)
    {
        if (Regions[a][uk1]<Regions[b][uk2])
        return true;
        else if (Regions[a][uk1]>Regions[b][uk2])
        return false;
        else
        {
            uk1--;
            uk2--;
        }
    }

    if (uk1<0 && uk2>=0)
    return true;
    else
    return false;
}

bool SOpen(int a,int b)
{
    return diags[a].second>diags[b].second;
}

vector<int> Graph[100111];

vector<int> Opens[100111];
vector<int> Closes[100111];
int ID[100111];

int S[100111];
int sL=0;

void AddEdge(int a,int b)
{
    Graph[ ID[a] ].push_back( ID[b] );
    Graph[ ID[b] ].push_back( ID[a] );

    return;
}

///Centroid decomp

int Color[100111];
bool killed[100111];
int sz[100111];
vector<int> vers;

void DFS(int ver,int dad)
{
    int i;

    sz[ver]=1;
    vers.push_back(ver);

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i]==dad || killed[ Graph[ver][i] ])
        continue;

        DFS(Graph[ver][i],ver);

        sz[ver]+=sz[ Graph[ver][i] ];
    }

    return;
}

void Solve(int ver,int depth)
{
    int i,j;
    int centroid;
    bool bad;
    int v;
    int limit;

    vers.clear();
    DFS(ver,0);

    limit=sz[ver]/2;

    for (i=0;i<vers.size();i++)
    {
        v=vers[i];
        bad=false;

        for (j=0;j<Graph[v].size();j++)
        {
            if (killed[ Graph[v][j] ] || sz[ Graph[v][j] ]>sz[v])
            continue;

            if (sz[ Graph[v][j] ]>limit)
            {
                bad=true;
                break;
            }
        }

        if (sz[ver]-sz[v]>limit)
        bad=true;

        if (!bad)
        {
            centroid=v;
            break;
        }
    }

    killed[centroid]=true;
    Color[centroid]=depth;

    for (i=0;i<Graph[centroid].size();i++)
    {
        if (killed[ Graph[centroid][i] ])
        continue;

        Solve(Graph[centroid][i],depth+1);
    }

    return;
}

int main()
{
    int i,j;
    int a,b;

    scanf("%d %d",&n,&m);

    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);

        if (a<b)
        diags[i]=make_pair(a,b);
        else
        diags[i]=make_pair(b,a);
    }

    sort(diags+1,diags+1+m,MS);

    for (i=1;i<=n;i++)
    {
        NextBFF[i]=i+1;
        PrevBFF[i]=i-1;
    }
    NextBFF[0]=1;
    PrevBFF[n+1]=n;

    for (i=1;i<=m;i++)
    {
        a=diags[i].first;
        b=diags[i].second;

        while(a!=b)
        {
            Regions[i].push_back(a);

            if (a!=diags[i].first && a!=diags[i].second)
            Kill(a);

            a=NextBFF[a];
        }

        Regions[i].push_back(b);
    }

    a=1;
    while(a<=n)
    {
        Regions[m+1].push_back(a);

        a=NextBFF[a];
    }

    m++;
    diags[m]=make_pair(1,n);

    for (i=1;i<=m;i++)
    {
        Order[i]=i;
    }

    sort(Order+1,Order+1+m,SO);

    for (i=1;i<=m;i++)
    {
        ID[ Order[i] ]=i;
    }

    ///Build tree

    for (i=1;i<=m;i++)
    {
        Opens[ diags[i].first ].push_back(i);
        Closes[ diags[i].second ].push_back(i);
    }

    for (i=1;i<=n;i++)
    {
        if (!Opens[i].empty())
        sort(Opens[i].begin(),Opens[i].end(),SOpen);
    }

    for (i=1;i<=n;i++)
    {
        for (j=0;j<Closes[i].size();j++)
        {
            sL--;
        }

        for (j=0;j<Opens[i].size();j++)
        {
            if (sL>0)
            AddEdge(S[sL],Opens[i][j]);

            sL++;
            S[sL]=Opens[i][j];
        }
    }

    ///Centroid

    Solve(1,1);

    for (i=1;i<=m;i++)
    {
        printf("%d",Color[i]);

        if (i!=m)
        printf(" ");
    }
    printf("\n");

    return 0;
}