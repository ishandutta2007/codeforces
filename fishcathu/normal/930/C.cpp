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

int a[N],f[N],q[N],s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int m=read(),n=read();
    while(m--)++a[read()],--a[read()+1];
    for(int i=1;i<=n;++i)
    {
        a[i]+=a[i-1];
        if(a[i]<q[s])*upper_bound(q+1,q+1+s,a[i])=a[i];
        else q[++s]=a[i];
        f[i]=s;
    }
    s=0;
    for(int i=n;i>=1;--i)
    {
        if(a[i]<q[s])*upper_bound(q+1,q+1+s,a[i])=a[i];
        else q[++s]=a[i];
        f[i]+=s;
    }
    cout<<*max_element(f+1,f+1+n)-1<<'\n';
}