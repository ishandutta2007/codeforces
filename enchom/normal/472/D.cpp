#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

struct edge
{
    int a,b,c;
};

int n;
int grid[2001][2001];
edge edges[2000001];
int eL=0;
vector< pair<int,int> > Graph[2001];
bool TFO[2001];

bool ALERT=false;

int father[2001];

bool S(edge a,edge b)
{
    return a.c<b.c;
}

int Find(int ver)
{
    if (father[ver]==0)
    return ver;
    else
    {
        father[ver]=Find(father[ver]);
        return father[ver];
    }
}

void Dist(int org,int ver,int dist)
{
    TFO[ver]=true;

    if (grid[org][ver]!=dist)
    {
        ALERT=true;
        return;
    }

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (TFO[ Graph[ver][i].first ])
        continue;

        Dist(org,Graph[ver][i].first,dist+Graph[ver][i].second);

        if (ALERT)
        return;
    }

    return;
}

int main()
{
    int i,j;
    int r1,r2;
    int ctr=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            scanf("%d",&grid[i][j]);
        }
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (i==j)
            {
                if (grid[i][j]!=0)
                {
                    printf("NO\n");
                    return 0;
                }
            }
            else if (i>j)
            {
                if (grid[i][j]!=grid[j][i])
                {
                    printf("NO\n");
                    return 0;
                }
            }
            else
            {
                eL++;
                edges[eL].a=i;
                edges[eL].b=j;
                edges[eL].c=grid[i][j];
            }
        }
    }

    if (n==1)
    {
        printf("YES\n");
        return 0;
    }

    sort(edges+1,edges+1+eL,S);

    for (i=1;i<=eL;i++)
    {
        r1=Find(edges[i].a);
        r2=Find(edges[i].b);

        if (r1!=r2)
        {
            ctr++;

            if (edges[i].c<1)
            {
                printf("NO\n");
                return 0;
            }

            Graph[ edges[i].a ].push_back( make_pair(edges[i].b,edges[i].c) );
            Graph[ edges[i].b ].push_back( make_pair(edges[i].a,edges[i].c) );

            father[r1]=r2;

            if (ctr==n-1)
            break;
        }
    }

    for (i=1;i<=n;i++)
    {
        memset(TFO,false,sizeof(TFO));
        Dist(i,i,0);
        if (ALERT)
        break;
    }

    if (ALERT)
    printf("NO\n");
    else
    printf("YES\n");

    return 0;
}