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
int arr[105][105];
inline void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    bool f=1;
    for(int s=0;s<n+m-1;s++)
    {
        int xr=0;
        for(int j=max(0,s-n+1);j<=s&&j<m;j++)
            xr^=arr[s-j][j];
        if(xr!=0)
        {
            f=0;
            break;
        }
    }
    cout<<(f?"Jeel":"Ashish")<<'\n';
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