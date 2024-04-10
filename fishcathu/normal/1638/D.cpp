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
constexpr int N=1010;
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

int a[N][N],n,m;
vector<array<int,3>>ans;
void dfs(int i,int j)
{
    if(!i||!j||i==n||j==m)return;
    int x=0;
    for(int u=2;u--;)for(int v=2;v--;)
    {
        int y=a[i+u][j+v];
        if(!y)continue;
        if(!x)x=y;
        if(x^y)return;
    }
    if(!x)return;
    ans.pb({i,j,x});
    a[i][j]=a[i][j+1]=a[i+1][j]=a[i+1][j+1]=0;
    for(int u=-1;u<2;++u)for(int v=-1;v<2;++v)dfs(i+u,j+v);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    cin>>n>>m;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>a[i][j];
    for(int i=1;i<n;++i)for(int j=1;j<m;++j)dfs(i,j);
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(a[i][j])return cout<<"-1\n",0;
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto [i,j,x]:ans)cout<<i<<' '<<j<<' '<<x<<'\n';
}