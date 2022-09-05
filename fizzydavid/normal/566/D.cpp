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
int n,q,nxt[200111];
struct dsu1
{
    int f[200111];
    dsu1(){for(int i=1;i<=200000;i++)f[i]=i;}
    int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
    void un(int x,int y)
    {
        x=gf(x);
        y=gf(y);
        f[x]=y;
    }
}d1;
struct dsu2
{
    int f[200111],nxt[200111];
    dsu2(){for(int i=1;i<=200000;i++)f[i]=i,nxt[i]=i+1;}
    int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
    void un(int x,int y)
    {
        x=gf(x);
        y=gf(y);
        nxt[y]=max(nxt[x],nxt[y]);
        f[x]=y;
    }
}d2;
int main()
{
    getii(n,q);
    for(int i=1;i<=n;i++)nxt[i]=i+1;
    int op,x,y;
    for(int i=1;i<=q;i++)
    {
        getiii(op,x,y);
        if(op==1)d1.un(x,y);
        else if(op==2)
        {
            int pre=x;
            for(int j=d2.nxt[d2.gf(x)];j<=y;j=d2.nxt[d2.gf(j)])
            {
                d1.un(pre,j);
                d2.un(pre,j);
                pre=j;
            }
        }
        else
        {
            if(d1.gf(x)==d1.gf(y))puts("YES");else puts("NO");
        }
    }
    return 0;
}