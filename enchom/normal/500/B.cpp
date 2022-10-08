#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int n;
int perm[1001];
char str[1001];
vector<int> Graph[1001];
bool TFO[1001];

vector<int> positions;
vector<int> values;

int ans[1001];

void DFS(int ver)
{
    if (TFO[ver])
    return;

    TFO[ver]=true;
    positions.push_back(ver);
    values.push_back(perm[ver]);

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        DFS(Graph[ver][i]);
    }

    return;
}

int main()
{
    int i,j;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&perm[i]);
    }

    for (i=1;i<=n;i++)
    {
        scanf("%s",str+1);

        for (j=1;j<=n;j++)
        {
            if (str[j]=='1')
            {
                Graph[i].push_back(j);
                Graph[j].push_back(i);
            }
        }
    }

    memset(TFO,false,sizeof(TFO));

    for (i=1;i<=n;i++)
    {
        if (!TFO[i])
        {
            positions.clear();
            values.clear();
            DFS(i);

            sort(positions.begin(),positions.end());
            sort(values.begin(),values.end());

            for (j=0;j<positions.size();j++)
            {
                ans[ positions[j] ]=values[j];
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        printf("%d",ans[i]);

        if (i!=n)
        printf(" ");
    }
    printf("\n");

    return 0;
}