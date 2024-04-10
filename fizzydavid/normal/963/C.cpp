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

int n;
vector<ll> vx,vy;
int getidx(ll x){return lower_bound(vx.begin(),vx.end(),x)-vx.begin()+1;}
int getidy(ll y){return lower_bound(vy.begin(),vy.end(),y)-vy.begin()+1;}
ll px[200111],py[200111],pw[200111];
int xn,yn;
map<pair<int,int>,ll> mp;
ll xk[200111],yk[200111];
bool check(ll a0,ll a1,ll b0,ll b1)
{
	if(fabs(1.0*a0*b1-1.0*a1*b0)>1e9)return false;
	return a0*b1-a1*b0==0;
}
void printans(ll x)
{
	int ans=0;
	for(ll i=1;i<=x;i++)
	{
		i=x/(x/i);
		if(x%i==0)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return;
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		getiii(px[i],py[i],pw[i]);
		vx.PB(px[i]);
		vy.PB(py[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	sort(vy.begin(),vy.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
	int xn=vx.size(),yn=vy.size();
	for(int i=1;i<=n;i++)
	{
		int x=getidx(px[i]);
		int y=getidy(py[i]);
		mp[MP(x,y)]=pw[i];
	}
	if(1ll*xn*yn!=n)
	{
		puts("0");
		return 0;
	}
	ll g;
	g=0;
	for(int i=1;i<=xn;i++)xk[i]=mp[MP(i,1)],g=__gcd(g,xk[i]);
	for(int i=1;i<=xn;i++)xk[i]/=g;
	g=0;
	for(int i=1;i<=yn;i++)yk[i]=mp[MP(1,i)],g=__gcd(g,yk[i]);
	for(int i=1;i<=yn;i++)yk[i]/=g;
//	for(int i=1;i<=xn;i++)cerr<<xk[i]<<" ";cerr<<endl;
//	for(int i=1;i<=yn;i++)cerr<<yk[i]<<" ";cerr<<endl;
	
	for(int i=1;i<=xn;i++)
	{
		for(int j=1;j<=yn;j++)
		{
			if(!check(xk[1],mp[MP(1,j)],xk[i],mp[MP(i,j)]))
			{
				puts("0");
				return 0;
			}
			if(!check(yk[1],mp[MP(i,1)],yk[j],mp[MP(i,j)]))
			{
				puts("0");
				return 0;
			}
			
		}
	}
	if(1.0*xk[1]*yk[1]>1e18||mp[MP(1,1)]%(xk[1]*yk[1])!=0)
	{
		puts("0");
		return 0;
	}
	printans(mp[MP(1,1)]/xk[1]/yk[1]);
	return 0;
}