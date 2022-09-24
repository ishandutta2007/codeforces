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
inline int add(int x,int y)
{
    return x+y<mod?x+y:x+y-mod;
}
inline int sub(int x,int y)
{
    return x<y?x+mod-y:x-y;
}
inline int mul(int x,int y)
{
    return(ll)x*y%mod;
}
inline int pw(int x,ll y)
{
    int t=1;
    while(y>0)
    {
        if(y%2==1)
            t=mul(t,x);
        x=mul(x,x);
        y/=2;
    }
    return t;
}
inline int divi(int x,int y)
{
    return mul(x,pw(y,mod-2));
}
int fact[400010];
int invf[400010];
inline int ncr(int n,int r)
{
    if(r<0||n<r)
        return 0;
    return mul(mul(invf[n-r],invf[r]),fact[n]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=fact[0]=1;i<400010;i++)
        fact[i]=mul(fact[i-1],i);
    invf[400009]=divi(1,fact[400009]);
    for(int i=400009;i-->0;)
        invf[i]=mul(invf[i+1],i+1);
    int n;
    cin>>n;
    vector<int>v(n+1);
    int s=0;
    for(int&t:v)
        cin>>t;
    for(int i=0;i<=n;i++)
        s=add(s,ncr(v[i]-1+(i+1),i+1));
    cout<<s<<endl;
    return 0;
}