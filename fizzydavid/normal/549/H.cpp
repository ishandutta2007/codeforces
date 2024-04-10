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
double a,b,c,d;
double ans;
double myabs(double x)
{
    return x<0?-x:x;
}
int main()
{
    cin>>a>>b>>d>>c;
    double l=0,r=1000000000;
    for(int i=0;i<=1000;i++)
    {
        ans=(l+r)/2;
        double l1=min(min(min((a-ans)*(c-ans),(a-ans)*(c+ans)),(a+ans)*(c-ans)),(a+ans)*(c+ans));
        double r1=max(max(max((a-ans)*(c-ans),(a-ans)*(c+ans)),(a+ans)*(c-ans)),(a+ans)*(c+ans));
        double l2=min(min(min((b-ans)*(d-ans),(b-ans)*(d+ans)),(b+ans)*(d-ans)),(b+ans)*(d+ans));
        double r2=max(max(max((b-ans)*(d-ans),(b-ans)*(d+ans)),(b+ans)*(d-ans)),(b+ans)*(d+ans));
//      cout<<"ans:"<<fixed<<ans<<endl;
//      cout<<fixed<<l1<<","<<r1<<" "<<l2<<","<<r2<<endl;
        if(l1<=l2&&l2<=r1||l1<=r2&&r2<=r1||l2<=l1&&l1<=r2||l2<=r1&&r1<=r2)
        {
            r=ans;
        }
        else
        {
            l=ans;
        }
    }
    cout<<fixed<<setprecision(10)<<r<<endl;
    return 0;
}