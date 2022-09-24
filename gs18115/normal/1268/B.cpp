#include<iostream>
#include<vector>
#include<set>
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
ll ans,a2;
ll c[2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,i;
    cin>>n;
    vector<ll>a(n);
    for(i=0;i<n;i++)
        cin>>a[i],c[i&1]+=a[i]/2,c[i+1&1]+=(a[i]+1)/2;
    cout<<min(c[0],c[1])<<endl;
    return 0;
}