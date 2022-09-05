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
ll n,k,l,m;
struct matrix22
{
    ll a,b,c,d;
    matrix22()
    {
        a=b=c=d=0;
    }
    void inite()
    {
        a=d=1;
    }
    void operator*=(const matrix22 &tmp)
    {
        matrix22 res;
        res.a=(a*tmp.a%m+b*tmp.c%m)%m;
        res.b=(a*tmp.b%m+b*tmp.d%m)%m;
        res.c=(c*tmp.a%m+d*tmp.c%m)%m;
        res.d=(c*tmp.b%m+d*tmp.d%m)%m;
        a=res.a;
        b=res.b;
        c=res.c;
        d=res.d;
    }
}t;
matrix22 kissme(matrix22 x,ll p)
{
    matrix22 ans;
    ans.inite();
    while(p>0)
    {
        if(p&1)ans*=x;
        p>>=1;
        x*=x;
    }
    return ans;
}
ll kissme(ll x,ll p)
{
    ll ans=1;
    while(p>0)
    {
        if(p&1)ans=ans*x%m;
        p>>=1;
        x=x*x%m;
    }
    return ans;
}
int main()
{
    getii(n,k);
    getii(l,m);
    if(l<62&&(k>>l)>0)
    {
        puts("0");
        return 0;
    }
    ll p2=kissme(2,n);
    t.a=1;t.b=1;t.c=1;
    t=kissme(t,n+1);
    ll ans=1;
    for(int i=0;i<l;i++)
    {
        if((k>>i)&1)
        {
            ans=ans*((p2-t.a+m)%m)%m;
        }
        else 
        {
            ans=ans*t.a%m;
        }
    }
    putsi(ans%m);
    return 0;
}