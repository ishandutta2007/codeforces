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
#define puti(x) putnum(x)
#define putii(x,y) puti(x),putnum(y)
#define putiii(x,y,z) putii(x,y),putnum(z)
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
const int gx[]={-1,-1,-1,0,0,1,1,1};
const int gy[]={-1,0,1,-1,1,-1,0,1};
#define cid(x,y) (x-1)*m+y
int p[18000111],n,m,q;
int gf(int x)
{
    return x==p[x]?x:(p[x]=gf(p[x]));
}
pair<int,int>tmp[100];
int sz,ans;
bool land[3011][6011];
vector<int>v1,v2;
int main()
{
    for(int i=1;i<=18000000;i++)p[i]=i;
    getiii(n,m,q);
    m=m*2;
    for(int i=1;i<=q;i++)
    {
        v1.clear();v2.clear();
        int x,y,id;
        getii(x,y);id=cid(x,y);
        sz=0;
        for(int j=0;j<8;j++)
        {
            int nx=x+gx[j],ny=y+gy[j];
            if(ny<1)ny+=m;
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&land[nx][ny])
            {
                v1.PB(gf(cid(nx,ny)));
                tmp[sz++]=MP(id,cid(nx,ny));
            }
        }
        for(int j=0;j<8;j++)
        {
            int nx=x+gx[j],ny=y+m/2+gy[j];
            if(ny>m)ny-=m;
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&land[nx][ny])
            {
                v2.PB(gf(cid(nx,ny)));
                tmp[sz++]=MP(id+m/2,cid(nx,ny));
            }
        }
        bool ok=0;
        for(int j=0;j<v1.size();j++)for(int k=0;k<v2.size();k++)if(v1[j]==v2[k])ok=1;
        if(!ok&&m!=2)
        {
            ans++;
            land[x][y]=1,land[x][y+m/2]=1;
            for(int j=0;j<sz;j++)p[gf(tmp[j].FF)]=gf(tmp[j].SS);
        }
    }
    putsi(ans);
    return 0;
}