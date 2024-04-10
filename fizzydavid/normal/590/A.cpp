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
int n,a[500111];
int cnt[500111];
int main()
{
    geti(n);
    for(int i=1;i<=n;i++)geti(a[i]);
    int ans=0,tmp=0;
    for(int i=2;i<=n;i++)
    {
        if(i<n&&a[i]!=a[i-1]&&a[i]!=a[i+1])
        {
            tmp++;
        }
        else
        {
            int l=(tmp+1)/2;
            ans=max(ans,l);
            for(int j=i-1;j>=i-l;j--)cnt[j]=i-j;
            for(int j=i-tmp;j<i-tmp+l;j++)cnt[j]=j-(i-tmp)+1;
            tmp=0;
        }
    }
    putsi(ans);
    for(int i=1;i<=n;i++)puti(a[i]^(cnt[i]&1));
    return 0;
}