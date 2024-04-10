#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n;
vector<int> Graph[100111];
int c[100111];
bool SameColor[100111];
int ctr[100111];
int sz[100111];
int Father[100111];

void GoDown(int ver,int dad)
{
    int i;

    Father[ver]=dad;
    SameColor[ver]=true;
    sz[ver]=1;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i]==dad)
        continue;

        if (c[ver]!=c[ Graph[ver][i] ])
        SameColor[ver]=false;

        GoDown(Graph[ver][i],ver);

        sz[ver]+=sz[ Graph[ver][i] ];

        if (!SameColor[ Graph[ver][i] ])
        SameColor[ver]=false;
    }

    return;
}

bool UpperFine(int ver)
{
    if (ver==1)
    return true;

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (sz[ Graph[ver][i] ]<sz[ver])
        {
            ctr[ c[ Graph[ver][i] ] ]-=sz[ Graph[ver][i] ];
        }
    }

    ctr[ c[ver] ]--;

    ///

    if ( ctr[ c[ Father[ver] ] ] == sz[1]-sz[ver] )
    return true;

    ///

    ctr[ c[ver] ]++;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (sz[ Graph[ver][i] ]<sz[ver])
        {
            ctr[ c[ Graph[ver][i] ] ]+=sz[ Graph[ver][i] ];
        }
    }

    return false;
}

int main()
{
    int i,j;
    int a,b;
    bool bad;

    scanf("%d",&n);

    for (i=1;i<=n-1;i++)
    {
        scanf("%d %d",&a,&b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    for (i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);

        ctr[ c[i] ]++;
    }

    GoDown(1,0);

    for (i=1;i<=n;i++)
    {
        bad=false;

        for (j=0;j<Graph[i].size();j++)
        {
            if (sz[ Graph[i][j] ]<sz[i])
            {
                if (!SameColor[ Graph[i][j] ])
                {
                    bad=true;
                    break;
                }
            }
        }

        if (!bad)
        {
            if (UpperFine(i))
            {
                printf("YES\n%d\n",i);
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}