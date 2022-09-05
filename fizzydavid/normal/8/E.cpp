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
ll K;
bool f[55];
ll dp[55][3][3][3][3];
ll ndp[55][3][3][3][3];
int getnxt(int pst,int v0,int v1)
{
	if(pst!=1)return pst;
	else
	{
		if(v0<v1)return 0;
		if(v0==v1)return 1;
		if(v0>v1)return 2;
	}
}
int getnxt2(int pst,int v0,int v1)
{
	if(v0==v1)return pst;
	else
	{
		if(v0<v1)return 0;
		if(v0>v1)return 2;
	}
}

ll solve()
{
	memset(dp,0,sizeof(dp));
	dp[0][1][1][1][1]=1;
	int lst=0;
	for(int i=0;i<(n+1)/2;i++)
	{
//		cerr<<"i="<<i<<endl;
		lst=i+1;
		memset(ndp,0,sizeof(ndp));
		for(int t0=0;t0<3;t0++)
		{
			for(int t1=0;t1<3;t1++)
			{
				for(int t2=0;t2<3;t2++)
				{
					for(int t3=0;t3<3;t3++)
					{
						ll &cur=dp[i][t0][t1][t2][t3];
						if(!cur)continue;
//						cerr<<i<<" "<<t0<<","<<t1<<","<<t2<<","<<t3<<":"<<cur<<endl;
						for(int v0=0;v0<2;v0++)
						{
							for(int v1=0;v1<2;v1++)
							{
								if(i+i>=n-1&&v0!=v1)continue;
								if(i==0&&v0!=0)continue;
								int nt0=getnxt(t0,v0,f[i]);
								int nt1=getnxt2(t1,v1,f[n-i-1]);
								int nt2=getnxt(t2,v1,v0);
								int nt3=getnxt(t3,1-v1,v0);
								ndp[i+1][nt0][nt1][nt2][nt3]+=dp[i][t0][t1][t2][t3];
							}
						}
					}
				}
			}
		}
		swap(dp,ndp); 
	}
	ll ans=0;
	for(int t0=0;t0<=1;t0++)
	{
		for(int t1=0;t1<=2-t0*1;t1++)
		{
			for(int t2=1;t2<=2;t2++)
			{
				for(int t3=1;t3<=2;t3++)
				{
					ans+=dp[lst][t0][t1][t2][t3];
				}
			}
		}
	}
	return ans;
}
int main()
{
	cin>>n>>K;K++;
	for(int i=0;i<n;i++)f[i]=1;
	for(int i=0;i<n;i++)
	{
		f[i]=0;
		ll cur=solve();
		if(cur<K)f[i]=1;
	}
//	for(int i=0;i<n;i++)putchar('0'+f[i]);
	
	ll cur=solve();
	if(K!=cur)
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<n;i++)putchar('0'+f[i]);
	return 0;
}