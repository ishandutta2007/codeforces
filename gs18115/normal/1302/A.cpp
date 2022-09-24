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
pl operator-(pl x,pl y)
{
    return pl(x.fi-y.fi,x.se-y.se);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pl>v(n);
    for(pl&t:v)
        cin>>t.fi>>t.se;
    if(n&1)
        return cout<<"NO"<<endl,0;
    v.eb(v[0]);
    for(int i=0;i<n/2;i++)
        if(v[i+1]-v[i]!=v[i+n/2]-v[i+n/2+1])
            return cout<<"NO"<<endl,0;
    cout<<"YES"<<endl;
    return 0;
}