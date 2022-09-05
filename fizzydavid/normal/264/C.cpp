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
int n,k;
int v[100111],c[100111];
ll a[100111];
int main()
{
    getii(n,k);
    for(int i=1;i<=n;i++)geti(v[i]);
    for(int i=1;i<=n;i++)geti(c[i]);
    while(k--)
    {
        ll A,B;
        getii(A,B);
        for(int i=0;i<=n;i++)a[i]=-LINF;
        ll ans=0,mx=0,mx2=0;
        for(int i=1;i<=n;i++)
        {
            ll tmp;
            if(mx==c[i])tmp=a[mx2];else tmp=a[mx];
            if(tmp<0)tmp=0;
            tmp=max(tmp+v[i]*B,a[c[i]]+v[i]*A);
            a[c[i]]=max(tmp,a[c[i]]);
            if(a[c[i]]>=a[mx]&&c[i]!=mx)mx2=mx,mx=c[i];
            else if(a[c[i]]>a[mx2]&&c[i]!=mx)mx2=c[i];
            ans=max(ans,tmp);
        }
        putsi(ans);
    }
    return 0;
}