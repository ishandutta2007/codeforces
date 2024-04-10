#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;
int n;
vector<int> Graph[100111];
vector<int> Kids[100111];

void DFS(int ver,int dad)
{
    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i]==dad)
        continue;

        Kids[ver].push_back(Graph[ver][i]);

        DFS(Graph[ver][i],ver);
    }

    return;
}



int main()
{
    int i,j;
    int a,b;
    Int ans=0;
    int k;

    scanf("%d",&n);

    for (i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);

        Graph[a].push_back(b);

        Graph[b].push_back(a);
    }

    DFS(1,0);

    for (i=1;i<=n;i++)
    {
        k=Kids[i].size();

        for (j=0;j<Kids[i].size();j++)
        {
            ans+=(Int)Kids[ Kids[i][j] ].size();
        }

        ans+=( (Int)k*(Int)(k-1) )/2LL;
    }

    printf("%lld\n",ans);

    return 0;
}