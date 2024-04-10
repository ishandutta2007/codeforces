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
const int N=3E5+10;
const int inf=1<<30;
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
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int L[N<<2],R[N<<2];
vector<pii>to[N<<2];
int sx[N<<1],sy[N<<1],fa[N<<1];
map<pii,int>las;
vector<pair<int*,int>>q;
ll ans;
int fin(int x)
{
    return fa[x]==x?x:fin(fa[x]);
}
void build(int i,int l,int r)
{
    L[i]=l;
    R[i]=r;
    if(l!=r)
    {
        int m=l+r>>1;
        build(ls,l,m);
        build(rs,m+1,r);
    }
}
void add(int i,int l,int r,pii x)
{
    if(L[i]>r||R[i]<l)return;
    if(L[i]>=l&&R[i]<=r)to[i].pb(x);
    else
    {
        add(ls,l,r,x);
        add(rs,l,r,x);
    }
}
void change(int *u,int v)
{
    q.pb(mp(u,*u));
    *u=v;
}
void dfs(int i)
{
    int now=q.size();
    ll res=ans;
    for(pii x:to[i])
    {
        int u=fin(x.fi),v=fin(x.se);
        if(u!=v)
        {
            ans-=sx[u]*1LL*sy[u];
            ans-=sx[v]*1LL*sy[v];
            if(sx[u]+sy[u]<sx[v]+sy[v])swap(u,v);
            change(fa+v,u);
            change(sx+u,sx[u]+sx[v]);
            change(sy+u,sy[u]+sy[v]);
            ans+=sx[u]*1LL*sy[u];
        }
    }
    if(L[i]==R[i])write(ans,' ');
    else
    {
        dfs(ls);
        dfs(rs);
    }
    while(q.size()>now)
    {
        *q.back().fi=q.back().se;
        q.pop_back();
    }
    ans=res;
}
int main()
{
    int n=read();
    build(1,1,n);
    for(int i=1;i<=n;++i)
    {
        pii x=mp(read(),read()+n);
        int t=las[x];
        if(t)
        {
            add(1,t,i-1,x);
            las.erase(x);
        }
        else las[x]=i;
    }
    for(pair<pii,int>x:las)add(1,x.se,n,x.fi);
    for(int i=1;i<=n;++i)
    {
        int j=i+n;
        fa[i]=i;
        fa[j]=j;
        sx[i]=sy[j]=1;
    }
    dfs(1);
}