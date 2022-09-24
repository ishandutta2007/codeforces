#include<iostream>
#include<vector>
using namespace std;
const int MAXV=1e6+10;
const int INF=1e9;
vector<int>adj[MAXV];
int V,E;
int s,e,i,j;
vector<int>v;
bool vis[MAXV],inc[MAXV];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>V>>E;
    for(i=0;i<E;i++)
    {
        cin>>s>>e;
        adj[s-1].push_back(e-1);
    }
    for(i=0;i<V;i++)
    {
        if(!vis[i])
        {
            inc[i]=true;
            for(j=0;j<adj[i].size();j++)
                vis[adj[i][j]]=true;
        }
    }
    for(i=V;i-->0;)
    {
        if(inc[i])
        {
            v.push_back(i);
            for(j=0;j<adj[i].size();j++)
                inc[adj[i][j]]=false;
        }
    }
    cout<<v.size()<<endl;
    for(i=v.size();i-->0;)
        cout<<v[i]+1<<' ';
    cout<<endl;
    return 0;
}