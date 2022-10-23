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
const int mod=1e9+7;
int add(int x,int y)
{
    return x+y<mod?x+y:x+y-mod;
}
int sub(int x,int y)
{
    return x<y?x+mod-y:x-y;
}
int mul(int x,int y)
{
    return(ll)x*y%mod;
}
int pw(int x,int y)
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
const int N=1e6+10;
int dp[N],pr[N],ans[N];
int pw2[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        pr[n+1]=0;
        pw2[0]=1;
        for(int i=0;i++<n;)
            pw2[i]=mul(pw2[i-1],2);
        for(int i=n;i>0;i--)
        {
            if(i>n-i)
                dp[i]=pw2[n-i];
            else
                dp[i]=sub(pr[i+1],pr[i+i]);
            pr[i]=add(pr[i+1],dp[i]);
            int d=i/2;
            int k=pw2[d];
            ans[i]=i==n?mul(k,2):mul(k,dp[i]);
        }
        int alc=pw(2,n);
        int q=pw(alc,mod-2);
        for(int i=0;i++<n;)
            cout<<mul(ans[i],q)<<'\n';
    }
    return 0;
}