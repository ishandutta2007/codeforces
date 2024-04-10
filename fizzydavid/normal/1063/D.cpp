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
ll solve(ll n,ll K,ll L,ll lst,ll a2l,ll a2r)
{
	if(a2l>a2r)return -1;
//	cerr<<"solve:"<<n<<" "<<K<<" "<<L<<" "<<lst<<" "<<a2l<<" "<<a2r<<endl;
	ll nL=n+a2l,nR=n+n-(L-a2r);
	ll ret=-1;
	for(ll nl=nL;nl<=nR;)
	{
		ll k=K/nl,nr;
		if(k==0)nr=nR;
		else nr=min(nR,K/k);
		if(L==n)
		{
			if(k==0)return ret;
			else k--;
		}
//		cerr<<nl<<" "<<nr<<" "<<k<<endl;
		ll cL=nl-n,cR=nr-n;
		ll C=K-k*n-L;
//		cerr<<"C="<<C<<endl;
		{
			//upper_bound
			ll l=cL,r=cR;
			while(l<=r)
			{
				ll mid=l+r>>1;
				ll mx=mid*k+min(mid,a2r);
				if(C<=mx)r=mid-1;else l=mid+1;
			}
			cL=l;
		}
		{
			//lower_bound
			ll l=cL,r=cR;
			while(l<=r)
			{
				ll mid=l+r>>1;
				ll mn=mid*k+max(mid-(n-L),a2l);
				if(mn<=C)l=mid+1;else r=mid-1;
			}
			cR=r;
		}
//		cerr<<"cL="<<cL<<" cR="<<cR<<endl;
		if(cL<=cR)ret=max(ret,cR);
		nl=nr+1;
	}
	return ret;
}
int main()
{
	ll n,K,L,tl,tr;
	cin>>n>>tl>>tr>>K;
	if(tr>=tl)L=tr-tl+1;else L=tr+n-tl+1;
	ll ans1=solve(n,K,L,1,0,L-1);
	ll ans2=solve(n,K,L,2,1,L);
	ll ans3=solve(n,K+1,L,2,1,L);
	ll ans=max(max(ans1,ans2),ans3);
	cout<<ans<<endl;
	return 0;
}