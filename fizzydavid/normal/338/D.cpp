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
ll r,c,a[10011];
int n;
ll kissmul(ll x,ll y,ll md)
{
	ll ret=x*y-ll(1.0*x/md*y+1e-8)*md;
	while(ret<0)ret+=md;
	while(ret>=md)ret-=md;
	return ret;
}
pair<ll,ll> extgcd(ll x,ll y,ll t,ll md)
{
	if(y==0)return MP(t/x,0);
	else
	{
		pair<ll,ll> p=extgcd(y,x%y,t,md);
		return MP(p.SS,(p.FF-kissmul(x/y,p.SS,md))%md);
	}
}
int main()
{
	getiii(r,c,n);
	ll R=1;
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
		ll g=__gcd(R,a[i]);
		if(1.0*R/g*a[i]>Lbig)
		{
			puts("NO");
			return 0;
		}
		R=R/g*a[i];
	}
//	cout<<"R="<<R<<endl;
	if(R>r)
	{
		puts("NO");
		return 0;
	}
	ll M=1,C=0;
	for(int i=1;i<=n;i++)
	{
		ll m=a[i],c=(m-i%m)%m;
		ll gm=__gcd(m,M);
		if(C%gm!=c%gm)
		{
			puts("NO");
			return 0;
		}
		ll nm=M/gm*m;
		pair<ll,ll> p=extgcd(M,m,c-C,nm);
		C=((kissmul(p.FF,M,nm)+C)%nm+nm)%nm;
		M=nm;
//		cout<<m<<" "<<c<<" "<<p.FF<<" "<<p.SS<<" "<<C<<" "<<M<<endl;
	}
//	cout<<"C="<<C<<endl;
	if(C+n>c)puts("NO");
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(__gcd(R,C+i)!=a[i])
			{
				puts("NO");
				return 0;
			}
		}
		puts("YES");
	}
	return 0;
}