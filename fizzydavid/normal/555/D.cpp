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
int n,m,id[200111];
ll a[200111];
pair<ll,int>t[200111];
int calc(int l,int r,ll restl,bool dir)
{
    if(l==r)return t[l].SS;
    if((restl/(a[r]-a[l]))&1)dir^=1;
    restl%=(a[r]-a[l]);
    if(dir)
    {
        int tmp=lower_bound(a+1,a+n+1,a[r]-restl)-a;
        restl-=a[r]-a[tmp];
        return calc(tmp,r,restl,0);
    }
    else
    {
        int tmp=upper_bound(a+1,a+n+1,a[l]+restl)-a-1;
        restl-=a[tmp]-a[l];
        return calc(l,tmp,restl,1);
    }
}
int main()
{
    getii(n,m);
    ll x,y;
    for(int i=1;i<=n;i++)geti(t[i].FF),t[i].SS=i;
    sort(t+1,t+n+1);
    for(int i=1;i<=n;i++)a[i]=t[i].FF,id[t[i].SS]=i;
    for(int i=1;i<=m;i++)
    {
        getii(x,y);
        x=id[x];
        if(a[x]+y<=a[n])
        {
            int tmp=upper_bound(a+1,a+n+1,a[x]+y)-a-1;
            putsi(calc(1,tmp,y-a[tmp]+a[x],1));
        }
        else
        {
            putsi(calc(1,n,y-(a[n]-a[x]),1));
        }
    }
    return 0;
}