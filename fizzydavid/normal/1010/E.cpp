//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn=1000111;
int n1,n2,n3;
int n;
struct point
{
	int x,y,z,id;
	point(int X=0,int Y=0,int Z=0,int Id=0){x=X;y=Y;z=Z;id=Id;}
	bool operator<(const point &t)const
	{
		if(x!=t.x)return x<t.x;
		if((id!=0)!=(t.id!=0))return (id!=0)<(t.id!=0);
		return false;
	}
}a[maxn];
int xl=1e9,xr=0;
int yl=1e9,yr=0;
int zl=1e9,zr=0;
bool suit(int x,int y,int z){return x>=xl&&x<=xr&&y>=yl&&y<=yr&&z>=zl&&z<=zr;}
int ANS[maxn];
const int maxtn=100111;
int tab[maxtn];
void add(int x,int v){for(int i=x;i<maxtn;i+=(i&(-i)))tab[i]+=v;}
int query(int x){int ret=0;for(int i=x;i;i-=i&(-i))ret+=tab[i];return ret;}
void solve(vector<point> &v)
{
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		if(v[i].id==0)add(v[i].y,1);
		else
		{
			if(v[i].id>0)ANS[v[i].id]+=query(v[i].y);
			else ANS[-v[i].id]-=query(v[i].y);
		}
	}
	for(int i=0;i<v.size();i++)
	{
		if(v[i].id==0)add(v[i].y,-1);
	}
}
void solve(int l,int r)
{
	if(l>=r)return;
	int m=l+r>>1;
	vector<point> v;
	for(int i=l;i<=m;i++)
	{
		if(a[i].id==0)
		{
			v.PB(point(a[i].y,a[i].z,0,a[i].id));
		}
	}
	for(int i=m+1;i<=r;i++)
	{
		if(a[i].id!=0)
		{
			v.PB(point(a[i].y,a[i].z,0,a[i].id));
		}
	}
	solve(v);
	solve(l,m);
	solve(m+1,r);
}
void solve()
{
	sort(a+1,a+n+1);
	solve(1,n);
}
int main()
{
	int yxg;
	getiii(yxg,yxg,yxg);
	getiii(n1,n2,n3);
	for(int i=1;i<=n1;i++)
	{
		int x,y,z;
		getiii(x,y,z);
		xl=min(xl,x);xr=max(xr,x);
		yl=min(yl,y);yr=max(yr,y);
		zl=min(zl,z);zr=max(zr,z);
	}
	for(int i=1;i<=n2;i++)
	{
		int x,y,z;
		getiii(x,y,z);
		if(suit(x,y,z))
		{
			puts("INCORRECT");
			return 0;
		}
		a[++n]=point(x,y,z,0);
	}
	for(int i=1;i<=n3;i++)
	{
		int x,y,z;
		getiii(x,y,z);
		if(suit(x,y,z))
		{
			ANS[i]=-1;
		}
		else
		{
			int XL=min(xl,x);
			int XR=max(xr,x);
			int YL=min(yl,y);
			int YR=max(yr,y);
			int ZL=min(zl,z);
			int ZR=max(zr,z);
			a[++n]=point(XR  ,YR  ,ZR  ,i);
			a[++n]=point(XL-1,YR  ,ZR  ,-i);
			a[++n]=point(XR  ,YL-1,ZR  ,-i);
			a[++n]=point(XL-1,YL-1,ZR  ,i);
			a[++n]=point(XR  ,YR  ,ZL-1,-i);
			a[++n]=point(XL-1,YR  ,ZL-1,i);
			a[++n]=point(XR  ,YL-1,ZL-1,i);
			a[++n]=point(XL-1,YL-1,ZL-1,-i);
		}
	}
	solve();
	puts("CORRECT");
	for(int i=1;i<=n3;i++)
	{
//		cerr<<ANS[i]<<endl;
	}
	for(int i=1;i<=n3;i++)
	{
		if(ANS[i]==-1)puts("OPEN");
		else if(ANS[i]==0)puts("UNKNOWN");
		else puts("CLOSED");
	}
	return 0;
}