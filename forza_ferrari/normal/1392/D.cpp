#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,a[200005],ans,nxt[200005];
bool vis[200005];
int dfs(int k)
{
    if(vis[k])
        return -1<<30;
    if(nxt[nxt[k]]==k)
        return 0;
    vis[k]=1;
    return dfs(nxt[k])+1;
}
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans=0;
        bool flag=1;
        for(register int i=1;i<=n;++i)
        {
            char c=getchar();
            while(c!='R'&&c!='L')
                c=getchar();
            a[i]=(c=='R'? 1:-1);
            if(i+a[i]==0)
                nxt[i]=n;
            else
                if(i+a[i]>n)
                    nxt[i]=1;
                else
                    nxt[i]=i+a[i];
            if(i>1&&a[i]!=a[i-1])
                flag=0;
        }
        if(flag)
        {
            if(a[2]==1)
            {
                a[2]=-1;
                nxt[2]=1;
            }
            else
            {
                a[2]=1;
                nxt[2]=3;
            }
            ans=1;
        }
        for(register int i=1;i<=n;++i)
        {
            if(vis[i])
                continue;
            if(i==1&&a[i]==1&&a[n]==-1)
            {
                ans+=max((dfs(i)+1)/3,0ll);
                continue;
            }
            if(i==n&&a[i]==-1&&a[1]==1)
            {
                ans+=max((dfs(i)+1)/3,0ll);
                continue;
            }
            if(a[i]==1&&a[i-1]==-1)
                ans+=max((dfs(i)+1)/3,0ll);
            if(a[i]==-1&&a[i+1]==1)
                ans+=max((dfs(i)+1)/3,0ll);
        }
        for(register int i=1;i<=n;++i)
            a[i]=nxt[i]=vis[i]=0;
        printf("%lld\n",ans);
    }
    return 0;
}