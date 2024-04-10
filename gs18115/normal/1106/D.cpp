#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
vector<LL>adj[1234567];
bool vis[1234567];
priority_queue<LL,vector<LL>,greater<LL> >pq;
LL V,E;
LL s,e,i,x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>V>>E;
    for(i=0;i<E;i++)
    {
        cin>>s>>e;
        adj[--s].push_back(--e);
        adj[e].push_back(s);
    }
    vis[0]=true;
    pq.push(0);
    while(!pq.empty())
    {
        x=pq.top();
        pq.pop();
        cout<<x+1<<' ';
        for(i=0;i<adj[x].size();i++)
        {
            if(!vis[adj[x][i]])
            {
                vis[adj[x][i]]=true;
                pq.push(adj[x][i]);
            }
        }
    }
    cout<<endl;
    return 0;
}