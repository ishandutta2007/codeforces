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
constexpr int inf=2E5+20;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int a[N];
bool f[N<<2][2],laz[N<<2];
void build(int i,int l,int r)
{
    f[i][0]=1;
    if(l==r)return;
    int m=l+r>>1;
    build(ls,l,m);
    build(rs,m+1,r);
}
void modify(int i)
{
    swap(f[i][0],f[i][1]);
    laz[i]^=1;
}
void push_down(int i)
{
    if(laz[i])
    {
        modify(ls);
        modify(rs);
        laz[i]=0;
    }
}
bool flip(int i,int l,int r,int x,int k)
{
    if(r<x)return 0;
    if(l>=x&&!f[i][k])return modify(i),0;
    if(l==r&&f[i][k])return modify(i),1;
    push_down(i);
    int m=l+r>>1;
    bool t=flip(ls,l,m,x,k)||flip(rs,m+1,r,x,k);
    f[i][0]=f[ls][0]|f[rs][0];
    f[i][1]=f[ls][1]|f[rs][1];
    return t;
}
void output()
{
    int i=1,l=1,r=inf;
    while(l^r)
    {
        push_down(i);
        int m=l+r>>1;
        if(f[rs][1])i=rs,l=m+1;
        else i=ls,r=m;
    }
    cout<<l<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read(),m=read();
    build(1,1,inf);
    for(int i=1;i<=n;++i)flip(1,1,inf,a[i]=read(),0);
    while(m--)
    {
        int x=read();
        flip(1,1,inf,a[x],1);
        flip(1,1,inf,a[x]=read(),0);
        output();
    }
}