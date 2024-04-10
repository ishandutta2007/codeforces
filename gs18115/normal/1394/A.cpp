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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,d,m;
    cin>>n>>d>>m;
    d++;
    vector<int>v1,v2;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        (t>m?v2:v1).eb(t);
    }
    sort(all(v1),greater<int>());
    sort(all(v2),greater<int>());
    vector<ll>ps1(1,0),ps2(1,0);
    int n1=v1.size(),n2=v2.size();
    for(int i=0;i<n1;i++)
        ps1.eb(ps1.back()+v1[i]);
    for(int i=0;i<n2;i++)
        ps2.eb(ps2.back()+v2[i]);
    ll ans=0;
    for(int i=0;i<=n1;i++)
    {
        if((n-i+d-1)/d<=n2)
            ans=max(ans,ps1[i]+ps2[(n-i+d-1)/d]);
    }
    cout<<ans<<endl;
    return 0;
}