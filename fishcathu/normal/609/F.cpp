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
template<typename U,typename V>auto min(U x,V y){return x<y?x:y;}
template<typename U,typename V>auto max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>auto min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>auto max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int a[N],c[N],h[N],f[N<<2];
ll b[N];
multimap<int,int>q;
void build(int i,int l,int r)
{
    if(l==r)f[i]=min(a[c[l]]+b[c[l]],inf);
    else
    {
        int m=l+r>>1;
        build(ls,l,m);
        build(rs,m+1,r);
        f[i]=max(f[ls],f[rs]);
    }
}
void ass(int i,int l,int r,int x,int k)
{
    cmax(f[i],k);
    if(l==r)return;
    int m=l+r>>1;
    if(x<=m)ass(ls,l,m,x,k);
    else ass(rs,m+1,r,x,k);
}
int ask(int i,int l,int r,int x)
{
    if(a[c[l]]>x||f[i]<x)return 0;
    if(l==r)return l;
    int m=l+r>>1;
    if(f[ls]>=x)return ask(ls,l,m,x);
    return ask(rs,m+1,r,x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read(),m=read();
    for(int i=1;i<=n;++i)cin>>a[i]>>b[i],c[i]=i;
    sort(c+1,c+1+n,[](int x,int y){return a[x]<a[y];});
    build(1,1,n);
    while(m--)
    {
        int u=read(),v=read(),i=ask(1,1,n,u);
        if(i)
        {
            int x=c[i];
            ++h[x];
            b[x]+=v;
            for(auto it=q.lower_bound(a[x]);it!=q.end()&&a[x]+b[x]>=it->fi;it=q.erase(it))++h[x],b[x]+=it->se;
            ass(1,1,n,i,min(a[x]+b[x],inf));
        }
        else q.insert({u,v});
    }
    for(int i=1;i<=n;++i)cout<<h[i]<<' '<<b[i]<<'\n';
}