//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
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
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
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
int A,B,H,W,n;
ll a[100111];
bool f[100111];
int main()
{
	getii(A,B);
	getiii(H,W,n);
	if(H>=A&&W>=B||H>=B&&W>=A)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)geti(a[i]);
	sort(a+1,a+n+1);
	f[1]=1;
	ll prod=1;
	for(int i=n;i>=1;i--)
	{
		if(a[i]==1)break;
		prod*=a[i];
		for(int j=1;j<=100000;j++)
		{
			if(!f[j])continue;
			ll x=a[i]*j,y=prod/x;
			if(H*x>=A&&W*y>=B||H*y>=A&&W*x>=B||
			   H*x>=B&&W*y>=A||H*y>=B&&W*x>=A)
			{
				cout<<n-i+1<<endl;
				return 0;
			}
		}
		for(int j=1;j<=100000/a[i];j++)
		{
			if(!f[j])continue;
			f[j*a[i]]=1;
		}
	}
	puts("-1");
	return 0;
}