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
ll L;
ll a[400111],b[400111];
pair<int,int> pp[400111];
int cnt[400111];
bool check(ll x)
{
	for(int i=0;i<n;i++)
	{
		ll l=b[i]-x;
		ll r=b[i]+x;
		if(l<0)l+=L,r+=L;
		l=lower_bound(a,a+n+n,l)-a;
		r=lower_bound(a,a+n+n,r+1)-a-1;
		r=min(r,l+n-1);
		if(l>r)return false;
		pp[i]=MP(l,r);
	}
//	for(int i=0;i<n;i++)cerr<<pp[i].FF<<" "<<pp[i].SS<<endl;
	sort(pp,pp+n);
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;i++)
	{
		int l=pp[i].FF-i,r=pp[i].SS-i;
		if(l<0)l+=n,r+=n;
		assert(r<n+n);
		cnt[l]++;cnt[r+1]--;
	}
	for(int i=1;i<n+n;i++)
	{
		cnt[i]+=cnt[i-1];
	}
	for(int i=0;i<n;i++)if(cnt[i]+cnt[i+n]==n)return true;
	return false;
}
int main()
{
	getii(n,L);
	for(int i=0;i<n;i++)geti(a[i]);
	sort(a,a+n);
	for(int i=n;i<n+n;i++)a[i]=a[i-n]+L;
	for(int i=0;i<n;i++)geti(b[i]);
	sort(b,b+n);
//	for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl;
//	for(int i=0;i<n;i++)cerr<<b[i]<<" ";cerr<<endl;
//	check(8);
//	return 0;
	ll l=0,r=L/2;
	while(l<=r)
	{
		ll mid=l+r>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}