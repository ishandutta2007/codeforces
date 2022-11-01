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
int u[N],v[N],w[N];
int fa[N],n,m;
int find(int x){return fa[x]^x?fa[x]=find(fa[x]):x;}
bool check(int x)
{
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=1;i<=m;++i)if((w[i]|x)==x)fa[find(u[i])]=find(v[i]);
    for(int i=2,t=find(1);i<=n;++i)if(find(i)^t)return 0;
    return 1;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)cin>>u[i]>>v[i]>>w[i];
    int ans=(1<<30)-1;
    for(int i=1<<29;i;i>>=1)if(check(ans^i))ans^=i;
    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}