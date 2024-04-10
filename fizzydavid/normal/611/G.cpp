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
struct point
{
	ll x,y;
	point(ll X=0,ll Y=0){x=X;y=Y;}
	ll det(const point &t)const{return x*t.y-y*t.x;}
	point operator+(const point &t)const{return point((x+t.x)%mod,(y+t.y)%mod);}
	point operator-(const point &t)const{return point((x-t.x+mod)%mod,(y-t.y+mod)%mod);}
	point operator*(const ll &t)const{return point(x*t%mod,y*t%mod);}
	
}a[1000111],prea[1000111];
ll op[1000111];
ll pre[1000111],pre2[1000111];
int n;
ll calcarea(int x,int y)
{
	return op[y-1]-op[x-1]+a[y].det(a[x]);
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		getii(a[i].x,a[i].y);
		a[n+i]=a[i];
	}
	reverse(a+1,a+n+n+1);
//	for(int i=1;i<=2*n;i++)cout<<a[i].x<<","<<a[i].y<<" ";cout<<endl;
	ll area=0,area2=0;
	for(int i=1;i<=2*n;i++)
	{
//		cout<<a[i].det(a[i+1])<<" ";
		prea[i]=prea[i-1]+a[i];
		op[i]=op[i-1]+a[i].det(a[i+1]);
		pre[i]=(pre[i-1]+a[i].det(a[i+1]))%mod;
		pre2[i]=(pre2[i-1]+pre[i])%mod;
	}
	area=op[n];
//	cout<<"area="<<area<<endl;
	area2=area%mod;
	ll ans=0;
	int it=2;
	for(int i=1;i<=n;i++)
	{
		while(calcarea(i,it+1)<=area/2)it++;
//		cout<<"it="<<it<<endl;
		int l=i+2,r=i+n-2;
		ll sum=0;
		sum=(prea[it]-prea[l-1]-prea[r]+prea[it]).det(a[i]);
		sum+=(pre2[it-1]-pre2[i]-1ll*pre[i-1]*(it-1-i)%mod)%mod;
		sum-=(pre2[i+n-3]-pre2[it-1]-1ll*pre[i-1]*(i+n-2-it)%mod)%mod;
		sum=(1ll*area2*(it-l+1-(r-it))-2*sum)%mod;
		ans+=sum;
	}
	cout<<1ll*((ans%mod)+mod)%mod*((mod+1)/2)%mod<<endl;
	return 0;
}