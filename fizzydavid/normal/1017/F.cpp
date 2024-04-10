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
int N,A,B,C,D;
const int magic=10000111;
const int sn=20011;
bool np[magic];
int pr[sn],pn;
typedef unsigned int ui;
ui calcp(int p)
{
	ui ans=0,x=N/p;
	while(x)ans+=x,x/=p;
	return ans;
}
ui calcf(ui x)
{
	ui ret=A;
	ret=ret*x+B;
	ret=ret*x+C;
	ret=ret*x+D;
	return ret;
}
void prework()
{
	np[1]=1;pn=0;
	for(int i=2;i<=sn;i++)
	{
		if(np[i])continue;
		pr[pn++]=i;
		for(int j=i+i;j<=sn;j+=i)np[j]=1;
	}
//	cerr<<"pn="<<pn<<endl;
}
ui solve(int L,int R)
{
//	cerr<<"solve:"<<L<<" "<<R<<endl;
	int n=R-L;
	for(int i=0;i<=n;i++)np[i]=0;
	for(int i=0;i<pn;i++)
	{
		int st=pr[i]-L%pr[i];
		if(st==pr[i])st=0;
		for(int j=st;j<=n;j+=pr[i])np[j]=1;
	}
	if(L==1)
	{
		for(int i=0;i<pn;i++)np[pr[i]-L]=0;
	}
//	for(int i=0;i<=n;i++)cerr<<np[i];cerr<<endl;
	ui ans=0;
	for(int i=max(2,L);i<=R;i++)
	{
		if(!np[i-L])
		{
			ans+=calcp(i)*calcf(i);
		}
	}
	return ans;
}
int main()
{
	prework();
	cin>>N>>A>>B>>C>>D;
	ui ans=0;
	for(int i=1;i<=N;i+=magic)ans+=solve(i,min(N,i+magic));
	cout<<ans<<endl;
	return 0;
}