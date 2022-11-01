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
constexpr int N=1.2E6+10;
constexpr int inf=3E5;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

using node=array<array<int,2>,2>;
constexpr node u={3,0,1,2},v={1,2,1,2};
node f[N];
int ans;
void operator*=(node &x,node y)
{
    node z;
    for(int i=0;i<2;++i)for(int j=0;j<2;++j)
    {
        z[i][j]=0;
        for(int k=0;k<2;++k)z[i][j]=(z[i][j]+1LL*x[i][k]*y[k][j])%p;
    }
    x=z;
}
void push_down(int i)
{
    f[ls]*=f[i];
    f[rs]*=f[i];
    f[i]={1,0,0,1};
}
void build(int i,int l,int r,int x,int y)
{
    if(l==r)
    {
        if(l>y||r<x)f[i]={1,0,0,0};
        else f[i]={0,1,0,0};
    }
    else
    {
        f[i]={1,0,0,1};
        int m=l+r>>1;
        build(ls,l,m,x,y);
        build(rs,m+1,r,x,y);
    }
}
void mul(int i,int l,int r,int x,int y)
{
    if(l>y||r<x)f[i]*=u;
    else if(l>=x&&r<=y)f[i]*=v;
    else
    {
        push_down(i);
        int m=l+r>>1;
        mul(ls,l,m,x,y);
        mul(rs,m+1,r,x,y);
    }
}
void dfs(int i,int l,int r)
{
    if(l==r)(ans+=f[i][0][1])%=p;
    else
    {
        push_down(i);
        int m=l+r>>1;
        dfs(ls,l,m);
        dfs(rs,m+1,r);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read(),l=read(),r=read();
    build(1,0,inf,l,r);
    while(--n)
    {
        cin>>l>>r;
        mul(1,0,inf,l,r);
    }
    dfs(1,0,inf);
    cout<<ans<<'\n';
}