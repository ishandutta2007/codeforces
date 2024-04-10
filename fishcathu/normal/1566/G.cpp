#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E5+10,M=1.8E7+10;
const int inf=1E9+1;
auto max(auto l,auto r){return l>r?l:r;}
auto min(auto l,auto r){return l<r?l:r;}
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
map<int,int>dis[N];
set<tuple<int,int,int>>q;
set<pii>to[N];
int top[N],lc[M],rc[M],sum[M],cnt;
void add(int &i,int l,int r,int w,int k)
{
    if(!i)i=++cnt;
    sum[i]+=k;
    if(l==r)return;
    int m=l+r>>1;
    if(w<=m)add(lc[i],l,m,w,k);
    else add(rc[i],m+1,r,w,k);
}
ll ask(int i,int j,int k,int w,int l,int r)
{
    if(l==r)return l^inf?w+l:1LL<<60;
    int m=l+r>>1;
    if(sum[lc[i]]-sum[lc[j]]-sum[lc[k]]+(w>=l&&w<=m))return ask(lc[i],lc[j],lc[k],w,l,m);
    return ask(rc[i],rc[j],rc[k],w,m+1,r);
}
void addedge(int u,int v,int w)
{
    if(u>v)swap(u,v);
    if(w)
    {
        dis[u][v]=w;
        q.insert({w,u,v});
        to[u].insert({w,v});
        to[v].insert({w,u});
        add(top[0],1,inf,w,1);
        add(top[u],1,inf,w,1);
        add(top[v],1,inf,w,1);
    }
    else
    {
        w=dis[u][v];
        q.erase({w,u,v});
        to[u].erase({w,v});
        to[v].erase({w,u});
        add(top[0],1,inf,w,-1);
        add(top[u],1,inf,w,-1);
        add(top[v],1,inf,w,-1);
    }
}
void putout()
{
    auto [w,u,v]=*q.begin();
    ll res=ask(top[0],top[u],top[v],w,1,inf);
    vector<pii>a,b;
    for(pii x:to[u])
    {
        if(x.se^v)
        {
            a.pb(x);
            if(a.size()==2)
            {
                res=min(res,w+0LL+a[0].fi+x.fi);
                break;
            }
        }
    }
    for(pii x:to[v])
    {
        if(x.se^u)
        {
            b.pb(x);
            if(b.size()==2)
            {
                res=min(res,w+0LL+b[0].fi+x.fi);
                break;
            }
        }
    }
    for(pii x:a)
    {
        for(pii y:b)
        {
            if(x.se^y.se)
            {
                res=min(res,x.fi+y.fi);
            }
        }
    }
    write(res,'\n');
}
int main()
{
    read();
    for(int n=read();n--;)
    {
        int u=read(),v=read();
        addedge(u,v,read());
    }
    putout();
    for(int n=read();n--;)
    {
        int k=read(),u=read(),v=read();
        if(k)addedge(u,v,read());
        else addedge(u,v,0);
        putout();
    }
}