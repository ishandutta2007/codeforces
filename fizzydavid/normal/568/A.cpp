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
bool f[4000111];
int p[1000000],pcnt,a[100];
bool ispalin(int x)
{
    int sz=0;
    while(x>0)
    {
        a[sz++]=x%10;
        x/=10;
    }
    for(int i=0;i<sz;i++)if(a[i]!=a[sz-i-1])return false;
    return true;
}
int x,y;
int main()
{
    cin>>x>>y;
    f[0]=f[1]=1;
    for(int i=2;i<=4000000;i++)
    {
        if(!f[i])
        {
            p[pcnt++]=i;
        }
        for(int j=0;j<pcnt&&1ll*p[j]*i<=4000000ll;j++)
        {
            f[i*p[j]]=1;
        }
    }
    int cnt1=0,cnt2=0,ans=-1;
    for(int i=1;i<=4000000;i++)
    {
        if(!f[i])cnt1++;
        if(ispalin(i))cnt2++;
        if(1ll*cnt1*y<=1ll*cnt2*x)
        {
            ans=max(ans,i);
        }
    }
    if(ans==-1)cout<<"Palindromic tree is better than splay tree"<<endl;else cout<<ans<<endl;
    return 0;
}