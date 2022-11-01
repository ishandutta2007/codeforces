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
constexpr int p=1E9+7;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int a[N];
vector<int>q[N];
int lcm(int x,int y){return 1LL*x*y/__gcd(x,y)%p;}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read(),ans=0;
    for(int i=2;i<n;++i)for(int j=i<<1;j<n;j+=i)q[j].pb(i);
    for(int i=2;i<n;++i)
    {
        a[i]=i-1;
        for(int j:q[i])
        {
            a[i]-=a[j];
            ans=(ans+1LL*a[j]*lcm(i/j,n-i))%p;
        }
        ans=(ans+1LL*a[i]*(n-i))%p;
    }
    cout<<ans<<'\n';
}