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
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}
const int N=2E5+10;
const int inf=1<<30;
vector<pair<int,bool>>to[N];
int b[N],du[N],q[N],ans[N],s;
void dfs(int x,bool k)
{
    b[x]=k;
    for(auto [t,w]:to[x])
    {
        if(b[t]==k)cout<<"NO\n",exit(0);
        if(!~b[t])dfs(t,!k);
    }
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int n=read();
    for(int m=read();m--;)
    {
        int w=read()-1,u=read(),v=read();
        to[u].pb({v,w});
        to[v].pb({u,w});
    }
    for(int i=1;i<=n;++i)b[i]=-1;
    for(int i=1;i<=n;++i)if(!~b[i])dfs(i,0);
    for(int i=1;i<=n;++i)for(auto [j,k]:to[i])du[j]+=k^b[i];
    for(int i=1;i<=n;++i)if(!du[i])q[++s]=i;
    int cnt=0;
    for(int i=1;i<=s;++i)
    {
        int x=q[i];
        ans[x]=i;
        for(auto [t,w]:to[x])if(w^b[x]&&!--du[t])q[++s]=t;
    }
    if(s^n)return cout<<"NO\n",0;
    cout<<"YES\n";
    for(int i=1;i<=n;++i)cout<<(b[i]?'L':'R')<<' '<<ans[i]<<'\n';
}