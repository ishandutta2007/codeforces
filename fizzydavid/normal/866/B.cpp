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
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
int n;
ll s,a[100111],b[100111],c[100111];
ll cntf,sum;
priority_queue<pair<ll,ll> >pq;
ll calc(ll y)
{
//	cerr<<"calc:"<<y<<endl;
	while(!pq.empty())pq.pop();
	for(int i=1;i<=n;i++)
	{
		pq.push(MP(c[i]-b[i],a[i]));
	}
	ll lft=y;
	ll ans=sum;
//	st2.clear();
	while(!pq.empty())
	{
		ll p=pq.top().FF,c=pq.top().SS;
		pq.pop();
		ll t=min(c,lft);
//		if(t>0)st2.insert(MP(-p,t));
//		cerr<<"add:"<<p<<" "<<t<<endl;
		ans+=t*(p);
		lft-=t;
	}
//	cerr<<"ans="<<ans<<endl;
	return ans;
}
int main()
{
	getii(n,s);
	ll tot=0;
	ll t=0;
	for(int i=1;i<=n;i++)
	{
		getiii(a[i],b[i],c[i]);
		sum+=a[i]*b[i];
		tot+=a[i];
		if(b[i]<c[i])
		{
			t+=a[i];
		}
	}
	cntf=tot;
	tot=(tot+s-1)/s;
	cntf=tot*s-cntf;
//	cerr<<"tot="<<tot<<endl;
//	cerr<<cntf<<endl;
	ll ans=calc((t/s)*s);
	if(t/s+1<=tot)ans=max(ans,calc((t/s)*s+max(0ll,max(t%s,s-cntf))));
	cout<<ans<<endl;
	return 0;
}