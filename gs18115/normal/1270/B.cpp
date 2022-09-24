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
        int n;
        cin>>n;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        int i;
        for(i=1;i<n;i++)
            if(abs(v[i]-v[i-1])>1)
                break;
        if(i<n)
            cout<<"YES\n"<<i<<' '<<i+1<<'\n';
        else
            cout<<"NO\n";
    }
    return 0;
}