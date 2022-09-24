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
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        ll ans=0;
        int prv;
        cin>>prv;
        for(int i=1;i<n;i++)
        {
            int x;
            cin>>x;
            ans+=max(0,prv-x);
            prv=x;
        }
        cout<<ans;
        cout<<'\n';
    }
    cout.flush();
    return 0;
}