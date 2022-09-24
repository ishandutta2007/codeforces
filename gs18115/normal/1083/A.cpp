#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const LL MAXV=3e5+10;
vector<pair<int,LL> >adj[MAXV];
LL W[MAXV];
LL MAX=-INF;
void dfs(LL X,LL P)
{
    vector<LL>V;
    for(int i=0;i<adj[X].size();i++)
    {
        int x=adj[X][i].first;
        int w=adj[X][i].second;
        if(x==P)
            continue;
        dfs(x,X);
        V.push_back(W[x]-w);
    }
    sort(V.begin(),V.end(),greater<LL>());
    if(V.size()>1)
        MAX=max(MAX,V[0]+V[1]+W[X]);
    if(!V.empty()&&V[0]>0)
        W[X]+=V[0];
    MAX=max(MAX,W[X]);
    return;
}
int N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>W[i];
    for(int i=1;i<N;i++)
    {
        int s,e,l;
        cin>>s>>e>>l;
        adj[--s].emplace_back(--e,l);
        adj[e].emplace_back(s,l);
    }
    dfs(0,-1);
    cout<<MAX<<endl;
    return 0;
}