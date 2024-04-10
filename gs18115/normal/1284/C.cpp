#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define semicolon 
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
ll fac[1000010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    fac[0]=1;
    for(ll i=0;i++<n;)
        fac[i]=fac[i-1]*i%m;
    for(ll i=0;i++<n;)
    {
        ll c=n-i+1;
        ans+=fac[i]*fac[n-i]%m*c%m*c%m;
        ans%=m;
    }
    cout<<(ans%m+m)%m<<endl;
    return 0;
}