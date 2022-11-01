#include<bits/stdc++.h>
#define ls lc[i]
#define rs rc[i]
#define fi first
#define se second
#define min amin
#define max amax
#define pb push_back
using namespace std;
using ll=long long;
using pii=array<int,2>;
constexpr int N=3E5+10;
constexpr int inf=1E9;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

vector<int>to[N],q[N];
int root[N],lc[N],rc[N],h[N],k[N],dep[N];
ll val[N],laz[N];
void add(int i,ll x){val[i]+=x,laz[i]+=x;}
void push(int i){if(laz[i])add(ls,laz[i]),add(rs,laz[i]),laz[i]=0;}
int merge(int x,int y)
{
    if(!x||!y)return x^y;
    if(val[x]>val[y])swap(x,y);
    push(x);
    rc[x]=merge(rc[x],y);
    if(h[lc[x]]<h[rc[x]])swap(lc[x],rc[x]);
    h[x]=h[rc[x]]+1;
    return x;
}
void dfs(int x,int f)
{
    ll s=0;
    for(int t:to[x])if(t^f)
    {
        dep[t]=dep[x]+1;
        dfs(t,x);
        while(root[t]&&dep[k[root[t]]]>dep[x])push(root[t]),root[t]=merge(lc[root[t]],rc[root[t]]);
        if(!root[t])cout<<"-1\n",exit(0);
        s+=val[root[t]];
        add(root[t],-val[root[t]]);
        root[x]=merge(root[x],root[t]);
    }
    add(root[x],s);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read(),m=read();
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    for(int i=1;i<=m;++i)
    {
        int x=read();
        cin>>k[i]>>val[i];
        if(x^1)root[x]=merge(root[x],i);
    }
    dfs(1,0);
    cout<<val[root[1]]<<'\n';
}