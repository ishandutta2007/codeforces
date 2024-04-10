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
ll Cx,Cy;
const double eps=1e-10;
const double pi=acos(-1);
inline bool is0(double x){return x<eps&&x>-eps;}
struct point
{
	int x,y;double rad;
	point(int X=0,int Y=0)
	{
		x=X;y=Y;
	}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	ll det(const point &t)const{return 1ll*x*t.y-1ll*y*t.x;}
	ll dot(const point &t)const{return 1ll*x*t.x+1ll*y*t.y;}
	void getrad(){rad=atan2(y,x);}
	bool operator<(point t)const
	{
		return rad<t.rad;
	}
	void out(){cout<<x<<" "<<y<<endl;}
};
bool cmp_init(point x,point y){return MP(x.y,-x.x)>MP(y.y,-y.x);}
const int maxn=2011;
int n;
ll S;
point a[maxn];
int pos[maxn];
void query(int x,point p,ll s)
{
	int l=0,r=n-1;
	while(l<=r)
	{
		int m=l+r>>1;
		ll curs=p.det(a[m]-a[x]);
		if(curs==s)
		{
			puts("Yes");
			a[x].out();
			a[x+1].out();
			a[m].out();
			exit(0);
		}
		else if(curs<s)l=m+1;
		else r=m-1;
	}
}
vector<pair<point,pair<int,int> > > v;
void solve()
{
	v.clear();
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
	{
		v.PB(MP(a[j]-a[i],MP(i,j)));
	}
	for(int i=0;i<v.size();i++)v[i].FF.getrad();
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)pos[i]=i;
	for(int i=0;i<v.size();i++)
	{
		int x=v[i].SS.FF,y=v[i].SS.SS;
		query(pos[x],a[pos[y]]-a[pos[x]],2*S);
		query(pos[x],a[pos[y]]-a[pos[x]],-2*S);
		swap(a[pos[x]],a[pos[y]]);
		swap(pos[x],pos[y]);
	}
	puts("No");
}
int main()
{
//	freopen("1019D.in","r",stdin);
	getii(n,S);
	for(int i=0;i<n;i++)getii(a[i].x,a[i].y);
	sort(a,a+n,cmp_init);
	solve();
	return 0;
}