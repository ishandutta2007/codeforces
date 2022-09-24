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
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int t2;
            cin>>t2;
            cout<<(i%2==0?1:-1)*abs(t2)<<' ';
        }
        cout<<'\n';
    }
    cout.flush();
    return 0;
}