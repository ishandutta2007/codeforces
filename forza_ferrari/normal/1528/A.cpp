#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
struct edge
{
    int nxt,to;
}e[100001<<1];
int t,n,tot,h[100001],pos[100001][2],dp[100001][2];
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
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void dfs(int k,int f)
{
    dp[k][0]=dp[k][1]=0;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k);
        dp[k][0]+=max(dp[e[i].to][0]+abs(pos[k][0]-pos[e[i].to][0]),dp[e[i].to][1]+abs(pos[k][0]-pos[e[i].to][1]));
        dp[k][1]+=max(dp[e[i].to][0]+abs(pos[k][1]-pos[e[i].to][0]),dp[e[i].to][1]+abs(pos[k][1]-pos[e[i].to][1]));
    }
}
signed main()
{
    t=read();
    while(t--)
    {
        n=read();
        tot=0;
        for(int i=1;i<=n;++i)
        {
            h[i]=0;
            pos[i][0]=read(),pos[i][1]=read();
        }
        for(int i=1;i<n;++i)
        {
            int x=read(),y=read();
            add(x,y);
            add(y,x);
        }
        dfs(1,0);
        cout<<max(dp[1][0],dp[1][1])<<'\n';
    }
    return 0;
}