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
constexpr int N=2E5+10,M=1E7+10;
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

int a[N],b[M],h[M];
vector<int>pri;
int f[N][21],g[N][21];
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)a[i]=h[read()];
    for(int i=0;i<=m;++i)for(int l=0,r=0,s=0;l<=n;)
    {
        if(r<=n&&s<=i)f[r][i]=l,s+=!!b[a[++r]]++;
        else s-=!!--b[a[++l]];
    }
    for(int i=1;i<=n;++i)for(int j=0;j<=m;++j)
    {
        g[i][j]=inf;
        for(int k=0;k<=j;++k)cmin(g[i][j],g[f[i][k]][j-k]);
        ++g[i][j];
    }
    cout<<g[n][m]<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    h[1]=1;
    for(int i=2;i<M;++i)
    {
        if(!h[i])h[i]=i,pri.pb(i);
        for(int j:pri)
        {
            int x=i*j;
            if(x>=M)break;
            if(!(i%j))
            {
                h[x]=h[i/j];
                break;
            }
            h[x]=h[i]*h[j];
        }
    }
    for(int T=read();T--;solve());
}