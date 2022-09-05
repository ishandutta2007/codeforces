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
int Tn,n,k;
char a[5][111];
bool f[5][111];
int main()
{
    geti(Tn);
    while(Tn--)
    {
        memset(f,0,sizeof(f));
        getii(n,k);
        int stx,sty;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j]=mygetchar();
                if(a[i][j]=='s')stx=i,sty=j;
            }
        }
        queue<pair<int,int> >q;
        if(a[stx][sty+1]=='.')q.push(MP(stx,sty+1));
        bool ans=0;
        while(!q.empty())
        {
            int x=q.front().FF,y=q.front().SS;
            q.pop();
            if(f[x][y])continue;
            f[x][y]=1;
            for(int delta=-1;delta<=1;delta++)
            {
                int nx=x+delta,ny=y+3;
                if(nx<1||nx>3)continue;
                bool ok=1;
                for(int j=y;j<=ny&&j<=n;j++)
                {
                    ok&=a[nx][j]=='.';
                }
                if(ok)
                {
                    if(ny>n)
                    {
                        ans=1;
                        break;
                    }
                    q.push(MP(nx,ny));
                }
            }
            if(ans)break;
        }
        if(ans)puts("YES");else puts("NO");
    }
    return 0;
}