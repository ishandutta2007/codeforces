#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define MN 100000
#define MB 80
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,size[MN+5],mx[MN+5],top[MN+5],dfn[MN+5],head[MN+5],cnt,dn,p[MN+5],a[MN+5],fa[MN+5],block[MN+5],ans,pt[MN+5];
int v[MN/MB+15][MB+5],val[MN+5],s[MN+5],num[MN+5],suf[MN/MB+5][MB+5],rk[MN/MB+5][MB+5];
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
    e[++cnt]=(edge){t,head[f]};head[f]=cnt;
    e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}
void Pre(int x,int fa)
{
    size[x]=1;mx[x]=0;
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=fa)
        {
            Pre(e[i].to,x);
            size[x]+=size[e[i].to];
            if(size[e[i].to]>size[mx[x]]) mx[x]=e[i].to;
        }
}
void Dfs(int x,int tp)
{
  //  cout<<x<<" "<<tp<<endl;
    top[x]=tp;dfn[x]=++dn;s[dn]=a[x];p[dn]=x;
    if(mx[x]) Dfs(mx[x],tp);
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=fa[x]&&e[i].to!=mx[x])
            Dfs(e[i].to,e[i].to);
}
void Mark(int x,int V)
{
   // cout<<"MK"<<endl;
    val[x]+=V;ans-=suf[x][pt[x]];
    while(pt[x]&&v[x][pt[x]]+val[x]>=0) --pt[x];
    while(pt[x]<num[x]&&v[x][pt[x]+1]+val[x]<0) ++pt[x];
    ans+=suf[x][pt[x]];
}
void Simp(int x)
{
    suf[x][1]=1;int nn=num[x];num[x]=1;
    for(int i=2;i<=nn;++i)
        if(v[x][i]!=v[x][num[x]]) v[x][++num[x]]=v[x][i],suf[x][num[x]]=1;
        else ++suf[x][num[x]];
    for(int i=2;i<=num[x];++i) suf[x][i]+=suf[x][i-1];
    for(int i=1;i<=num[x]+1;++i) if(i>num[x]||v[x][i]+val[x]>=0)
    {
     //   cout<<"pt="<<i-1<<" "<<suf[x][i-1]<<endl;
        pt[x]=i-1;
        ans+=suf[x][pt[x]];
        break;
    }
}
bool cmp(int x,int y){return s[x]<s[y];}
void Build(int x)
{
  //  cout<<"Build"<<x<<endl;
    int lt=(x-1)*MB+1,rt=min(n,x*MB);num[x]=0;
    for(int i=lt;i<=rt;++i) v[x][++num[x]]=s[i],rk[x][num[x]]=i;
    sort(v[x]+1,v[x]+num[x]+1);
    sort(rk[x]+1,rk[x]+num[x]+1,cmp);
   // for(int i=1;i<=num[x];++i) cout<<x<<" "<<i<<" "<<v[x][i]<<endl;
    Simp(x);
}
int A[MB+5],B[MB+5];
void ReBuild(int x,int l,int r,int V)
{
  //  cout<<"Rebuild"<<x<<" "<<l<<" "<<r<<" "<<V<<endl;
    ans-=suf[x][pt[x]];
    int lt=(x-1)*MB+1,rt=min(n,x*MB);num[x]=0;
    for(int i=l;i<=r;++i) s[i]+=V;
    int t1=0,t2=0;
    for(int i=1;i<=rt-lt+1;++i)
        if(rk[x][i]>=l&&rk[x][i]<=r) A[++t1]=rk[x][i];
        else B[++t2]=rk[x][i];
    for(int i=1,j=1;i<=t1||j<=t2;)
        if(i<=t1&&(j>t2||s[A[i]]<=s[B[j]])) v[x][++num[x]]=s[A[i]],rk[x][num[x]]=A[i],++i;
        else v[x][++num[x]]=s[B[j]],rk[x][num[x]]=B[j],++j;
    
    Simp(x);
}
void Mod(int l,int r,int v)
{
    for(int i=block[l]+1;i<block[r];++i) Mark(i,v);
    ReBuild(block[l],l,min(block[l]*MB,r),v);
    if(block[l]!=block[r])
        ReBuild(block[r],(block[r]-1)*MB+1,r,v);
}
#define INF 10000000
int main()
{
    n=read();m=read();
    for(int i=2;i<=n;++i) ins(fa[i]=read(),i);
    for(int i=1;i<=n;++i) a[i]=read();
    Pre(1,0);Dfs(1,1);
    for(int i=1;i<=n;++i) block[i]=(i-1)/MB+1;
    for(int i=1;i<=block[n];++i) Build(i);
    for(int i=1;i<=m;++i)
    {
        int x=read(),v=-1;if(x<0) x=-x,v=1;
        Mod(dfn[x],dfn[x],-v*INF);
        for(x=fa[x];x;x=fa[top[x]]) Mod(dfn[top[x]],dfn[x],v);
        printf("%d ",ans);
    }
    return 0;
}