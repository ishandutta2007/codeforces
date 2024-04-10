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

struct point//integer
{
	ll x,y;
	point(ll X=0,ll Y=0){x=X;y=Y;}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
	ll det(const point &t)const
	{
		double tmp=1.0*x*t.y-1.0*y*t.x;
		if(tmp>1e18)return 1e18;
		if(tmp<-1e18)return -1e18;
		return x*t.y-y*t.x;
	}
	bool operator<(const point &t)const{return MP(x,y)<MP(t.x,t.y);}
	bool operator==(const point &t)const{return MP(x,y)==MP(t.x,t.y);}
	ll sqrl(){return x*x+y*y;}
};
point a[100111];
int ch[100111],chn;
int st[100111],stn;
vector<ll> mini(vector<ll> v)
{
	if(v.size()==1)return v;
	vector<ll> ret;
	int i=0,j=1,k=0,n=v.size();
	while(i!=j&&i<n&&j<n)
	{
		k=0;
		while(k<n&&v[(i+k)%n]==v[(j+k)%n])k++;
		if(v[(i+k)%n]<v[(j+k)%n])j=max(j+k+1,i+1);
		else i=max(i+k+1,j+1);
	}
	int pos=min(i,j);
	for(int t=0;t<n;t++)ret.PB(v[(pos+t)%n]);
//	for(int i=0;i<n;i++)cerr<<ret[i]<<" ";cerr<<endl;
	return ret;
}
vector<ll> getv(int n)
{
	for(int i=1;i<=n;i++)
	{
		getii(a[i].x,a[i].y);
	}
	stn=0;
	sort(a+1,a+n+1);
	chn=0;
	for(int i=1;i<=n;i++)
	{
		while(chn>=2&&(a[i]-a[ch[chn-2]]).det(a[ch[chn-1]]-a[ch[chn-2]])>=0)chn--;
		ch[chn++]=i;
	}
	for(int i=0;i<chn;i++)st[stn++]=ch[i];
	chn=0;
	for(int i=1;i<=n;i++)
	{
		while(chn>=2&&(a[i]-a[ch[chn-2]]).det(a[ch[chn-1]]-a[ch[chn-2]])<=0)chn--;
		ch[chn++]=i;
	}
	for(int i=chn-2;i>0;i--)st[stn++]=ch[i];
	st[stn]=st[0];
	vector<point> v;
	for(int i=0;i<stn;i++)
	{
		v.PB(a[st[i+1]]-a[st[i]]);
	}
	v.PB(v[0]);
	vector<ll> ret;
	for(int i=0;i+1<v.size();i++)
	{
		ret.PB(v[i].sqrl());
		ret.PB((v[i+1]-v[i]).sqrl());
	}
	ret=mini(ret);
//	for(int i=0;i<ret.size();i++)cerr<<ret[i]<<" ";cerr<<endl;
	return ret;
}
vector<ll> A,B;
int n,m;
int main()
{
	getii(n,m);
	A=getv(n);
	B=getv(m);
	if(A==B)puts("YES");
	else puts("NO");
	return 0;
}