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
constexpr int N=1<<18;
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

char a[N];
int f[N<<1];
void update(int i)
{
    f[i]=0;
    if(a[i]^'0')f[i]+=f[ls];
    if(a[i]^'1')f[i]+=f[rs];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=1<<read();
    for(int i=0;i<n;++i)f[i|n]=1;
    for(int i=n;--i;)
    {
        cin>>a[i];
        update(i);
    }
    for(int m=read();m--;)
    {
        int u=n-read();
        cin>>a[u];
        while(u)update(u),u>>=1;
        cout<<f[1]<<'\n';
    }
}