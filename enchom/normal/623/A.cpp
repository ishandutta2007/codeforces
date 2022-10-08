#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n,m;
vector<int> Graph[100111];
bool isB[100111];
char vals[100111];

bool edges[511][511];
bool TFO[511];

bool inG1[511];
vector<int> G1,G2;

void DFS(int ver)
{
    if (TFO[ver])
    return;

    TFO[ver]=true;
    G1.push_back(ver);
    inG1[ver]=true;

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        DFS(Graph[ver][i]);
    }

    return;
}

void NO()
{
    printf("No\n");
    return;
}

void YES()
{
    int i;

    printf("Yes\n");

    for (i=1;i<=n;i++)
    {
        printf("%c",vals[i]);
    }
    printf("\n");

    return;
}

int main()
{
    int i,j;
    int a,b;
    int uk;

    scanf("%d %d",&n,&m);

    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);

        edges[a][b]=true;
        edges[b][a]=true;
    }

    for (i=1;i<=n;i++)
    {
        if (Graph[i].size()==n-1)
        {
            isB[i]=true;
            vals[i]='b';
        }
    }

    for (i=1;i<=n;i++)
    {
        if (isB[i])
        continue;

        uk=0;

        while(uk<Graph[i].size())
        {
            if ( isB[ Graph[i][uk] ] )
            {
                Graph[i][uk]=Graph[i].back();
                Graph[i].pop_back();
            }
            else
            {
                uk++;
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        if (!isB[i])
        {
            DFS(i);
            break;
        }
    }

    if (i==n+1)
    {
        YES();
        return 0;
    }

    for (i=1;i<=n;i++)
    {
        if (!isB[i] && !inG1[i])
        {
            G2.push_back(i);
        }
    }

    for (i=0;i<G1.size();i++)
    {
        vals[ G1[i] ]='a';
        for (j=i+1;j<G1.size();j++)
        {
            if (!edges[ G1[i] ][ G1[j] ])
            {
                NO();
                return 0;
            }
        }
    }

    for (i=0;i<G2.size();i++)
    {
        vals[ G2[i] ]='c';
        for (j=i+1;j<G2.size();j++)
        {
            if (!edges[ G2[i] ][ G2[j] ])
            {
                NO();
                return 0;
            }
        }
    }

    YES();

    return 0;
}