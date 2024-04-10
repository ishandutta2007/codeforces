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
vector<pair<ll,ll> >ans;
bool gcd(ll x,ll y)
{
	if(x==1||y==1)
	{
		if(x==1)
		{
			ans.PB(MP(y-1,2));
		}
		else
		{
			ans.PB(MP(x-1,1));
		}
		return true;
	}
	else if(x==0||y==0)return false;
	if(x>y)
	{
		ans.PB(MP(x/y,1));
		return gcd(x%y,y);
	}
	else
	{
		ans.PB(MP(y/x,2));
		return gcd(x,y%x);
	}
}
int main()
{
	ll a,b;
	cin>>a>>b;
	ans.clear();
	if(gcd(a,b))
	{
	//	ll xx=1,xy=0,yx=0,yy=1;
		for(int i=0;i<ans.size();i++)
		{
			if(ans[i].SS==1)
			{
	//			yx+=ans[i].FF*xx;
	//			yy+=ans[i].FF*xy;
				cout<<ans[i].FF<<"A";
			}
			else
			{
	//			xx+=ans[i].FF*yx;
	//			xy+=ans[i].FF*yy;
				cout<<ans[i].FF<<"B";
			}
		}
	//	if(xx+yx!=a||xy+yy!=b)
	//	{
	//		cout<<"oh no"<<endl;
	//	}
	}
	else
	{
		puts("Impossible");
	}
	return 0;
}