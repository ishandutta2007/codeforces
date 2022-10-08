#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n,d;
int islands[40001];
int mem[31001][510];

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int Solve(int x,int dev)
{
    if (mem[x][dev+250]!=-1)
    return mem[x][dev+250];

    int canjump=d+dev;
    int ans=islands[x];

    if (canjump-1>0 && x+canjump-1<=30000)
    {
        ans=MAX(ans,islands[x]+Solve(x+canjump-1,dev-1));
    }

    if (canjump>0 && x+canjump<=30000)
    {
        ans=MAX(ans,islands[x]+Solve(x+canjump,dev));
    }

    if (canjump+1>0 && x+canjump+1<=30000)
    {
        ans=MAX(ans,islands[x]+Solve(x+canjump+1,dev+1));
    }

    mem[x][dev+250]=ans;

    return ans;
}

int main()
{
    int i;
    int k;
    int ans=0;

    memset(mem,-1,sizeof(mem));

    scanf("%d %d",&n,&d);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&k);

        islands[k]++;
    }

    ans+=islands[0];

    ans+=Solve(d,0);

    printf("%d\n",ans);

    return 0;
}