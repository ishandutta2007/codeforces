#include<bits/stdc++.h>
#define MN 200000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='1') f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
ll f[MN+5],g[MN+5],h[MN+5],mx[MN+5];
int n,a[MN+5],head[MN+5],cnt,son[MN+5],ans[MN+5],ansn,mxn[MN+5];
struct edge{int to,next,w;}e[MN*2+5];
inline void ins(int f,int t)
{
    e[++cnt]=(edge){t,head[f]};head[f]=cnt;
    e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}
void dfs(int x,int fa)
{
    mx[x]=-1;
    for(int i=head[x];i;i=e[i].next) if(e[i].to!=fa)
    {
        ++son[x];dfs(e[i].to,x);
        ll v=f[e[i].to]-g[e[i].to];
        if(v>mx[x]) mx[x]=v,mxn[x]=1;
        else if(v==mx[x]) ++mxn[x];
        h[x]+=f[e[i].to];
    }
    if(!son[x]) mx[x]=0,f[x]=a[x];
    else f[x]=min(h[x],h[x]-mx[x]+a[x]),g[x]=h[x]-mx[x];
    //cout<<x<<" "<<f[x]<<" "<<g[x]<<" "<<h[x]<<" "<<mx[x]<<endl;
}
void Solve(int x,int fa,int f1,int f2)
{
    //cout<<"SOlve"<<x<<" "<<fa<<" "<<f1<<" "<<f2<<endl;
    int case1=(h[x]-mx[x]+a[x]==f[x]);
    if(f1&&case1) ans[++ansn]=x;
    for(int i=head[x];i;i=e[i].next) if(e[i].to!=fa)
    {
        int v=e[i].to;
        int g1=(f1&&case1&&(mxn[x]-(f[v]-g[v]==mx[x])>0));
        g1|=(f1&&h[x]==f[x]);
        g1|=(f2&&(mxn[x]-(f[v]-g[v]==mx[x])>0));
        int g2=(f[v]-g[v]==mx[x]);
        Solve(e[i].to,x,g1,g2);
    }
}
int main()
{   
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<n;++i) ins(read(),read());
    dfs(1,0);Solve(1,0,1,0);
    sort(ans+1,ans+1+ansn);
    printf("%lld %d\n",f[1],ansn);
    for(int i=1;i<=ansn;++i) printf("%d ",ans[i]);
    return 0;
}