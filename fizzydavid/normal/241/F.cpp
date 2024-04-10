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
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
int n,m,k,sx,sy,ex,ey,dis[111][111][26];
pair<int,int> junc[30];
char g[111][111],s[1011];
int len;
#define cost(i,j) (g[i][j]>='a'&&g[i][j]<='z'?1:g[i][j]-'0')
void caldis(int x,int y)
{
    int ox=x,oy=y;
    for(int t=0;t<4;t++)
    {
        int sum=cost(ox,oy);x=ox+dx[t],y=oy+dy[t];
        while(1<=x&&x<=n&&1<=y&&y<=m)
        {
            if(g[x][y]>='a'&&g[x][y]<='z')
            {
                dis[ox][oy][g[x][y]-'a']=sum;
                break;
            }
            else if(g[x][y]=='#')break;
            sum+=g[x][y]-'0';
            x+=dx[t];y+=dy[t];
        }
    }
}
void dfs(int &x,int &y,int nx,int ny)
{
    while(x!=nx||y!=ny)
    {
        k-=cost(x,y);
        if(k<0)return;
        if(x<nx)x++;else if(x>nx)x--;else if(y<ny)y++;else if(y>ny)y--;
    }
}
int main()
{
    getiii(n,m,k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            g[i][j]=mygetchar();
            if(g[i][j]>='a'&&g[i][j]<='z')
            {
                junc[g[i][j]-'a']=MP(i,j);
            }
        }
    }
    getii(sx,sy);
    scanf("%s",s);
    len=strlen(s);
    s[len++]='a'+26;
    getii(ex,ey);
    junc[26]=MP(ex,ey);
    caldis(sx,sy);
    for(int i=0;i<27;i++)caldis(junc[i].FF,junc[i].SS);
    int x=sx,y=sy;
    int i=0;
    while(i<len)
    {
        k-=dis[x][y][s[i]-'a'];
        if(k<0)
        {
            k+=dis[x][y][s[i]-'a'];
            break;
        }
        x=junc[s[i]-'a'].FF;
        y=junc[s[i]-'a'].SS;
        i++;
    }
    if(i<len)dfs(x,y,junc[s[i]-'a'].FF,junc[s[i]-'a'].SS);
    putsii(x,y);
    return 0;
}