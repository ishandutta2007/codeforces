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
const ll Lbg=2e18;
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
int n;
int a[66],b[66];
map<ll,int> lg2;
int c[66],d[66];
bool check(int x)
{
	int mn=x,sum=0;
	for(int i=0;i<60;i++)
	{
		mn=min(mn,a[i]);
		c[i]=mn;
	}
//	for(int i=0;i<5;i++)cout<<c[i]<<" ";cout<<endl;
	memset(d,0,sizeof(d));
	for(int i=60;i>=0;i--)
	{
		int need=b[i+1]+a[i]-c[i];
		sum+=need;
		if(sum>c[i])return false;
	}
	return true;
}
int main()
{
	for(int i=0;i<60;i++)lg2[1ll<<i]=i;
	geti(n);
	for(int i=1;i<=n;i++)
	{
		ll x;
		geti(x);
		if((x&(-x))==x)
		{
			a[lg2[x]]++;
		}
		else
		{
			while((x&(-x))!=x)x+=x&(-x);
			b[lg2[x]]++;
		}
	}
	int l=1,r=a[0];
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	for(int i=l;i<=a[0];i++)printf("%d ",i);
	if(l>a[0])puts("-1");
	return 0;
}