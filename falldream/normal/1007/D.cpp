#include<bits/stdc++.h>
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
#define Rev(x) ((x&1)?x+1:x-1)
namespace SAT2
{
    #define MX 2*(100000*2+10000+10000*17*17*2)
    vector<int> v[MX+5],V[MX+5];
    int n,b[MX+5],dn,q[MX+5],mark[MX+5],num,yes[MX+5];
    void ins(int f,int t)
    {
        v[f].push_back(t);
        v[Rev(t)].push_back(Rev(f));
        V[t].push_back(f);
        V[Rev(f)].push_back(Rev(t));
    }
    void dfs(int x)
    {
        b[x]=1;
        for(int i=0;i<v[x].size();++i)
            if(!b[v[x][i]]) dfs(v[x][i]);
        q[++dn]=x;
    }
    void rdfs(int x)
    {
        mark[x]=num;
        for(int i=0;i<V[x].size();++i)
            if(!mark[V[x][i]]) rdfs(V[x][i]);
    }
    bool Solve()
    {
        for(int i=1;i<=n;++i)
            if(!b[i]) dfs(i);
        for(int i=n;i;--i)
            if(!mark[q[i]]) ++num,rdfs(q[i]);
        for(int i=1;i<=n;++i) if(mark[i]==mark[Rev(i)]) return false;
        for(int i=1;i<=n;++i) yes[mark[i]>mark[Rev(i)]?i:Rev(i)]=1;
        return true;
    }
}
vector<int> v[MN*4+5];
int n,m,head[MN+5],cnt,top[MN+5],size[MN+5],mx[MN+5],fa[MN+5],dep[MN+5],dfn[MN+5],dn,id[MN*4+5],L[MN*4+5],R[MN*4+5];
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
    e[++cnt]=(edge){t,head[f]};head[f]=cnt;
    e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}
void Pre(int x,int f)
{
    fa[x]=f;size[x]=1;
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=f)
        {
            dep[e[i].to]=dep[x]+1;
            Pre(e[i].to,x);
            size[x]+=size[e[i].to];
            if(size[e[i].to]>size[mx[x]]) mx[x]=e[i].to;
        }
}
void Dfs(int x,int tp)
{
    top[x]=tp;dfn[x]=++dn;
    if(mx[x]) Dfs(mx[x],tp);
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=fa[x]&&e[i].to!=mx[x]) Dfs(e[i].to,e[i].to);
}
void Build(int x,int l,int r)
{
    L[x]=++cnt;R[x]=(cnt+=v[x].size());
    if(x>1) SAT2::ins(R[x>>1]*2-1,L[x]*2-1);
    for(int j=0;j<v[x].size();++j)
    {
        //cout<<l<<" "<<r<<" "<<v[x][j]<<endl;
        SAT2::ins(v[x][j],(L[x]+1+j)*2-1);
        SAT2::ins((L[x]+j)*2-1,(L[x]+1+j)*2-1);
        SAT2::ins((L[x]+j)*2-1,Rev(v[x][j]));
    }
    if(l<r)
    {
        int mid=l+r>>1;
        Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
    }
}
void Insert(int x,int l,int r,int L,int R,int f)
{
    if(l==L&&r==R) return v[x].push_back(f);
    int mid=l+r>>1;
    if(R<=mid) Insert(x<<1,l,mid,L,R,f);
    else if(L>mid) Insert(x<<1|1,mid+1,r,L,R,f);
    else Insert(x<<1,l,mid,L,mid,f),Insert(x<<1|1,mid+1,r,mid+1,R,f);
}
void Ins(int x,int y,int from)
{
    for(;top[x]!=top[y];x=fa[top[x]])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        Insert(1,1,n,dfn[top[x]],dfn[x],from);
    }
    if(dfn[x]>dfn[y]) swap(x,y);
    if(dfn[x]<dfn[y]) Insert(1,1,n,dfn[x]+1,dfn[y],from);
}
int main()
{
    n=read();
    for(int i=1;i<n;++i) ins(read(),read());
    Pre(1,0);Dfs(1,1);cnt=m=read();
    for(int i=1;i<=m;++i)
    {
        int a=read(),b=read(),c=read(),d=read();
        Ins(a,b,i*2-1);Ins(c,d,i*2);
    }
    Build(1,1,n);SAT2::n=cnt*2;
    if(!SAT2::Solve()) puts("NO");
    else
    {
        puts("YES");
        for(int i=1;i<=m;++i) printf("%d\n",SAT2::yes[i*2]+1);
    }
    return 0;
}