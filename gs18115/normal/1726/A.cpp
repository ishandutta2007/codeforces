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
    int t=1;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        int ans=v.back()-v[0];
        for(int i=1;i<n;i++)
            ans=max(ans,v[i-1]-v[i]);
        for(int i=1;i<n;i++)
            ans=max(ans,v[i]-v[0]);
        for(int i=0;i<n-1;i++)
            ans=max(ans,v.back()-v[i]);
        cout<<ans<<endl;
    }
    return 0;
}