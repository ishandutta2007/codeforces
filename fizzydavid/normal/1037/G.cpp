//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
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
const int maxn=100111;
const int maxa=27;
char s[maxn];
int n,q;
int go[maxn][maxa],rgo[maxn][maxa];
int dp[2][maxn][maxa],dps[2][maxn][maxa];
void solve(int dp[maxn][maxa],int dps[maxn][maxa])
{
	for(int i=0;i<maxa;i++)go[n+1][i]=n+1,rgo[0][i]=0;
	for(int i=n;i>=0;i--)
	{
		for(int j=0;j<maxa;j++)
		{
			if(s[i]=='a'+j)go[i][j]=i;
			else go[i][j]=go[i+1][j];
		}
	}
	for(int i=1;i<=n+1;i++)
	{
		for(int j=0;j<maxa;j++)
		{
			if(s[i]=='a'+j)rgo[i][j]=i;
			else rgo[i][j]=rgo[i-1][j];
		}
	}
	for(int i=n;i>=1;i--)
	{
		vector<pair<int,int> > v;
		for(int j=0;j<maxa;j++)v.PB(MP(go[i][j],j));
		sort(v.begin(),v.end());
		for(int t=0;t<maxa;t++)
		{
			int j=v[t].SS;
			int r=go[i][j]-1;
			bool f[32]={};
			dp[i][j]=dps[i][j]=0;
			for(int k=0;k<maxa;k++)
			{
				if(go[i][k]>r)continue;
				int p=rgo[r][k];
				int cur=dps[i][k]^dps[p][k]^dp[p+1][j];
				f[cur]=1;
			}
			while(f[dp[i][j]])dp[i][j]++;
			dps[i][j]=dp[i][j]^(go[i][j]+1<=n?dps[go[i][j]+1][j]:0);
		}
	}
}
int query(int l,int r)
{
	bool f[32]={};
	for(int i=0;i<maxa;i++)
	{
		if(go[l][i]>r)continue;
		int p=rgo[r][i];
		int cur=dps[0][l][i]^dps[0][p][i]^dp[1][n-r+1][i];
		f[cur]=1;
	}
	int ret=0;
	while(f[ret])ret++;
	return ret;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	s[0]=s[n+1]='a'+maxa-1;
	reverse(s+1,s+n+1);
	solve(dp[1],dps[1]);
	reverse(s+1,s+n+1);
	solve(dp[0],dps[0]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(query(l,r)>0)puts("Alice");else puts("Bob");
	}
	return 0;
}