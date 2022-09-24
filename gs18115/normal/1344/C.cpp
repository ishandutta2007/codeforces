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
const ll INF=1e18+7;
vector<int>adj[200010],radj[200010];
int in[200010];
int dp1[200010],dp2[200010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].eb(v);
        radj[v].eb(u);
        in[v]++;
    }
    queue<int>qu;
    vector<int>tps;
    for(int i=0;i++<n;)
        if(in[i]==0)
            qu.ep(i);
    while(!qu.empty())
    {
        tps.eb(qu.front());
        qu.pop();
        for(int&t:adj[tps.back()])
            if(--in[t]==0)
                qu.ep(t);
    }
    if((int)tps.size()!=n)
        return cout<<-1<<endl,0;
    for(int i=0;i++<n;)
        dp1[i]=dp2[i]=i;
    for(int&t:tps)
        for(int&nx:adj[t])
            dp1[nx]=min(dp1[nx],dp1[t]);
    reverse(all(tps));
    for(int&t:tps)
        for(int&nx:radj[t])
            dp2[nx]=min(dp2[nx],dp2[t]);
    int cnt=0;
    for(int i=0;i++<n;)
        if(dp1[i]==i&&dp2[i]==i)
            cnt++;
    cout<<cnt<<endl;
    for(int i=0;i++<n;)
        cout<<(dp1[i]==i&&dp2[i]==i?'A':'E');
    cout<<endl;
    return 0;
}