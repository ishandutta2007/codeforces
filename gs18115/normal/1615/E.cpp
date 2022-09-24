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
const int mxn=200010;
vector<int>adj[mxn];
priority_queue<int>pq[mxn];
int id[mxn];
void dfs(int x,int p)
{
    int c=0;
    id[x]=x;
    for(int&t:adj[x])
    {
        if(t==p)
            continue;
        c++;
        dfs(t,x);
        if(pq[id[x]].size()<pq[id[t]].size())
            id[x]=id[t];
    }
    if(c==0) //leaf
        pq[x].ep(0);
    for(int&t:adj[x])
    {
        if(t==p||id[t]==id[x])
            continue;
        while(!pq[id[t]].empty())
        {
            pq[id[x]].ep(pq[id[t]].top());
            pq[id[t]].pop();
        }
    }
    {
        int t=pq[id[x]].top();
        pq[id[x]].pop();
        pq[id[x]].ep(t+1);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs(1,0);
    vector<int>v(1,0);
    while(!pq[id[1]].empty())
    {
        v.eb(v.back()+pq[id[1]].top());
        pq[id[1]].pop();
    }
    v.resize(n+1,v.back());
    ll m=-INF;
    for(int r=0;r<=k;r++)
    {
        int b=min(n/2,n-v[r]);
        int w=n-r-b;
        m=max(m,(ll)w*(r-b));
    }
    cout<<m<<endl;
    return 0;
}