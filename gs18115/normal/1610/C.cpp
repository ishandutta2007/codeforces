#include<iostream>
#include<vector>
#include<queue>
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
inline bool chk(vector<pi>v,int d)
{
    int i=0;
    for(pi&t:v)
        if(t.fi>=d-i-1&&t.se>=i)
            i++;
    return i>=d;
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
        vector<pi>v(n);
        for(pi&t:v)
            cin>>t.fi>>t.se;
        int s=1,e=n;
        while(s<e)
        {
            int m=s+(e-s+1)/2;
            if(chk(v,m))
                s=m;
            else
                e=m-1;
        }
        cout<<s<<'\n';
    }
    return 0;
}