#include<iostream>
#include<cstdio>
using namespace std;
struct edge
{
    int nxt,to;
}e[200001<<1];
int n,a[200001],maxn[200001],root,tot,h[200001];
long long ans;
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
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k);
        maxn[k]=max(maxn[k],maxn[e[i].to]);
    }
    if(k!=root&&maxn[k]<a[k])
    {
        ans+=a[k]-maxn[k];
        maxn[k]=a[k];
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
        if(a[i]>a[root])
            root=i;
    }
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    dfs(root,0);
    int tmp[2]={0};
    for(int i=h[root];i;i=e[i].nxt)
    {
        if(maxn[e[i].to]>tmp[0])
        {
            tmp[1]=tmp[0];
            tmp[0]=maxn[e[i].to];
        }
        else
            tmp[1]=max(tmp[1],maxn[e[i].to]);
    }
    cout<<ans+a[root]+a[root]-tmp[0]-tmp[1]<<'\n';
    return 0;
}