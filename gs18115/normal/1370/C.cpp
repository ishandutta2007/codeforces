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
const string ans[2]={"Ashishgup","FastestFinger"};
inline bool isp(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return 0;
    return 1;
}
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
        int v;
        if(n==1)
            v=1;
        else if(n==2)
            v=0;
        else if(n%2==1)
            v=0;
        else if(__builtin_popcount(n)==1)
            v=1;
        else if(n%4==0)
            v=0;
        else if(isp(n/2))
            v=1;
        else
            v=0;
        cout<<ans[v]<<endl;
    }
    cout.flush();
    return 0;
}