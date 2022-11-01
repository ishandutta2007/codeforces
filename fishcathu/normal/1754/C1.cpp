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
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int a[N],c[N];
void solve()
{
    int n=read(),m=0;
    for(int i=1;i<=n;++i)if(a[i]=read())c[++m]=i;
    if(m&1)return cout<<"-1\n",void();
    vector<pii>ans;
    c[m+1]=n+1;
    if(c[1]^1)ans.pb({1,c[1]-1});
    for(int l=1,r=2;r<=m;l+=2,r+=2)
    {
        if(c[r]-c[l]&1^a[c[l]]==a[c[r]])ans.pb({c[l],c[l]}),ans.pb({c[l]+1,c[r+1]-1});
        else ans.pb({c[l],c[r+1]-1});
    }
    cout<<ans.size()<<'\n';
    for(auto [x,y]:ans)cout<<x<<' '<<y<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}