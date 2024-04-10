#include<iostream>
#include<vector>
#include<algorithm>
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,i;
    cin>>n;
    if(n==1)
        return cout<<1<<endl,0;
    for(i=2;i*i<=n;i++)
        if(n%i==0)
            break;
    if(i*i>n)
        i=n;
    ll m=n;
    while(m%i==0)
        m/=i;
    if(m==1)
        return cout<<i<<endl,0;
    cout<<1<<endl;
    return 0;
}