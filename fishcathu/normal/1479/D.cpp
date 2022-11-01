#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=3E5+1;
ll read()
{
	ll a=0;
	char b=1,c;
	do if((c=getchar())==45)b=-1;while(c<48||c>57);
	do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
	return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N],b[N],n;
vct to[N];
int fa[N],son[N],siz[N],top[N],dep[N];
int head[N*21],L[N*21],R[N*21],val[N*21],cnt;
int y,z;
int build(int pre,int l,int r,int x)
{
    int i=++cnt;
    val[i]=val[pre]^b[x];
    if(l!=r)
    {
        int m=l+r>>1;
        if(x<=m)
        {
            L[i]=build(L[pre],l,m,x);
            R[i]=R[pre];
        }
        else
        {
            L[i]=L[pre];
            R[i]=build(R[pre],m+1,r,x);
        }
    }
    return i;
}
void dfs1(int x)
{
    siz[x]=1;
    head[x]=build(head[fa[x]],1,n,a[x]);
    for(int t:to[x])
    {
        if(t==fa[x])continue;
        fa[t]=x;
        dep[t]=dep[x]+1;
        dfs1(t);
        siz[x]+=siz[t];
        if(siz[t]>siz[son[x]])son[x]=t;
    }
}
void dfs2(int x,int p)
{
    top[x]=p;
    for(int t:to[x])
    {
        if(t!=fa[x])dfs2(t,t==son[x]?p:t);
    }
}
int lca(int l,int r)
{
    int u=top[l],v=top[r];
    while(u!=v)
    {
        dep[u]>dep[v]?u=top[l=fa[u]]:v=top[r=fa[v]];
    }
    return dep[l]<dep[r]?l:r;
}
int ask(int c,int d,int e,int f,int l,int r)
{
    if(l>z||r<y||!(val[c]^val[d]^val[e]^val[f]))return -1;
    if(l==r)return l;
    int m=l+r>>1;
    int res=ask(L[c],L[d],L[e],L[f],l,m);
    return ~res?res:ask(R[c],R[d],R[e],R[f],m+1,r);
}
int main()
{
    n=read();
	int m=read();
	const int p=1E9+7;
	b[1]=1;
	for(int i=2;i<=n;++i)b[i]=b[i-1]*2%p;
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    dfs1(1);
    dfs2(1,1);
    while(m--)
    {
        int u=read(),v=read(),w=lca(u,v);
        y=read(),z=read();
        write(ask(head[u],head[v],head[w],head[fa[w]],1,n),'\n');
    }
}