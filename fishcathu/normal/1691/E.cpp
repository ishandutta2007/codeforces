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
constexpr int N=1E5+10;
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

int l[N],r[N],fa[N];
vector<int>to[N];
bool vis[N];
int find(int x){return fa[x]^x?fa[x]=find(fa[x]):x;}
void solve()
{
    int n=read();
    to[0]=to[1]={};
    for(int i=1;i<=n;++i)
    {
        to[read()].pb(i);
        cin>>l[i]>>r[i];
        fa[i]=i;
    }
    for(int k=0;k<=1;++k)
    {
        sort(to[k].begin(),to[k].end(),[](int x,int y){return l[x]<l[y];});
        vector<int>q;
        for(int mx=-1;int x:to[k])if(cmax(mx,r[x]))q.pb(x);
        for(int x:to[k^1])
        {
            auto it=partition_point(q.begin(),q.end(),[&](int t){return r[t]<l[x];});
            if(it!=q.end()&&l[*it]<=r[x])fa[find(x)]=find(*it);
        }
    }
    for(int i=1;i<=n;++i)vis[find(i)]=1;
    int ans=0;
    for(int i=1;i<=n;++i)if(vis[i])++ans,vis[i]=0;
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}