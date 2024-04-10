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
        vector<int>v(n*2);
        vector<int>o,e;
        for(int i=0;i<n*2;i++)
            cin>>v[i],(v[i]%2==1?o:e).eb(i+1);
        if((int)o.size()%2==1)
            o.pop_back(),e.pop_back();
        else if(o.empty())
            e.pop_back(),e.pop_back();
        else
            o.pop_back(),o.pop_back();
        for(int i=0;i<(int)o.size();i+=2)
            cout<<o[i]<<' '<<o[i+1]<<'\n';
        for(int i=0;i<(int)e.size();i+=2)
            cout<<e[i]<<' '<<e[i+1]<<'\n';
    }
    cout.flush();
    return 0;
}