#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
using namespace std;

int n;
vector<int> Graph[200111];
int col[200111];
set<int> myset;
set<int>::iterator myit;
bool TFO[200111];

void Solve(int ver)
{
    if (TFO[ver])
    return;

    TFO[ver]=true;

    int i;
    int v;
    int uk=1;

    myset.clear();

    for (i=0;i<Graph[ver].size();i++)
    {
        v=Graph[ver][i];

        if (col[v]!=-1)
        {
            myset.insert(col[v]);
        }
    }

    if (col[ver]==-1)
    {
        while(myset.find(uk)!=myset.end())
        {
            uk++;
        }

        col[ver]=uk;
        uk++;
    }
    else
    {
        myset.insert(col[ver]);
    }


    for (i=0;i<Graph[ver].size();i++)
    {
        v=Graph[ver][i];

        while(myset.find(uk)!=myset.end())
        {
            uk++;
        }

        if (col[v]==-1)
        {
            col[v]=uk;
            uk++;
        }
    }

    for (i=0;i<Graph[ver].size();i++)
    {
        Solve(Graph[ver][i]);
    }

    return;
}

int main()
{
    int i,j;
    int k=0;
    int v;
    int a,b;

    memset(col,-1,sizeof(col));

    scanf("%d",&n);

    for (i=1;i<=n-1;i++)
    {
        scanf("%d %d",&a,&b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    for (i=1;i<=n;i++)
    {
        if (Graph[i].size()>k)
        k=Graph[i].size();
    }

    k++;

    Solve(1);

    for (i=1;i<=n;i++)
    {
        for (j=0;j<Graph[i].size();j++)
        {
            v=Graph[i][j];

            if (col[v]!=-1)
            {

            }
        }
    }

    printf("%d\n",k);

    for (i=1;i<=n;i++)
    {
        printf("%d",col[i]);
        if (i!=n)
        printf(" ");
    }
    printf("\n");

    return 0;
}