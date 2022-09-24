#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAXV=2e5+10;
const int INF=1e9;
vector<int>adj[MAXV];
queue<int>Q;
bool vis[MAXV];
int pa[MAXV];
int arr[MAXV];
int cnt;
inline void bfs()
{
    vis[0]=true;
    Q.push(0);
    while(!Q.empty())
    {
        int h=Q.front();
        Q.pop();
        for(int i=0;i<adj[h].size();i++)
        {
            if(!vis[adj[h][i]])
            {
                vis[adj[h][i]]=true;
                pa[adj[h][i]]=h;
                Q.push(adj[h][i]);
            }
        }
    }
    return;
}
inline void bfs2()
{
    vis[0]=true;
    Q.push(0);
    while(!Q.empty())
    {
        int h=Q.front();
        Q.pop();
        if(h!=arr[cnt++])
        {
            cout<<"No"<<endl;
            exit(0);
        }
        for(int i=0;i<adj[h].size();i++)
        {
            if(!vis[adj[h][i]])
            {
                vis[adj[h][i]]=true;
                pa[adj[h][i]]=h;
                Q.push(adj[h][i]);
            }
        }
    }
    return;
}
int N,i,s,e;
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
    bfs();
    for(i=0;i<N;i++)
        adj[i].clear();
    for(i=0;i<N;i++)
    {
        cin>>arr[i];
        arr[i]--;
        if(arr[i]==0)
            continue;
        else
            adj[pa[arr[i]]].push_back(arr[i]);
    }
    fill(vis,vis+N,false);
    bfs2();
    cout<<"Yes"<<endl;
    return 0;
}