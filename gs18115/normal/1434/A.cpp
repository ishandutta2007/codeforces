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
    int n;
    vector<int>fr(6);
    for(int&t:fr)
        cin>>t;
    cin>>n;
    vector<pi>d;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        for(int&t:fr)
            d.eb(x-t,i);
    }
    vector<int>ctv(n,0);
    int ct=n;
    sort(all(d));
    int r=0;
    int ans=inf;
    for(int l=0;l<(int)d.size();l++)
    {
        while(r<(int)d.size()&&ct>0)
        {
            int i=d[r].se;
            if(ctv[i]==0)
                ct--;
            ctv[i]++;
            r++;
        }
        if(r==(int)d.size()&&ct>0)
            break;
        if(ctv[d[l].se]==1)
            ct++;
        ctv[d[l].se]--;
        ans=min(ans,d[r-1].fi-d[l].fi);
    }
    cout<<ans<<endl;
    return 0;
}