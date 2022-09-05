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
int n,q,a[100111],sum[100111],L,R;
bool rev;
void update(int l,int r)
{
    if(l==0)sum[0]=a[0],l++;
    for(int i=l;i<=r;i++)sum[i]=sum[i-1]+a[i];
}
int main()
{
    getii(n,q);
    for(int i=1;i<=n;i++)a[i]=1,sum[i]=i;
    L=0,R=n;
    while(q--)
    {
        int op,x,y;
        geti(op);
        if(op==1)geti(x);else getii(x,y);
        if(rev)x=R-L-x,y=R-L-y;
        if(op==1)
        {
            if(x*2<=R-L)
            {
                rev=0;
                for(int i=1;i<=x;i++)a[L+x+i]+=a[L+x-i+1];
                L+=x;
                sum[L]=0;
                update(L+1,L+x);
            }
            else
            {
                rev=1;
                for(int i=1;i<=R-L-x;i++)a[L+x-i+1]+=a[L+x+i];
                x=R-L-x;
                R-=x;
                update(R-x,R);
            }
        }
        else
        {
            if(x>y)swap(x,y);
            putsi(sum[L+y]-sum[L+x]);
        }
//      for(int i=L+1;i<=R;i++)cout<<a[i]<<" ";cout<<endl;
//      for(int i=L+1;i<=R;i++)cout<<sum[i]<<" ";cout<<endl;        
    }
    return 0;
}