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
        int n,m;
        cin>>n>>m;
        bool f=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int c=(i==0||i==n-1?0:1)+(j==0||j==m-1?0:1)+2;
                int d;
                cin>>d;
                if(c<d)
                    f=1;
            }
        }
        if(f)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int c=(i==0||i==n-1?0:1)+(j==0||j==m-1?0:1)+2;
                cout<<c<<' ';
            }
            cout<<'\n';
        }
    }
    return 0;
}