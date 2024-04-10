#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[300001],tot,ch[300001*30][2],maxn[300001*30][2],dp[300001];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void insert(int p)
{
    int node=0;
    for(int i=30;~i;--i)
    {
        if(!ch[node][(p>>i&1)^(a[p]>>i&1)])
            ch[node][(p>>i&1)^(a[p]>>i&1)]=++tot;
        node=ch[node][(p>>i&1)^(a[p]>>i&1)];
        maxn[node][a[p]>>i&1]=max(maxn[node][a[p]>>i&1],dp[p]);
    }
}
inline int query(int p)
{
    int node=0,res=0;
    for(int i=30;~i;--i)
    {
        if(ch[node][(p>>i&1)^(a[p]>>i&1)^1])
            res=max(res,maxn[ch[node][(p>>i&1)^(a[p]>>i&1)^1]][p>>i&1]);
        node=ch[node][(p>>i&1)^(a[p]>>i&1)];
        if(!node)
            break;
    }
    return res;
}
int main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=0;i<=tot;++i)
            ch[i][0]=ch[i][1]=maxn[i][0]=maxn[i][1]=0;
        tot=0;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            a[i]=read();
            ans=max(ans,dp[i]=query(i)+1);
            insert(i);
        }
        cout<<ans<<'\n';
    }
    return 0;
}