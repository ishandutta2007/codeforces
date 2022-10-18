#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct edge
{
    int nxt,to;
}e[5001<<1];
int n,m,tot,h[3001],ans[5],dis[3001][3001];
vector<pair<int,int> > a[3001],b[3001];
bool vis[3001];
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void dijkstra(int s)
{
    queue<pair<int,int> > q;
    for(register int i=1;i<=n;++i)
        vis[i]=0;
    for(register int i=1;i<=n;++i)
        dis[s][i]=0x3f3f3f3f;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        pair<int,int> k=q.front();
        q.pop();
        if(vis[k.second])
            continue;
        vis[k.second]=1;
        dis[s][k.second]=k.first;
        for(register int i=h[k.second];i;i=e[i].nxt)
            if(!vis[e[i].to])
                q.push(make_pair(k.first+1,e[i].to));
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(register int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    for(register int i=1;i<=n;++i)
        dijkstra(i);
    for(register int i=1;i<=n;++i)
    {
        for(register int j=1;j<=n;++j)
            if(i!=j)
            {
                if(dis[i][j]!=0x3f3f3f3f)
                    a[i].push_back(make_pair(dis[i][j],j));
                if(dis[j][i]!=0x3f3f3f3f)
                    b[i].push_back(make_pair(dis[j][i],j));
            }
        sort(a[i].begin(),a[i].end());
        reverse(a[i].begin(),a[i].end());
        sort(b[i].begin(),b[i].end());
        reverse(b[i].begin(),b[i].end());
    }
    for(register int i=1;i<=n;++i)
    {
        int l=b[i].size();
        for(register int j=1;j<=n;++j)
        {
            if(i==j||dis[i][j]==0x3f3f3f3f)
                continue;
            int r=a[j].size();
            for(register int xx=0;xx<3&&xx<l;++xx)
            {
                int x=b[i][xx].second;
                if(x==j)
                    continue;
                for(register int yy=0;yy<3&&yy<r;++yy)
                {
                    int y=a[j][yy].second;
                    if(y==i||y==x)
                        continue;
                    if(dis[x][i]+dis[i][j]+dis[j][y]>ans[0])
                    {
                        ans[0]=dis[x][i]+dis[i][j]+dis[j][y];
                        ans[1]=x;
                        ans[2]=i;
                        ans[3]=j;
                        ans[4]=y;
                    }
                }
            }
        }
    }
    printf("%d %d %d %d\n",ans[1],ans[2],ans[3],ans[4]);
    return 0;
}