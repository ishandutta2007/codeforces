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
int n;
pair<pair<ll,ll>,int>a[100111];
ll det(pair<ll,ll>x,pair<ll,ll>y)
{
	return x.FF*y.SS-x.SS*y.FF;
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)getii(a[i].FF.FF,a[i].FF.SS),a[i].SS=i;
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		if(det(MP(a[2].FF.FF-a[1].FF.FF,a[2].FF.SS-a[1].FF.SS),MP(a[i].FF.FF-a[1].FF.FF,a[i].FF.SS-a[1].FF.SS))!=0)
		{
			cout<<a[1].SS<<" "<<a[2].SS<<" "<<a[i].SS<<endl;
			return 0;
		}
	}
	return 0;
}