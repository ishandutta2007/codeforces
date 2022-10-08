#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;
#define MOD 1000000007LL

int n,d;
vector<int> Graph[3001];
int a[3001];
int LIMIT;
int V;

Int DFS(int ver,int dad)
{
    if (a[ver]>LIMIT || (a[ver]==LIMIT && ver<V))
    return 0LL;

    if (LIMIT-a[ver]>d)
    return 0LL;

    int i;
    Int ways=1;
    Int val;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i]==dad)
        continue;

        val=(DFS(Graph[ver][i],ver)+1LL);

        ways=ways*val;
        ways%=MOD;
    }

    return ways;
}

int main()
{
    int i;
    int A,B;
    Int ans=0;
    Int val;

    scanf("%d %d",&d,&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    for (i=1;i<n;i++)
    {
        scanf("%d %d",&A,&B);

        Graph[A].push_back(B);
        Graph[B].push_back(A);
    }

    for (i=1;i<=n;i++)
    {
        LIMIT=a[i];
        V=i;

        val=DFS(i,0);

        ans+=val;

        if (ans>=MOD)
        ans-=MOD;
    }

    printf("%I64d\n",ans);

    return 0;
}