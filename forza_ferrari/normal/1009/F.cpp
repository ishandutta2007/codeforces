#include<iostream>
#include<cstdio>
using namespace std;
struct edge
{
    int nxt,to;
}e[1000001<<1];
int n,tot,h[1000001],tmp[1000001],*id=tmp,*dp[1000001],ans[1000001],son[1000001],len[1000001],top[1000001];
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
void print(int x)
{
    if(x>=10)
        print(x/10);
    putchar(x%10+'0');
}
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
void dfs1(int k,int f)
{
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs1(e[i].to,k);
        if(len[e[i].to]>len[son[k]])
            son[k]=e[i].to;
    }
    len[k]=len[son[k]]+1;
}
void dfs2(int k,int f)
{
    dp[k][0]=1;
    if(son[k])
    {
        dp[son[k]]=dp[k]+1;
        dfs2(son[k],k);
        ans[k]=ans[son[k]]+1;
    }
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f||e[i].to==son[k])
            continue;
        dp[e[i].to]=id;
        id+=len[e[i].to];
        dfs2(e[i].to,k);
        for(int j=1;j<=len[e[i].to];++j)
        {
            dp[k][j]+=dp[e[i].to][j-1];
            if(dp[k][j]==dp[k][ans[k]]&&j<ans[k])
                ans[k]=j;
            if(dp[k][j]>dp[k][ans[k]])
                ans[k]=j;
        }
    }
    if(dp[k][ans[k]]==1)
        ans[k]=0;
}
int main()
{
    n=read();
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    dfs1(1,0);
    dp[1]=id;
    id+=len[1];
    dfs2(1,0);
    for(int i=1;i<=n;++i)
    {
        print(ans[i]);
        puts("");
    }
    return 0;
}