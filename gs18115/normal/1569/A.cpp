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
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        int n;
        string s;
        cin>>n>>s;
        int l=-1,r=-1;
        for(int j=1;j<n;j++)
            if(s[j-1]!=s[j])
                l=j,r=j+1;
        cout<<l<<' '<<r<<'\n';
    }
    return 0;
}