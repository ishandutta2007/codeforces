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
constexpr int N=110;
constexpr int inf=1E9;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>auto min(U x,V y){return x<y?x:y;}
template<typename U,typename V>auto max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>auto min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>auto max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int c[N][N],f[N][N];
vector<pii>q[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read(),m=read(),s=read(),p=read();
    for(int i=0;i<n;++i)
    {
        c[i][0]=1;
        for(int j=1;j<=i;++j)c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
    }
    q[0].pb({0,1});
    for(int k=n;k>=1;--k)
    {
        for(int i=1;i<=n;++i)
        {
            q[i].clear();
            for(int j=0;j<=s;++j)if(f[i][j])q[i].pb({j,f[i][j]}),f[i][j]=0;
        }
        for(int i=0;i<n;++i)for(int j=n-i;j--;)for(auto [u,x]:q[i])for(auto [v,y]:q[j])
        {
            int t=u+v+(k==m);
            if(t>s)break;
            (f[i+j+1][t]+=1LL*c[i+j][i]*x%p*y%p)%=p;
        }
    }
    cout<<f[n][s]<<'\n';
}