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
ll S,A,B,dp[1011],ndp[1011];
ll iA2,iA,iB2,iB;
ll pwa[1011],pwb[1011];
int n;
ll qpow(ll x,ll k){return k==0?1:qpow(x*x%mod,k>>1)*(k&1?x:1)%mod;}
int main()
{
	cin>>n>>A>>B;
	S=(A+B)%mod;
	A=A*qpow(S,mod-2)%mod;
	B=B*qpow(S,mod-2)%mod;
	iA=qpow((1-A+mod)%mod,mod-2);
	iA2=iA*iA%mod;
	iB=qpow((1-B+mod)%mod,mod-2);
	iB2=iB*iB%mod;
	pwa[0]=1;
	for(int i=1;i<1005;i++)pwa[i]=pwa[i-1]*A%mod;
	pwb[0]=1;
	for(int i=1;i<1005;i++)pwb[i]=pwb[i-1]*B%mod;
	
	dp[0]=1;
	ll ans=0;
	for(int i=1;i<n;i++)
	{
		memset(ndp,0,sizeof(ndp));
		for(int j=0;j<n;j++)
		{
			ll cur=dp[j];
			if(!cur)continue;
//			cerr<<i<<" "<<j<<" "<<cur<<endl;
			int k=0;
			while(true)
			{
				if(j+k*i<n)
				{
					ndp[j+k*i]=(ndp[j+k*i]+pwb[k]*A%mod*cur%mod)%mod;
				}
				else
				{
					ans=(ans+pwb[k]*A%mod*cur%mod*(j+1ll*k*i)%mod)%mod;
/*					ll t=pwb[k]*A%mod*cur%mod;
					ll t2=((iB2-iB+mod)*i%mod+iB*(j+1ll*k*i%mod))%mod;
					ans+=t*t2%mod;
					cerr<<"ans="<<ans<<endl;*/
					break;
				}
				k++;
			}
		}
		swap(dp,ndp);
	}
//	ans+=B*pwa[n]%mod*((iA2-iA+mod)%mod+n*iA%mod)%mod;
	for(int i=0;i<n;i++)ans+=dp[i]*B%mod*((iA2-iA+mod)%mod+(n+i)*iA%mod)%mod*A%mod;
	ans=(ans%mod+mod)%mod;
	ans=ans*qpow(A,mod-2)%mod;
	cout<<ans<<endl;
	return 0;
}