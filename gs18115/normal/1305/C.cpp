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
const ll INF=1e18+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll mod;
    cin>>n>>mod;
    vector<int>v(n);
    for(int&t:v)
        cin>>t;
    if(n>mod)
        return cout<<0<<endl,0;
    ll ans=1;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            ans=ans*abs(v[i]-v[j])%mod;
    cout<<ans<<endl;
    return 0;
}