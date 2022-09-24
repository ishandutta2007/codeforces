#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;
ll n,i,j,ans;
vector<ll>v;
ll a[2010];
bool chk[2010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        v.eb(a[i]);
    }
    sort(all(v));
    v.erase(unique(all(v)),v.end());
    for(i=0;i<n;i++)
        a[i]=lower_bound(all(v),a[i])-v.begin();
    for(i=0;i<n;i++)
    {
        if(chk[a[i]])
            break;
        chk[a[i]]=true;
    }
    ans=n-i;
    j=n-1;
    for(;i-->0;)
    {
        for(;j>=0;j--)
        {
            if(chk[a[j]])
                break;
            chk[a[j]]=true;
        }
        ans=min(ans,j-i);
        chk[a[i]]=false;
    }
    for(;j>=0;j--)
    {
        if(chk[a[j]])
            break;
        chk[a[j]]=true;
    }
    ans=min(ans,j+1);
    cout<<ans<<endl;
    return 0;
}