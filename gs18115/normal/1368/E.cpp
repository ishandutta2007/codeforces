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
int tp[200010];
vector<int>adj[200010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int tc=0;tc<t;tc++)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].eb(v);
        }
        vector<int>off;
        for(int i=0;i++<n;)
        {
            if(tp[i]==-1)
                off.eb(i);
            else if(tp[i]==1)
                for(int&t:adj[i])
                    tp[t]=-1;
            else
                for(int&t:adj[i])
                    if(tp[t]==0)
                        tp[t]=1;
        }
        cout<<off.size()<<'\n';
        for(int&t:off)
            cout<<t<<' ';
        cout<<'\n';
        for(int i=0;i++<n;)
            adj[i].clear(),tp[i]=0;
    }
    cout.flush();
    return 0;
}