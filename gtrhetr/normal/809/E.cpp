#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define mod 1000000007
  
struct node { int t,v,next; }a[400010];
  
int fa[400010][20],head[400010],phi[400010],dfn[400010],v[400010],from[400010];
int dep[400010],ny[400010],ans[400010],f[400010],g[400010],s[400010];
int st[400010],c[400010],p[400010],n,pt,cl,sum,num,top,tot,ans1;
bool bo[400010];
  
inline int rd()
{
    int x=0;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar());
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x;
}
  
inline bool cmp(int x,int y) { return dfn[x]<dfn[y]; }
  
inline void add(int x,int y)
{
    a[++tot].t=y;a[tot].v=dep[y]-dep[x];
    a[tot].next=head[x];head[x]=tot;
}
  
inline void get_phi()
{
    phi[1]=1;pt=0;
    for (int i=2;i<=n;i++)
    {
        if (!bo[i]) p[++pt]=i,phi[i]=i-1;
        for (int j=1;j<=pt;j++)
        {
            if (i*p[j]>n) break;
            bo[i*p[j]]=true;
            if (i%p[j]) phi[i*p[j]]=phi[i]*phi[p[j]];
            else { phi[i*p[j]]=phi[i]*p[j];break; }
        }
    }
    for (int i=1;i<=n;i++) bo[i]=false;
}
  
inline int lca(int x,int y)
{
    if (dep[x]<dep[y]) swap(x,y);
    int t=dep[x]-dep[y];
    for (int i=18;~i;i--) if ((1<<i)&t) x=fa[x][i];
    if (x==y) return x;
    for (int i=18;~i;i--) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
  
inline void dfs(int x,int y)
{
    dfn[x]=++cl;
    for (int i=1;i<=18;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
    for (int i=head[x];i;i=a[i].next)
    {
        int t=a[i].t;
        if (t==y) continue;
        dep[t]=dep[x]+1;
        fa[t][0]=x;dfs(t,x);
    }
}
  
inline void dp1(int x)
{
    f[x]=s[x]=0;
    for (int i=head[x];i;i=a[i].next)
    {
        int t=a[i].t;
        dp1(t);
        f[x]=((f[x]+f[t])%mod+1ll*s[t]*a[i].v%mod)%mod;
        s[x]=(s[x]+s[t])%mod;
    }
    if (bo[x]) s[x]=(s[x]+phi[v[x]])%mod;
}
  
inline void dp2(int x)
{
    for (int i=head[x];i;i=a[i].next)
    {
        int t=a[i].t;
        g[t]=((g[x]+f[x]-f[t])%mod+1ll*(sum-s[t]*2)*a[i].v%mod)%mod;
        dp2(t);
    }
}
  
inline int solve()
{
    tot=sum=pt=0;
    for (int i=1;i<=num;i++) sum=(sum+phi[v[c[i]]])%mod;
    sort(c+1,c+num+1,cmp);
    st[top=1]=1;
    for (int i=1;i<=num;i++)
    {
        int x=c[i],y=lca(x,st[top]);
        p[++pt]=x;p[++pt]=y;
        while (dep[y]<dep[st[top-1]]) { add(st[top-1],st[top]);top--; }
        if (dep[y]<dep[st[top]]) add(y,st[top--]);
        if (y!=st[top]) st[++top]=y;
        if (x!=st[top]) st[++top]=x;
    }
    for (int i=1;i<top;i++) add(st[i],st[i+1]);
    for (int i=1;i<=num;i++) bo[c[i]]=true;
    dp1(1);dp2(1);
    int res=0;
    for (int i=1;i<=num;i++) res=(res+1ll*phi[v[c[i]]]*(f[c[i]]+g[c[i]])%mod)%mod;
    for (int i=1;i<=num;i++) bo[c[i]]=false;
    for (int i=1;i<=pt;i++) head[p[i]]=0;
    return res;
}
  
int main()
{
    n=rd();tot=0;
    get_phi();
    for (int i=1;i<=n;i++) v[i]=rd(),from[v[i]]=i;
    for (int i=1;i<n;i++)
    {
        int x=rd(),y=rd();
        add(x,y);add(y,x);
    }
    cl=0;dfs(1,0);
    memset(head,0,sizeof(head));
    for (int i=1;i<=n;i++)
    {
        num=0;
        for (int j=i;j<=n;j+=i) c[++num]=from[j];
        ans[i]=solve();
    }
    for (int i=n;i;i--) for (int j=i<<1;j<=n;j+=i) ans[i]=(ans[i]-ans[j])%mod;
    ny[0]=ny[1]=1;ans1=0;
    for (int i=2;i<=n;i++) ny[i]=1ll*(-mod/i)*ny[mod%i]%mod;
    for (int i=1;i<=n;i++) ans1=(ans1+1ll*ans[i]*i%mod*ny[phi[i]]%mod)%mod;
    ans1=1ll*ans1*ny[n]%mod*ny[n-1]%mod;
    ans1=(ans1+mod)%mod;
    printf("%d\n",ans1);
    return 0;
}