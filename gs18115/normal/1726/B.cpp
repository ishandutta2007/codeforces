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
        int n,m;
        cin>>n>>m;
        if(n>m)
            cout<<"No"<<endl;
        else if(n%2==1)
        {
            cout<<"Yes"<<endl;
            for(int i=0;i<n-1;i++)
                cout<<1<<' ';
            cout<<m-(n-1)<<endl;
        }
        else if(m%2==1)
            cout<<"No"<<endl;
        else
        {
            cout<<"Yes"<<endl;
            for(int i=0;i<n-2;i++)
                cout<<1<<' ';
            cout<<(m-(n-2))/2<<' '<<(m-(n-2))/2<<endl;
        }
    }
    return 0;
}