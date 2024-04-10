#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
int n,m,a[1001][1001],b[1001][1001];
bool vis[1001][1001];
queue<pair<int,int> > q;
vector<pair<pair<int,int>,int> > ans;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    for(int i=1;i<n;++i)
        for(int j=1;j<m;++j)
            if(a[i][j]==a[i+1][j]&&a[i][j]==a[i][j+1]&&a[i][j]==a[i+1][j+1])
            {
                q.push({i,j});
                ans.push_back({{i,j},a[i][j]});
                vis[i][j]=vis[i+1][j]=vis[i][j+1]=vis[i+1][j+1]=1;
            }
    while(!q.empty())
    {
        pair<int,int> k=q.front();
        q.pop();
        for(int i=0;i<8;++i)
        {
            int x=k.first+dx[i],y=k.second+dy[i];
            if(x<=0||x>=n||y<=0||y>=m)
                continue;
            int col=0;
            bool flag=1;
            for(int l=0;l<2&&flag;++l)
                for(int r=0;r<2&&flag;++r)
                {
                    if(vis[x+l][y+r])
                        continue;
                    if(!col)
                    {
                        col=a[x+l][y+r];
                        continue;
                    }
                    if(col^a[x+l][y+r])
                    {
                        flag=0;
                        break;
                    }
                }
            if(!flag||!col)
                continue;
            vis[x][y]=vis[x+1][y]=vis[x][y+1]=vis[x+1][y+1]=1;
            q.push({x,y});
            ans.push_back({{x,y},col});
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(!vis[i][j])
            {
                puts("-1");
                return 0;
            }
    cout<<ans.size()<<'\n';
    reverse(ans.begin(),ans.end());
    for(auto i:ans)
    {
        cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<'\n';
        int x=i.first.first,y=i.first.second;
        b[x][y]=b[x+1][y]=b[x][y+1]=b[x+1][y+1]=i.second;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]^b[i][j])
                puts("fuck");
    return 0;
}