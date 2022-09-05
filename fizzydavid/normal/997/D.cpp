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
const int mod=998244353;
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
int K;
void upd(int &x,int v){x=x+v>=mod?x+v-mod:x+v;}
struct Tree
{
	int n;
	vector<int> con[4011];
	int fa[4011];
	int ANS[80];
	int dp[80][4011];
	int dpd[80][4011],dpu[80][4011],dps[80][4011];
	void adde(int x,int y){con[x].PB(y);con[y].PB(x);}
	void dfs(int x)
	{
		for(int i=0;i<con[x].size();i++)
		{
			int u=con[x][i];
			if(u==fa[x])continue;
			fa[u]=x;
			dfs(u);
		}
	}
	void solve()
	{
		dfs(1);
		memset(ANS,0,sizeof(ANS));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)dp[0][i]=1,dpd[0][i]=1,dpu[0][i]=i!=1,dps[0][i]=con[i].size();
		for(int ti=1;ti<=K;ti++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int k=0;k<=ti-2;k++)
				{
					upd(dp[ti][i],1ll*dps[k][i]*dp[ti-2-k][i]%mod);
					upd(dpd[ti][i],1ll*(dps[k][i]-dpu[k][i]+mod)*dpd[ti-2-k][i]%mod);
					if(i>1)upd(dpu[ti][i],1ll*(dps[k][fa[i]]-dpd[k][i]+mod)*dpu[ti-2-k][i]%mod);
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<con[i].size();j++)
				{
					int u=con[i][j];
					if(u==fa[i])upd(dps[ti][i],dpu[ti][i]);
					else upd(dps[ti][i],dpd[ti][u]);
				}
			}
		}
		for(int ti=0;ti<=K;ti++)for(int i=1;i<=n;i++)upd(ANS[ti],dp[ti][i]);
	}
}T1,T2;
ll fac[10000],ifac[10000];
int main()
{
	fac[0]=1;
	for(int i=1;i<10000;i++)fac[i]=fac[i-1]*i%mod;
	ifac[9999]=qpow(fac[9999],mod-2);
	for(int i=9998;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	int n,m;
	getiii(n,m,K);
	T1.n=n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		T1.adde(x,y);
	}
	T1.solve();
	T2.n=m;
	for(int i=1;i<m;i++)
	{
		int x,y;
		getii(x,y);
		T2.adde(x,y);
	}
	T2.solve();
	int ans=0;
	for(int i=0;i<=K;i++)
	{
		upd(ans,1ll*T1.ANS[i]*T2.ANS[K-i]%mod*fac[K]%mod*ifac[i]%mod*ifac[K-i]%mod);
	}
	cout<<ans<<endl;
	return 0;
}