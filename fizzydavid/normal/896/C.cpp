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
ll qpow(ll x,ll k,ll md){return k==0?1:qpow(x*x%md,k>>1,md)*(k&1?x:1)%md;}
int n,m;
ll seed,vmax;
struct segment
{
	int l,r;
	ll v;
	bool operator<(const segment &t)const
	{
		return r<t.r;
	}
	segment(int L=0,int R=0,ll V=0){l=L;r=R;v=V;}
};
set<segment> st;
segment query(int x)
{
	return *st.lower_bound(segment(0,x,0));
}

segment tmp[100111];
int tmpn;
void op1(int x,int y,int v)
{
	tmpn=0;
	while(true)
	{
		segment t=query(x);
		if(t.l>y)break;
		st.erase(t);
		if(t.l<x)st.insert(segment(t.l,x-1,t.v));
		if(t.r>y)st.insert(segment(y+1,t.r,t.v));
		tmp[tmpn++]=segment(max(x,t.l),min(t.r,y),t.v+v);
	}
	for(int i=0;i<tmpn;i++)st.insert(tmp[i]);
}
void op2(int x,int y,int v)
{
	while(true)
	{
		segment t=query(x);
		if(t.l>y)break;
		st.erase(t);
		if(t.l<x)st.insert(segment(t.l,x-1,t.v));
		if(t.r>y)st.insert(segment(y+1,t.r,t.v));
	}
	st.insert(segment(x,y,v));
}
pair<ll,segment> p[100111];
int pn;
ll op3(int x,int y,int v)
{
	pn=0;
	while(x<=y)
	{
		segment t=query(x);
		p[pn++]=MP(t.v,segment(max(t.l,x),min(t.r,y),t.v));
		x=t.r+1;
	}
	sort(p,p+pn);
	for(int i=0;i<pn;i++)
	{
		int len=p[i].SS.r-p[i].SS.l+1;
		if(v<=len)return p[i].SS.v;
		v-=len;
	}
}
int op4(int x,int y,int k,int md)
{
	ll sum=0;
	while(x<=y)
	{
		segment t=query(x);
		sum+=1ll*(min(t.r,y)-max(t.l,x)+1)*qpow(t.v%md,k,md);
		x=t.r+1;
	}
	sum=(sum%md+md)%md;
	return sum;
}
ll rnd()
{
	ll ret=seed;
	seed=(seed*7+13)%mod;
	return ret;
}
int main()
{
	getii(n,m);
	getii(seed,vmax);
	for(int i=1;i<=n;i++)
	{
		ll v=rnd()%vmax+1;
		st.insert(segment(i,i,v));
	}
	st.insert(segment(n+1,n+1,0));
	for(int i=1;i<=m;i++)
	{
		int op=rnd()%4+1;
		int l=rnd()%n+1;
		int r=rnd()%n+1;
		int x,y;
		if(l>r)swap(l,r);
		if(op==3)x=(rnd()%(r-l+1))+1;
    	else x=(rnd()%vmax)+1;
    	if(op==4)y=(rnd()%vmax)+1;
    	if(op==1)op1(l,r,x);
    	if(op==2)op2(l,r,x);
    	if(op==3)putsi(op3(l,r,x));
    	if(op==4)putsi(op4(l,r,x,y));
	}
	return 0;
}