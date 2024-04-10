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
constexpr int N=2E5+10;
constexpr int inf=1E9;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>auto min(U x,V y){return x<y?x:y;}
template<typename U,typename V>auto max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>auto min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>auto max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int a[N],dfn[N],cnt;
bool vis[N];
vector<pii>to[N];
void dfs(int x)
{
    if(vis[x])return;
    sort(to[x].begin(),to[x].end(),[](pii &l,pii &r){return l[0]<r[0];});
    for(auto [t,i]:to[x])dfs(t),cout<<i<<'\n';
    vis[x]=1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read(),m=read();
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)for(int j=i;!dfn[j];j=a[j])dfn[j]=++cnt;
    for(int i=1;i<=m;++i)
    {
        int l=dfn[read()],r=dfn[read()];
        if(l>r)swap(l,r);
        to[l].pb({r,i});
    }
    for(int i=1;i<=n;++i)dfs(i);
}