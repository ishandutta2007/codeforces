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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        int n,i,k1,k2;
        cin>>n>>k1>>k2;
        int m1=0,m2=0;
        for(i=0;i<k1;i++)
            cin>>n,m1=max(m1,n);
        for(i=0;i<k2;i++)
            cin>>n,m2=max(m2,n);
        cout<<(m1>m2?"YES":"NO")<<'\n';
    }
    cout<<endl;
    return 0;
}