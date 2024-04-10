#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n;
vector<int> Graph[500111];
int seq[500111];

int parent[500111];
int depth[500111];

int Ldad[500111];
int Rdad[500111];

vector<int> kids[500111];

int labels[500111];
int labelCtr = 0;

void DFS(int ver,int dad)
{
    parent[ver] = dad;
    depth[ver] = depth[dad] + 1;

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i] == dad)
            continue;

        kids[ver].push_back(Graph[ver][i]);

        DFS(Graph[ver][i], ver);
    }

    return;
}

int MIN(int a,int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int MAX(int a,int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int i,j;
    int a,b;

    scanf("%d",&n);

    for (i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    for (i=1;i<=n;i++)
    {
        scanf("%d",&seq[i]);
    }

    if (seq[1] != 1)
    {
        printf("No\n");
        return 0;
    }

    DFS(seq[1], 0);

    for (i=1;i<n;i++)
    {
        if (depth[ seq[i] ] > depth[ seq[i+1] ])
        {
            printf("No\n");
            return 0;
        }
    }

    for (i=1;i<=n;i++)
    {
        Ldad[i] = n+1;
        Rdad[i] = 0;
    }

    for (i=1;i<=n;i++)
    {
        int dad = parent[ seq[i] ];

        Ldad[dad] = MIN(Ldad[dad], i);
        Rdad[dad] = MAX(Rdad[dad], i);
    }

    for (i=1;i<=n;i++)
    {
        for (j=Ldad[i];j<=Rdad[i];j++)
        {
            if (parent[ seq[j] ] != i)
            {
                printf("No\n");
                return 0;
            }
        }
    }

    labels[1] = 0;

    for (i=1;i<=n;i++)
    {
        labelCtr++;
        for (j=0;j<kids[ seq[i] ].size();j++)
        {
            labels[ kids[ seq[i] ][j] ] = labelCtr;
        }
    }

    for (i=1;i<n;i++)
    {
        if (labels[ seq[i] ] > labels[ seq[i+1] ])
        {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");

    return 0;
}