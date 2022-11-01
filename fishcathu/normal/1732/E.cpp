#include<bits/stdc++.h>
#define int uint32_t
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
constexpr int N=5E4+10,M=250;
constexpr int inf=3E9;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

vector<int>to[N],pri;
array<int,3>q[N];
int a[N],b[N],n,m,s;
int f[M],g[M][N],h[M][M],laz[M];
int _gcd(int x,int y)
{
    int z=1;
    for(int t:q[x])
    {
        int u=t<M?h[t][y%t]:y%t?1:t;
        y/=u;
        z*=u;
    }
    return z;
}
int calc(int i)
{
    int x=_gcd(a[i],b[i]);
    return a[i]*b[i]/x/x;
}
void push_down(int i)
{
    if(!laz[i])return;
    for(int j=1;j<=M;++j)a[i*M+j]=laz[i];
    laz[i]=0;
}
void push_up(int i)
{
    if(!i||i==s)return;
    f[i]=inf;
    for(int j=1;j<=M;++j)cmin(f[i],calc(i*M+j));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int i=1;i<N;++i)for(int j=i;j<N;j+=i)to[j].pb(i);
    q[1]={1,1,1};
    for(int i=2;i<N;++i)
    {
        if(!q[i][0])q[i]={1,1,i},pri.pb(i);
        for(int j:pri)
        {
            int x=i*j;
            if(x>=N)break;
            q[x]=q[i];
            q[x][0]*=j;
            if(q[x][0]>q[x][1])swap(q[x][0],q[x][1]);
            if(q[x][1]>q[x][2])swap(q[x][1],q[x][2]);
            if(!(i%j))break;
        }
    }
    for(int i=1;i<M;++i)
    {
        h[0][i]=h[i][0]=i;
        for(int j=1;j<=i;++j)h[i][j]=h[j][i%j];
    }
    n=read(),m=read(),s=n/M;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    for(int i=1;i<s;++i)
    {
        for(int j=1;j<N;++j)g[i][j]=inf;
        for(int j=1;j<=M;++j)
        {
            int x=b[i*M+j];
            for(int t:to[x])cmin(g[i][t],x/t);
        }
        for(int j=1;j<N;++j)for(int k:pri)
        {
            int x=j*k;
            if(x>=N)break;
            cmin(g[i][x],g[i][j]*k);
        }
        push_up(i);
    }
    while(m--)
    {
        int k=read(),l=read(),r=read(),u=(l-1)/M,v=(r-1)/M;
        if(k&1)
        {
            int x=read();
            if(u^v)
            {
                push_down(u),push_down(v);
                for(int i=u*M+M;i>=l;--i)a[i]=x;
                for(int i=v*M+1;i<=r;++i)a[i]=x;
                push_up(u),push_up(v);
                for(int i=u;++i<v;f[i]=g[i][x],laz[i]=x);
            }
            else
            {
                push_down(u);
                for(int i=l;i<=r;++i)a[i]=x;
                push_up(u);
            }
        }
        else
        {
            int mn=inf;
            if(u^v)
            {
                push_down(u),push_down(v);
                for(int i=u*M+M;i>=l;--i)cmin(mn,calc(i));
                for(int i=v*M+1;i<=r;++i)cmin(mn,calc(i));
                for(int i=u;++i<v;cmin(mn,f[i]));
            }
            else
            {
                push_down(u);
                for(int i=l;i<=r;++i)cmin(mn,calc(i));
            }
            cout<<mn<<'\n';
        }
    }
}