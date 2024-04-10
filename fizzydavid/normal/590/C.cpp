//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
    register ll r=0;register bool ng=0;register char c;c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    if(c=='-')ng=1,c=getchar();
    while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
    if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
    if(x<0)putchar('-'),x=-x;
    register short a[20]={},sz=0;
    while(x>0)a[sz++]=x%10,x/=10;
    if(sz==0)putchar('0');
    for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
char g[1011][1011];
int num[1011][1011],n,m,tot,dis[4][1000111];
vector<int>con[1000111];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
void bfs(int X)
{
    queue<int>q;
    q.push(X);
    for(int i=1;i<=tot;i++)dis[X][i]=-1;
    dis[X][X]=0;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=0;i<con[x].size();i++)
        {
            int u=con[x][i];
            if(dis[X][u]==-1)
            {
                dis[X][u]=dis[X][x]+1;
                q.push(u);
            }
        }
    }
}           
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",g[i]+1);
    tot=3;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(g[i][j]=='.')
            {
                num[i][j]=++tot;
            }
            else if(g[i][j]>='1'&&g[i][j]<='3')num[i][j]=g[i][j]-'0';
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=0;k<4;k++)
    {
        int nx=i+dx[k],ny=j+dy[k];
        if(nx>=1&&ny>=1&&nx<=n&&ny<=m&&num[nx][ny]>=1)
        {
            con[num[i][j]].PB(num[nx][ny]);
        }
    }
    for(int i=1;i<=tot;i++)
    {
        sort(con[i].begin(),con[i].end());
        con[i].erase(unique(con[i].begin(),con[i].end()),con[i].end());
    }
    bfs(1);bfs(2);bfs(3);
    int ans=INF;
    for(int i=1;i<=tot;i++)
    {
        if(dis[1][i]!=-1&&dis[2][i]!=-1&&dis[3][i]!=-1)
        {
            ans=min(ans,dis[1][i]+dis[2][i]+dis[3][i]-2);
        }
    }
    if(ans==INF)cout<<-1<<endl;else cout<<ans<<endl;
    return 0;
}