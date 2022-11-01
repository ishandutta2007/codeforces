#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define min amin
#define max amax
#define pb push_back
using namespace std;
using ll=long long;
using pii=array<int,2>;
const int N=2E5+10;
const int inf=1E9;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

vector<int>to[N];
int a[N],fa[N],cnt;
bool b[N];
map<int,vector<array<int,3>>>q;
int find(int x){return fa[x]^x?fa[x]=find(fa[x]):x;}
void dfs(int x,int f)
{
    int t=cnt;
    bool b=1;
    for(int t:to[x])if(t^f)
    {
        dfs(t,x);
        b=0;
    }
    cnt+=b;
    q[a[x]].pb({t,cnt,x});
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int n=read();
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    dfs(1,0);
    for(int i=0;i<=cnt;++i)fa[i]=i;
    ll ans=0;
    for(auto [x,y]:q)
    {
        for(auto [l,r,id]:y)if(find(l)^find(r))b[id]=1;
        for(auto [l,r,id]:y)
        {
            int u=find(l),v=find(r);
            if(u^v)fa[u]=v,ans+=x;
        }
    }
    cout<<ans<<' '<<count(b+1,b+1+n,1)<<'\n';
    for(int i=1;i<=n;++i)if(b[i])cout<<i<<' ';
    cout<<'\n';
}