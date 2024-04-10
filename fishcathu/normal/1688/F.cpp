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

ll a[N];
int fa[N];
int l[N],r[N],deg[N];
vector<int>to[N];
int find(int x){return fa[x]?fa[x]=find(fa[x]):x;}
void calc(int x)
{
    fa[x]=x+1;
    for(int t:to[x])if(!--deg[t])
    {
        for(int i=l[t];(i=find(i))<r[t];)
        {
            calc(i);
        }
    }
}
void solve()
{
    int n=read(),m=read();
    for(int i=0;i<=n+1;++i)fa[i]=0,to[i].clear();
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)a[i]=a[i-1]+a[i]-read();
    for(int i=1;i<=m;++i)to[l[i]=read()-1].pb(i),to[r[i]=read()].pb(i),deg[i]=2;
    for(int i=0;i<=n;++i)if(!a[i])calc(i);
    for(int i=0;i<=n;++i)if(!fa[i])return cout<<"NO\n",void();
    cout<<"YES\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}