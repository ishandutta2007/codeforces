#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
typedef pair<PL,PL>PPL;
const LL INF=1e18;
const LL MAXV=2e5+10;
vector<LL>adj[MAXV];
LL sum;
bool vis[MAXV];
PPL dfs(LL V,LL os,LL es,LL on,LL en)
{
    vis[V]=true;
    sum+=(os+es+on)>>1;
    LL OS,ES,ON,EN;
    OS=ES=ON=EN=0;
    LL i;
    for(i=0;i<adj[V].size();i++)
    {
        LL&T=adj[V][i];
        if(!vis[T])
        {
            PPL t=dfs(T,ES+EN+es+en+1,OS+ON+os+on,EN+en+1,ON+on);
            OS+=t.first.first;
            ES+=t.first.second;
            ON+=t.second.first;
            EN+=t.second.second;
        }
    }
    return{{ES+EN+1,OS+ON},{EN+1,ON}};
}
LL N;
LL i,s,e;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=1;i<N;i++)
    {
        cin>>s>>e;
        adj[s-1].push_back(e-1);
        adj[e-1].push_back(s-1);
    }
    dfs(0,0,0,0,0);
    cout<<sum<<endl;
    return 0;
}