#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n;
vector<int> Graph[2111];
int c[2111];
int root;

vector<int> subtree[2111];
bool BAD = false;

void DFS(int ver,int dad)
{
    int i,j;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i] == dad)
            continue;

        DFS(Graph[ver][i], ver);

        if (BAD)
            return;

        for (j=0;j<subtree[ Graph[ver][i] ].size();j++)
        {
            subtree[ver].push_back(subtree[ Graph[ver][i] ][j]);
        }
    }

    if (c[ver] > subtree[ver].size())
    {
        BAD = true;
        return;
    }

    subtree[ver].push_back(ver);
    int cur = subtree[ver].size() - 1;

    while(cur > c[ver])
    {
        int swp = subtree[ver][cur];
        subtree[ver][cur] = subtree[ver][cur-1];
        subtree[ver][cur-1] = swp;

        cur--;
    }
}

int values[100111];

int main()
{
    int i,j;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        int p;

        scanf("%d %d",&p,&c[i]);

        if (p == 0)
        {
            root = i;
            continue;
        }

        Graph[p].push_back(i);
        Graph[i].push_back(p);
    }

    DFS(root, 0);

    if (BAD)
    {
        printf("NO\n");
        return 0;
    }

    for (i=0;i<subtree[root].size();i++)
    {
        values[ subtree[root][i] ] = i + 1;
    }

    printf("YES\n");
    for (i=1;i<=n;i++)
    {
        printf("%d",values[i]);

        if (i != n)
            printf(" ");
    }
    printf("\n");

    return 0;
}