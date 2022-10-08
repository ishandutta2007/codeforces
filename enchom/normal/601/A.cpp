#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

bool railway[411][411];
int n,m;
vector<int> Graph[411];

bool TFO[411];
int q[411];
int d[411];
int qL=0;
int ans=-1;

void GetPath()
{
    int uk=1;
    int v;
    int i;

    qL=1;
    q[1]=1;
    TFO[1]=true;
    d[1]=0;

    while(uk<=qL)
    {
        v=q[uk];

        if (v==n)
        {
            ans=d[uk];
            break;
        }

        for (i=0;i<Graph[v].size();i++)
        {
            if (!TFO[ Graph[v][i] ])
            {
                qL++;
                q[qL]=Graph[v][i];
                d[qL]=d[uk]+1;
                TFO[ Graph[v][i] ]=true;
            }
        }

        uk++;
    }

    return;
}

int main()
{
    int a,b;
    int i,j;

    scanf("%d %d",&n,&m);

    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);

        railway[a][b]=true;
        railway[b][a]=true;
    }

    if (railway[1][n])
    {
        for (i=1;i<=n;i++)
        {
            for (j=i+1;j<=n;j++)
            {
                if (!railway[i][j])
                {
                    Graph[i].push_back(j);
                    Graph[j].push_back(i);
                }
            }
        }
    }
    else
    {
        for (i=1;i<=n;i++)
        {
            for (j=i+1;j<=n;j++)
            {
                if (railway[i][j])
                {
                    Graph[i].push_back(j);
                    Graph[j].push_back(i);
                }
            }
        }
    }

    GetPath();

    if (ans==-1)
    printf("-1\n");
    else
    printf("%d\n",ans);

    return 0;
}