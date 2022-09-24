#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
inline void solve()
{
    int n;
    cin>>n;
    ll pr;
    cin>>pr;
    ll cans=0;
    vector<ll>v;
    for(int i=1;i<n;i++)
    {
        ll cur;
        cin>>cur;
        cans+=abs(cur-pr);
        v.eb(cur-pr);
        pr=cur;
    }
    if(n==1)
    {
        cout<<cans<<'\n';
        return;
    }
    ll ans=cans-max(abs(v[0]),abs(v.back()));
    for(int i=1;i<n-1;i++)
    {
        ans=min(ans,cans-abs(v[i-1])-abs(v[i])+abs(v[i-1]+v[i]));
    }
    cout<<ans<<'\n';
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
        solve();
    return 0;
}