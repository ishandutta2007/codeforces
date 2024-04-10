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
constexpr int N=1E6+10;
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

int n,m;
int a[N],pre[N],nex[N];
int l[N],r[N];
ll b[N],c[N],ans[N];
vector<int>u[N],v[N];
void add(int i,int x){int y=x*i;for(;i<=n;i+=i&-i)b[i]+=x,c[i]+=y;}
void add(int l,int r,int x){add(l,x),add(r+1,-x);}
ll ask(int i){ll x=0,y=0;for(int j=i;j;j-=j&-j)x+=b[j],y+=c[j];return x*(i+1)-y;}
ll ask(int l,int r){return ask(r)-ask(l-1);}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i)u[l[i]=read()].pb(i);
    for(int i=1;i<=m;++i)v[r[i]=read()].pb(i);
    for(int i=1;i<=n;++i)
    {
        int j=i-1;
        while(j>=1&&a[j]<a[i])j=pre[j];
        pre[i]=j;
        add(j+1,i-1,1);
        for(int id:v[i])ans[id]+=ask(l[id],i);
    }
    for(int i=1;i<=n;++i)b[i]=c[i]=0;
    for(int i=n;i>=1;--i)
    {
        int j=i+1;
        while(j<=n&&a[j]<a[i])j=nex[j];
        nex[i]=j;
        add(i,j-1,1);
        for(int id:u[i])ans[id]+=ask(i,r[id]);
    }
    for(int i=1;i<=m;++i)cout<<ans[i]<<' ';
    cout<<'\n';
}