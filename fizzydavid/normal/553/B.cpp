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
ll n,k,f[52];
vector<int>a;
int ans[55];
void dfs(ll x,ll k)
{
    if(x<=2)
    {
        return;
    }
    else
    {
        if(k>f[x-1])
        {
            a.PB(n-x+2);
            k-=f[x-1];
            dfs(x-2,k);
        }
        else
        {
            dfs(x-1,k);
        }
    }
}
int main()
{
    getii(n,k);
    k--;
    if(k==0)
    {
        for(int i=1;i<=n;i++)puti(i);
        return 0;
    }
    else if(k==1)
    {
        for(int i=1;i<=n-2;i++)puti(i);
        putii(n,n-1);
        return 0;
    }
    else if(k==2)
    {
        for(int i=1;i<=n-3;i++)puti(i);
        putiii(n-1,n-2,n);
        return 0;
    }
    k-=2;
    f[1]=1;
    f[2]=1;
    for(int i=3;i<=50;i++)
    {
        f[i]=f[i-1]+f[i-2];
        if(k>f[i])k-=f[i];
        else
        {
            a.PB(n-i),dfs(i,k);
            break;
        }
    }
    for(int i=1;i<=n;i++)ans[i]=i;
    for(int i=0;i<a.size();i++)
    {
        swap(ans[a[i]],ans[a[i]+1]);
    }
    for(int i=1;i<=n;i++)puti(ans[i]);
    return 0;
}