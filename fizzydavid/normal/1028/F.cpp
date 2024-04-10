//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
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
const double pi=acos(-1);
const double eps=1e-12;
bool is0(double x){return x>-eps&&x<eps;}
unordered_map<ll,int> ANS;
const ll BASE=1e12;
void Inc(double r,int v=2)
{
	ll x=r*BASE;
	ANS[x]+=v;
}
void Dec(double r,int v=2)
{
	ll x=r*BASE;
	ANS[x]-=v;
}
int Query(double r)
{
	ll x=r*BASE;
	return ANS[x-1]+ANS[x]+ANS[x+1];
}
struct data
{
	vector<double>v;
	void add_point(double r)
	{
		for(int i=0;i<v.size();i++)Inc((v[i]+r)/2);
		v.PB(r);
	}
	void del_point(double r)
	{
		for(int i=0;i<v.size();i++)
		{
			if(is0(v[i]-r))
			{
				swap(v[i],v.back());
				v.resize(v.size()-1);
			}
		}
		for(int i=0;i<v.size();i++)Dec((v[i]+r)/2);
	}
};
unordered_map<ll,data> yxg;
int q;
int main()
{
	int cur=0;
	geti(q);
	for(int i=1;i<=q;i++)
	{
		int op,x,y;
		getiii(op,x,y);
		ll l=1ll*x*x+1ll*y*y;
		double r=atan2(y,x);
		if(op==1)
		{
			yxg[l].add_point(r);
			Inc(r,1);
			cur++;
		}
		else if(op==2)
		{
			yxg[l].del_point(r);
			Dec(r,1);
			cur--;
		}
		else
		{
			int ans=0;
			if(r-pi>-pi-eps)ans+=Query(r-pi);
			ans+=Query(r);
			if(r+pi<pi+eps)ans+=Query(r+pi);
			putsi(cur-ans);
		}
	}
	return 0;
}