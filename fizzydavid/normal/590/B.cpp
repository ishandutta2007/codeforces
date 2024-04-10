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
#define y1 asdfasdfasdf
double x1,y1,x2,y2,v,t,ux1,uy1,ux2,uy2;
int main()
{
    cin>>x1>>y1>>x2>>y2>>v>>t>>ux1>>uy1>>ux2>>uy2;
    ux1=-ux1;uy1=-uy1;ux2=-ux2;uy2=-uy2;
    double l=0,r=1000000000000000000;
    for(int _=0;_<=300;_++)
    {
        double m=(l+r)/2;
        double nx,ny;
        if(m<=t)nx=x2+ux1*m,ny=y2+uy1*m;
        else nx=x2+ux1*t+ux2*(m-t),ny=y2+uy1*t+uy2*(m-t);
        if(sqrt((nx-x1)*(nx-x1)+(ny-y1)*(ny-y1))/v<m)r=m;else l=m;
    }
    cout<<fixed<<setprecision(18)<<l<<endl;
    return 0;
}