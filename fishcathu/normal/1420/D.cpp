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

int lc[N<<5],rc[N<<5],f[N<<5],root,cnt;
int fac[N],inv[N];
int c(int n,int m){return m>n?0:1LL*fac[n]*inv[m]%p*inv[n-m]%p;}
void add(int &i,int l,int r,int x)
{
    if(!i)i=++cnt;
    ++f[i];
    if(l==r)return;
    int m=l+r>>1;
    if(x<=m)add(ls,l,m,x);
    else add(rs,m+1,r,x);
}
int ask(int i,int l,int r,int x)
{
    if(!i||l>x)return 0;
    if(r<=x)return f[i];
    int m=l+r>>1;
    return ask(ls,l,m,x)+ask(rs,m+1,r,x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    fac[0]=1;
    for(int i=0;++i<N;fac[i]=1LL*fac[i-1]*i%p);
    inv[N-1]=qpow(fac[N-1]);
    for(int i=N;--i>0;inv[i-1]=1LL*inv[i]*i%p);
    vector<pii>a(read());
    int m=read()-1;
    for(auto &[x,y]:a)cin>>x>>y;
    sort(a.begin(),a.end(),[](pii x,pii y){return x[1]>y[1];});
    int ans=0;
    for(auto [x,y]:a)ans=(ans+c(ask(root,1,inf,y),m))%p,add(root,1,inf,x);
    cout<<ans<<'\n';
}