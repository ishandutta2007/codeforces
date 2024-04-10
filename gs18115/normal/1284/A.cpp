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
    int n,m;
    cin>>n>>m;
    vector<string>x(n),y(m);
    for(auto&t:x)
        cin>>t;
    for(auto&t:y)
        cin>>t;
    int q;
    cin>>q;
    while(q-->0)
    {
        int p;
        cin>>p;
        p--;
        cout<<x[p%n]<<y[p%m]<<'\n';
    }
    cout<<endl;
    return 0;
}