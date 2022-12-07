#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
int n,m,Blocks,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
vector<vector<int> > a,Block;
vector<int> Edges[400005];

int dfn[400005],low[400005],col[400005],Points,Colors;
bool Insta[400005];
stack<int> Sta;
void tarjan(int x)
{
    low[x]=dfn[x]=++Points;
    Sta.push(x);
    Insta[x]=true;
    for(auto &y : Edges[x])
    {
        if(Insta[y]) 
        {
            low[x]=min(low[x],dfn[y]);
        }
        else if(!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
    }
    if(low[x]==dfn[x])
    {
        Colors++;
        while(Sta.top()!=x)
        {
            col[Sta.top()]=Colors;
            Insta[Sta.top()]=false;
            Sta.pop();
        }
        col[x]=Colors;
        Insta[x]=false;
        Sta.pop();
    }
}
void dfs(int x,int y,int c)
{
    Block[x][y]=c;
    for(int i=0;i<4;i++)
    {
        if(a[x+dx[i]][y+dy[i]] && !Block[x+dx[i]][y+dy[i]])
        {
            dfs(x+dx[i],y+dy[i],c);
        }
    }
}

bool In[400005];
int main()
{
    scanf("%d%d",&n,&m);
    a.resize(n+2);
    Block.resize(n+2);
    for(int i=0;i<=n+1;i++) 
    {
        a[i].resize(m+2);
        Block[i].resize(m+2);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char tmp;
            scanf(" %c",&tmp);
            if(tmp=='#') a[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j] && !Block[i][j])
            {
                Blocks++;
                dfs(i,j,Blocks);
            }
            //printf("%d ",Block[i][j]);
        }
        //printf("\n");
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(!a[i][j]) continue;
            bool flag1=false,flag2=false;
            for(int k=i+1;k<=n;k++)
            {
                if(a[k][j])
                {
                    if(Block[i][j]!=Block[k][j]) Edges[Block[i][j]].push_back(Block[k][j]);
                    break;
                } 
                if(a[k][j-1] && !flag1)
                {
                    if(Block[i][j]!=Block[k][j-1]) Edges[Block[i][j]].push_back(Block[k][j-1]);
                    flag1=true;
                }
                if(a[k][j+1] && !flag2)
                {
                    if(Block[i][j]!=Block[k][j+1]) Edges[Block[i][j]].push_back(Block[k][j+1]);
                    flag2=true;
                }
            }
        }
    }
    for(int i=1;i<=Blocks;i++)
    {
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=Blocks;i++)
    {
        for(auto &p : Edges[i])
        {
            if(col[i]!=col[p]) In[col[p]]=true;
        }
    }
    int ans=0;
    for(int i=1;i<=Colors;i++)
    {
        if(!In[i]) ans++;
    }
    printf("%d\n",ans);
}