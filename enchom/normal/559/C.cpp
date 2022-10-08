#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
typedef long long Int;
#define MOD 1000000007LL

int n,m,k;
pair<int,int> cells[2011];
int F[2011][2011];
int All[2011][2011];
Int fact[300011];

vector<int> Graph[2011];

Int FastPow(Int k,Int p)
{
    if (p==0)
    return 1LL;

    Int POW=FastPow(k,p/2);

    POW=(POW*POW)%MOD;

    if (p%2==1)
    POW=(POW*k)%MOD;

    return POW;
}

Int C(Int k,Int n)
{
    Int top=fact[n];
    Int bottom=(fact[k]*fact[n-k])%MOD;

    return ( top*FastPow(bottom,MOD-2) )%MOD;
}

int AllWays(int a,int b)
{
    if (All[a][b]!=-1)
    return All[a][b];

    int H,W;

    H=cells[b].first-cells[a].first+1;
    W=cells[b].second-cells[a].second+1;

    All[a][b]=C(H-1,H+W-2);

    return All[a][b];
}

int Solve(int a,int b)
{
    if (F[a][b]!=-1)
    return F[a][b];

    int i;
    Int ans=0;
    int p;

    ans=(Int)AllWays(a,b);

    for (i=0;i<Graph[a].size();i++)
    {
        p=Graph[a][i];

        if (p==b)
        continue;

        if (cells[b].first>=cells[p].first && cells[b].second>=cells[p].second)
        {
            ans=ans-( (Int)Solve(a,p)*(Int)AllWays(p,b) )%MOD;
            if (ans<0)
            ans+=MOD;
        }
    }

    F[a][b]=ans;

    return (int)ans;
}

int main()
{
    int i,j;

    fact[0]=1LL;
    for (i=1;i<=300000;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
    }

    memset(F,-1,sizeof(F));
    memset(All,-1,sizeof(All));

    scanf("%d %d %d",&n,&m,&k);

    for (i=1;i<=k;i++)
    {
        scanf("%d %d",&cells[i].first,&cells[i].second);
    }
    k++;
    cells[k]=make_pair(1,1);

    k++;
    cells[k]=make_pair(n,m);

    for (i=1;i<=k;i++)
    {
        for (j=1;j<=k;j++)
        {
            if (i==j)
            continue;

            if (cells[j].first>=cells[i].first && cells[j].second>=cells[i].second)
            {
                Graph[i].push_back(j);
            }
        }
    }

    printf("%d\n",Solve(k-1,k));

    return 0;
}