#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int n,m,dis[500001][2];
bool vis[500001];
vector<pair<int,int> > v[500001];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void dijkstra()
{
    for(int i=1;i<=n;++i)
        dis[i][0]=dis[i][1]=1e9;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.emplace(0,n);
    dis[n][0]=dis[n][1]=0;
    while(!q.empty())
    {
        pair<int,int> k=q.top();
        q.pop();
        if(vis[k.second])
            continue;
        vis[k.second]=1;
        int val=max(dis[k.second][0],dis[k.second][1]);
        for(auto i:v[k.second])
            if(!vis[i.first]&&dis[i.first][i.second]>val+1)
            {
                dis[i.first][i.second]=val+1;
                if(max(dis[i.first][0],dis[i.first][1])<1e9)
                    q.emplace(max(dis[i.first][0],dis[i.first][1]),i.first);
            }
    }
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read(),w=read();
        v[y].emplace_back(x,w);
    }
    dijkstra();
    int val=max(dis[1][0],dis[1][1]);
    cout<<(val==1e9? -1:val)<<'\n';
    for(int i=1;i<=n;++i)
        cout<<(dis[i][0]<dis[i][1]);
    cout<<'\n';
    return 0;
}