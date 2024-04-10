#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> Graph[300111];
int n,q;

int Sz[300111];
int Centroid[300111];
int p[300111];

void DFS(int ver)
{
    int i;
    int big=-1;
    int cen;

    Sz[ver]=1;

    for (i=0;i<Graph[ver].size();i++)
    {
        DFS(Graph[ver][i]);

        Sz[ver]+=Sz[ Graph[ver][i] ];
    }

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Sz[ Graph[ver][i] ]*2>Sz[ver])
        {
            big=Graph[ver][i];
        }
    }

    if (big!=-1)
    {
        cen=Centroid[big];

        while( (Sz[ver]-Sz[cen])*2>Sz[ver] )
        {
            cen=p[cen];
        }

        Centroid[ver]=cen;
    }
    else
    Centroid[ver]=ver;

    return;
}

int main()
{
    int i;
    int v;

    scanf("%d %d",&n,&q);

    for (i=2;i<=n;i++)
    {
        scanf("%d",&p[i]);

        Graph[ p[i] ].push_back(i);
    }

    DFS(1);

    for (i=1;i<=q;i++)
    {
        scanf("%d",&v);

        printf("%d\n",Centroid[v]);
    }

    return 0;
}