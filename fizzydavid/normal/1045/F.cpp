//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
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
struct point
{
	ll x,y;
	point(ll X=0,ll Y=0){x=X;y=Y;}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	ll det(const point &t)const{return x*t.y-y*t.x;}
	bool operator<(const point &t)const{return MP(x,y)<MP(t.x,t.y);}
	bool check(){return x%2==1||y%2==1;}
};
const int maxn=200111;
point a[maxn];
bool ban[maxn];
vector<int> get_chull(int l,int r)
{
	vector<int> ret;
	for(int i=l;i<=r;i++)
	{
		if(ban[i])continue;
		while(ret.size()>=1&&a[ret.back()].x==a[i].x&&a[i].y>=a[ret.back()].y)ret.pop_back();
		while(ret.size()>=2)
		{
			int p=ret.back();
			int q=ret[ret.size()-2];
			if((a[p]-a[q]).det(a[i]-a[q])>=0)ret.pop_back();else break;
		}
		ret.PB(i);
	}
	return ret;
}
int n;
vector<int> v;
void check(vector<int> v)
{
	for(int i=0;i<v.size();i++)if(a[v[i]].check())
	{
		puts("Ani");
		exit(0);
	}
	
}
void solve()
{
	sort(a,a+n);
	v=get_chull(0,n-1);
	check(v);
	for(int i=0;i<v.size();i++)
	{
		if(a[v[i]].x==0&&a[v[i]].y==0)continue;
		int l=0,r=n-1;
		if(i>0)l=v[i-1];
		if(i+1<v.size())r=v[i+1];
		ban[v[i]]=1;
		check(get_chull(l,r));
		ban[v[i]]=0;
	}	
}
int main()
{
	geti(n);
	for(int i=0;i<n;i++)getii(a[i].x,a[i].y);
	a[n++]=point(0,0);
	solve();
	for(int i=0;i<n;i++)swap(a[i].x,a[i].y);
	solve();
	puts("Borna");
	return 0;
}