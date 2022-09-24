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
        int n,m;
        cin>>n>>m;
        if(n==1&&m==1)
        cout<<0<<'\n';
        else if(n==1||m==1)
            cout<<1<<'\n';
        else
        cout<<2<<'\n';
    }
    return 0;
}