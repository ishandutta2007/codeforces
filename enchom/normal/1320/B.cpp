#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n,m;
vector<int> Graph[200111];
vector<int> Forw[200111];
int k;
int p[200111];

bool TFO[200111];
int qL;
int q[200111];
int dst[200111];

void BFS(int S)
{
    int i;

    for (i=1;i<=n;i++)
    {
        dst[i] = -1;
        TFO[i] = false;
    }
    dst[S] = 0;
    TFO[S] = true;
    q[1] = S;
    qL = 1;

    int uk = 1;

    while(uk <= qL)
    {
        int v = q[uk];

        for (i=0;i<Graph[v].size();i++)
        {
            int nv = Graph[v][i];

            if (!TFO[nv])
            {
                TFO[nv] = true;
                dst[nv] = dst[v] + 1;
                qL++;
                q[qL] = nv;
            }
        }

        uk++;
    }
}

int main()
{
    int i,j;

    scanf("%d %d",&n,&m);

    for (i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        Graph[b].push_back(a);
        Forw[a].push_back(b);
    }

    scanf("%d",&k);

    for (i=1;i<=k;i++)
    {
        scanf("%d",&p[i]);
    }

    BFS(p[k]);

    int minReb = 0, maxReb = 0;
    for (i=1;i<k;i++)
    {
        int curD = dst[ p[i] ];
        int nextD = dst[ p[i+1] ];

        if (curD - 1 != nextD)
        {
            minReb++;
            maxReb++;
        }
        else
        {
            int ctr = 0;
            for (j=0;j<Forw[ p[i] ].size();j++)
            {
                if (dst[ Forw[ p[i] ][j] ] == nextD)
                    ctr++;
            }

            if (ctr > 1)
            {
                maxReb++;
            }
        }
    }

    printf("%d %d\n",minReb,maxReb);

    return 0;
}