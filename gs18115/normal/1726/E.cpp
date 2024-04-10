#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
const int mod=998244353;
inline int add(const int&x,const int&y)
{
    return x+y<mod?x+y:x+y-mod;
}
inline int sub(const int&x,const int&y)
{
    return x<y?x+mod-y:x-y;
}
inline int mul(const int&x,const int&y)
{
    return(ll)x*y%mod;
}
inline int pw(int x,int y)
{
    int r=1;
    while(y>0)
    {
        if(y%2==1)
            r=mul(r,x);
        x=mul(x,x);
        y/=2;
    }
    return r;
}
inline int minv(const int&x)
{
    return pw(x,mod-2);
}
const int mxn=300010;
int dp[mxn];
int dp2[mxn];
int fac[mxn],invf[mxn];
int pw2[mxn];
inline int ncr(int n,int r)
{
    return mul(fac[n],mul(invf[n-r],invf[r]));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        fac[0]=1;
        pw2[0]=1;
        for(int i=0;i++<n;)
            pw2[i]=mul(2,pw2[i-1]),fac[i]=mul(i,fac[i-1]);
        invf[n]=minv(fac[n]);
        for(int i=n;i-->0;)
            invf[i]=mul(i+1,invf[i+1]);
        dp[0]=1;
        dp[1]=1;
        for(int i=1;i++<n;)
            dp[i]=add(dp[i-1],mul(i-1,dp[i-2]));
        dp2[0]=1;
        dp2[1]=0;
        for(int i=1;i++<n;)
            dp2[i]=mul(i-1,dp2[i-2]);
        int ans=0;
        for(int i=0;i*4<=n;i++)
            ans=add(ans,mul(pw2[i],mul(mul(dp[n-i*4],dp2[i*2]),ncr(n-i*2,i*2))));
        cout<<ans<<endl;
    }
    return 0;
}