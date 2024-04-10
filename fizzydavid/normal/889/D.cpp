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
ll n;
pair<ll,ll> a[2111];
ll sumx,sumy;
ll b[2011];
set<pair<ll,ll> >st;
bool check(ll cx,ll p,ll q)//t=p/q
{
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i].FF*cx*q+a[i].SS*p;
	}
	sort(b+1,b+n+1);
	ll M2=b[1]+b[n];
	for(int i=1;i<=n;i++)
	{
		if(b[i]+b[n-i+1]!=M2)return false;
	}
	return true;
}
bool matched[2011];
int mcnt;
void pre_go(int i)
{
	for(int j=i+1;j<=n;j++)
	{
		ll p=n*(-a[i].FF-a[j].FF)+2*sumx;
		ll q=n*(a[i].SS+a[j].SS)-2*sumy;
		if(p==0&&q==0)
		{
			assert(matched[i]==0&&matched[j]==0);
			matched[i]=matched[j]=1;
			mcnt+=2;
		}
	}
}
void go(int i)
{
	if(matched[i])return;
	for(int j=i+1;j<=n;j++)
	{
		ll p=n*(-a[i].FF-a[j].FF)+2*sumx;
		ll q=n*(a[i].SS+a[j].SS)-2*sumy;
//		cerr<<i<<","<<j<<" "<<p<<","<<q<<endl;
		if(q==0&&p!=0)continue;
		assert(!(q==0&&p==0));
		if(check(1,p,q))
		{
			ll g=__gcd(p,q);
			p/=g;
			q/=g;
			if(q<0)q=-q,p=-p;
			st.insert(MP(p,q));
		}
	}
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		getii(a[i].FF,a[i].SS);
		sumx+=a[i].FF;
		sumy+=a[i].SS;
	}
	for(int i=1;i<=n;i++)pre_go(i);
	if(n-mcnt<=2)
	{
		puts("-1");
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(matched[i])continue;
		go(i);
		if((++cnt)>=2)break;
	}
	if(check(0,1,1))st.insert(MP(1,0));
//	foreach(it,st)cerr<<it->FF<<","<<it->SS<<endl;
	cout<<st.size()<<endl;
	return 0;
}