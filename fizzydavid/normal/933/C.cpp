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
const double eps=1e-7;
bool is0(double x){return x>-eps&&x<eps;}
struct point
{
	double x,y;
	point(double X=0,double Y=0){x=X;y=Y;}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	point operator*(const double &t)const{return point(x*t,y*t);}
	point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
	double det(const point &t)const{return x*t.y-y*t.x;}
	double dot(const point &t)const{return x*t.x+y*t.y;}
	double sqrl()const{return x*x+y*y;}
	point unit()const{return (*this)*(1.0/sqrt(sqrl()));}
	bool operator<(const point &t)const{return is0(x-t.x)?(is0(y-t.y)?0:y<t.y):x<t.x;}
	bool operator==(const point &t)const{return is0(x-t.x)&&is0(y-t.y);}
};
point v[111];
int vn;
int cycle_intersect(point p,double pr,point q,double qr)
{
	if((p-q).sqrl()>(pr+qr)*(pr+qr)+eps||(p-q).sqrl()<(pr-qr)*(pr-qr)-eps)return 0;
	double sqrd=(p-q).sqrl();
	double x=(sqrd+pr*pr-qr*qr)/2/sqrd;
	point mid=(q-p)*x+p;
	double l2=pr*pr-(mid-p).sqrl();
	assert(l2>-eps);
	double l=sqrt(l2);
	if(is0(l2))
	{
		v[vn++]=mid;
		return 1;
	}
	v[vn++]=mid+(q-p).unit()*point(0,+1)*l;
	v[vn++]=mid+(q-p).unit()*point(0,-1)*l;
	return 2;
}
int n;
point a[5];
double ar[5];
int f[5];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		f[i]=i;
		int x,y,r;
		cin>>x>>y>>r;
		a[i]=point(x,y);
		ar[i]=r;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int t=cycle_intersect(a[i],ar[i],a[j],ar[j]);
			if(t>0)f[gf(i)]=gf(j);
		}
	}
	sort(v,v+vn);
	vn=unique(v,v+vn)-v;
//	cerr<<"vn="<<vn<<endl;
//	for(int i=0;i<vn;i++)cerr<<v[i].x<<","<<v[i].y<<" ";cerr<<endl;
	int V=vn,E=0,C=0;
	for(int i=0;i<n;i++)C+=gf(i)==i;
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=0;j<vn;j++)
		{
			if(is0((v[j]-a[i]).sqrl()-ar[i]*ar[i]))cnt++;
		}
		E+=cnt;
	}
//	cerr<<E<<" "<<V<<" "<<C<<endl;
	cout<<1+E-V+C<<endl;
	return 0;
}