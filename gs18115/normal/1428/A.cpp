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
        int x,y,p,q;
        cin>>x>>y>>p>>q;
        int d1=abs(x-p);
        int d2=abs(y-q);
        cout<<(d1+d2+(d1==0||d2==0?0:2))<<'\n';
    }
    return 0;
}