#include<iostream>
#include<cstdio>
using namespace std;
int t,n,ans[101][101],d[101];
bool g[101][101];
bool dfs(int k,int f,int s)
{
    ans[f][k]=1;
    ans[k][f]=-1;
    if(k==s&&f)
        return 1;
    for(register int i=k+1;i<=n;++i)
        if(!g[i][k]&&!g[k][i])
        {
            g[i][k]=g[k][i]=1;
            --d[k];
            --d[i];
            if(dfs(i,k,s))
                return 1;
            ++d[k];
            ++d[i];
            g[i][k]=g[k][i]=0;
        }
    for(register int i=1;i<k;++i)
        if(!g[i][k]&&!g[k][i])
        {
            g[i][k]=g[k][i]=1;
            --d[k];
            --d[i];
            if(dfs(i,k,s))
                return 1;
            ++d[k];
            ++d[i];
            g[i][k]=g[k][i]=0;
        }
    return 0;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(register int i=1;i<=n;++i)
            d[i]=n-1;
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=n;++j)
                ans[i][j]=g[i][j]=g[j][i]=0;
        for(register int i=1;i<=n;++i)
            while(d[i]>1)
                dfs(i,0,i);
        for(register int i=1;i<n;++i)
            for(register int j=i+1;j<=n;++j)
                printf("%d ",ans[i][j]);
        puts("");
    }
    return 0;
}