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
constexpr ll inf=1LL<<60;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>auto min(U x,V y){return x<y?x:y;}
template<typename U,typename V>auto max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>auto min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>auto max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

using node=array<ll,4>;
node operator+(node l,node r)
{
    node x;
    x[0]=min(l[0]+r[0],l[1]+r[2]);
    x[1]=min(l[0]+r[1],l[1]+r[3]);
    x[2]=min(l[2]+r[0],l[3]+r[2]);
    x[3]=min(l[2]+r[1],l[3]+r[3]);
    return x;
}
int a[N],b[N],n;
node f[N<<1];
node ask(int l,int r)
{
    node u={0,inf,inf,0},v=u;
    for(--l+=n,++r+=n;l^r^1;l>>=1,r>>=1)
    {
        if(~l&1)u=u+f[l^1];
        if(r&1)v=f[r^1]+v;
    }
    return u+v;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    cin>>n;
    for(int i=1;i<n;++i)
    {
        read();
        cin>>a[i]>>b[i];
        read();
        f[i+n][0]=abs(a[i]-a[i-1])+1;
        f[i+n][1]=i+i-a[i-1]-b[i]+1;
        f[i+n][2]=i+i-b[i-1]-a[i]+1;
        f[i+n][3]=abs(b[i]-b[i-1])+1;
    }
    for(int i=n;i>=1;--i)f[i]=f[ls]+f[rs];
    for(int m=read();m--;)
    {
        int l[3],r[3];
        cin>>l[0]>>l[1]>>r[0]>>r[1];
        if(l[0]>l[1])l[2]=0;
        else swap(l[0],l[1]),l[2]=1;
        if(r[0]>r[1])r[2]=0;
        else swap(r[0],r[1]),r[2]=1;
        if(l[0]==r[0])
        {
            if(l[2]==r[2])cout<<abs(l[1]-r[1])<<'\n';
            else cout<<(l[0]+r[0]-l[1]-r[1])<<'\n';
        }
        else
        {
            if(l[0]>r[0])swap(l,r);
            int u[2],v[2];
            if(l[2])u[0]=l[0]+l[0]-a[l[0]]-l[1],u[1]=abs(l[1]-b[l[0]]);
            else u[0]=abs(l[1]-a[l[0]]),u[1]=l[0]+l[0]-b[l[0]]-l[1];
            if(r[2])v[0]=r[0]+r[0]-a[r[0]-1]-r[1]+1,v[1]=abs(r[1]-b[r[0]-1])+1;
            else v[0]=abs(r[1]-a[r[0]-1])+1,v[1]=r[0]+r[0]-b[r[0]-1]-r[1]+1;
            node x=ask(l[0]+1,r[0]-1);
            ll ans=inf;
            cmin(ans,u[0]+x[0]+v[0]);
            cmin(ans,u[0]+x[1]+v[1]);
            cmin(ans,u[1]+x[2]+v[0]);
            cmin(ans,u[1]+x[3]+v[1]);
            cout<<ans<<'\n';
        }
    }
}