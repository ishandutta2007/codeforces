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
    int tc=1;
    cin>>tc;
    while(tc-->0)
    {
        int n,z;
        cin>>n>>z;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        int m=0;
        for(int&t:v)
            m=max(m,t|z);
        cout<<m;
        cout<<'\n';
    }
    return 0;
}