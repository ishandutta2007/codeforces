#include<iostream>
#include<vector>
#include<map>
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
map<pi,int>m;
int S[200010];
int A[200010];
ll ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q,i;
    cin>>n;
    for(i=0;i++<n;)
        cin>>A[i],ans+=A[i];
    cin>>q;
    while(q-->0)
    {
        int s,t,u;
        cin>>s>>t>>u;
        int x=m[pi(s,t)];
        S[x]--;
        if(x>0)
            ans++;
        if(x>0&&S[x]>=A[x])
            ans--;
        if(u>0)
            ans--;
        if(u>0&&S[u]>=A[u])
            ans++;
        S[m[pi(s,t)]=u]++;
        cout<<ans<<'\n';
    }
    cout<<endl;
    return 0;
}