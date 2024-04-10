//while(true)rp++;
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
#define putsi(x) puti(x),putendl()
#define putsii(x,y) putii(x,y),putendl()
#define putsiii(x,y,z) putiii(x,y,z),putendl()
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
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
const int maxn=1700;
int w,h,c[maxn][maxn],ans[12345];
bool g[maxn][maxn],ng[2][maxn][maxn],vis[maxn][maxn],p;
void color(int x,int y,int id)
{
    c[x][y]=id;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&nx<=w&&ny>0&&ny<=h&&g[nx][ny]&&c[nx][ny]==0)
        {
            color(nx,ny,id);
        }
    }
}
void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&nx<=w&&ny>0&&ny<=h&&g[nx][ny]&&!vis[nx][ny])
        {
            dfs(nx,ny);
        }
    }
}
void getsmaller()
{
    p^=1;
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=h;j++)
        {
            ng[p][i][j]=ng[p^1][i][j];
            for(int k=0;k<4;k++)
            {
                if(!ng[p^1][i+dx[k]][j+dy[k]])
                {
                    ng[p][i][j]=0;
                }
            }
        }
    }
}
void getbigger()
{
    p^=1;
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=h;j++)
        {
            ng[p][i][j]=ng[p^1][i][j];
            for(int k=0;k<4;k++)
            {
                if(ng[p^1][i+dx[k]][j+dy[k]])
                {
                    ng[p][i][j]=1;
                }
            }
        }
    }
}
void see()
{
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=h;j++)
        {
            puti(g[i][j]&(!vis[i][j]));
        }
        putendl();
    }
    putendl();
}
int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    getii(w,h);
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=h;j++)
        {
            geti(g[i][j]);
        }
    }
    int id=0;
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=h;j++)
        {
            if(g[i][j]&&c[i][j]==0)
            {
                id++;
                color(i,j,id);
            }
        }
    }
    for(int i=1;i<=w;i++)for(int j=1;j<=h;j++)ng[p][i][j]=g[i][j];
    getsmaller();getsmaller();getsmaller();
    getbigger();getbigger();getbigger();getbigger();getbigger();
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=h;j++)
        {
            g[i][j]&=!ng[p][i][j];
        }
    }
    for(int i=1;i<=w;i++)for(int j=1;j<=h;j++)ng[p][i][j]=g[i][j];
    getsmaller();getbigger();
    for(int i=1;i<=w;i++)for(int j=1;j<=h;j++)g[i][j]=ng[p][i][j];
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=h;j++)
        {
            if(g[i][j]&&!vis[i][j])
            {
                ans[c[i][j]]++;
                dfs(i,j);
            }
        }
    }
    sort(ans+1,ans+id+1);
    putsi(id);
    for(int i=1;i<=id;i++)puti(ans[i]);
    return 0;
}