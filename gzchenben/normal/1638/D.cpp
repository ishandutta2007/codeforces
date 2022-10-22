#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m,t,F[1005][1005];
bool vis[1005][1005];
queue<pair<int,int> > Q;

int FindColor(int x,int y)
{
    if(F[x][y]==0 && F[x][y+1]==0 && F[x+1][y]==0 && F[x+1][y+1]==0) return 0;
    int color;
    for(int i=x;i<=x+1;i++) for(int j=y;j<=y+1;j++) if(F[i][j]!=0) color=F[i][j];
    for(int i=x;i<=x+1;i++) for(int j=y;j<=y+1;j++) if(F[i][j]!=0 && F[i][j]!=color) return -1;
    return color; 
}

vector<int> Ans1,Ans2,Ans3;
void Erase(int x,int y,int col)
{
    F[x][y]=F[x][y+1]=F[x+1][y]=F[x+1][y+1]=0;
    Ans1.push_back(x);
    Ans2.push_back(y);
    Ans3.push_back(col);
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&F[i][j]);
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(FindColor(i,j)>=0) 
            {
                Q.push(make_pair(i,j));
                vis[i][j]=true;
            }
        }
    }
    while(!Q.empty())
    {
        auto p=Q.front();
        Q.pop();
        if(FindColor(p.first,p.second)==0) continue;
        Erase(p.first,p.second,FindColor(p.first,p.second));
        for(int i=p.first-1;i<=p.first+1;i++)
        {
            for(int j=p.second-1;j<=p.second+1;j++)
            {
                if(i==n || j==m || i==0 || j==0) continue;
                if(FindColor(i,j)==-1 || vis[i][j]) continue;
                vis[i][j]=true;
                Q.push(make_pair(i,j));
            }
        }
    }
    bool flag=true;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(!vis[i][j]) flag=false;
        }
    }
    if(!flag)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n",Ans1.size());
    for(int i=Ans1.size()-1;i>=0;i--)
    {
        printf("%d %d %d\n",Ans1[i],Ans2[i],Ans3[i]);
    }
}