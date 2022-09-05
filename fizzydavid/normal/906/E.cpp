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
const int maxn=1000111;
int n;
char s[maxn],t[500111];
int tot,go[maxn][26],len[maxn],par[maxn],slink[maxn],diff[maxn];
pair<int,int> gpl[maxn],dp[maxn];
int append(int n,int p,char c)
{
	int ic=c-'a';
	while(s[n-len[p]-1]!=c)p=par[p];
	if(!go[p][ic])
	{
		int q=++tot;
		len[q]=len[p]+2;
		int t=par[p];
		while(s[n-len[t]-1]!=c)t=par[t];
		par[q]=go[t][ic];
		go[p][ic]=q;
		diff[q]=len[q]-len[par[q]];
		slink[q]=diff[q]==diff[par[q]]?slink[par[q]]:par[q];
	}
	return go[p][ic];
}
int main()
{
	par[0]=tot=1;len[1]=-1;
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%s",t+1);
	for(int i=n;i>=1;i--)s[(i<<1)-1]=s[i];
	for(int i=1;i<=n;i++)s[(i<<1)]=t[i];
	n=n<<1;
	int st=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=MP(mod,-1);
		st=append(i,st,s[i]);
		for(int p=st;p;p=slink[p])
		{
			int lst=i-len[slink[p]]-diff[p];
			gpl[p]=MP(dp[lst].FF,lst);
			if(diff[par[p]]==diff[p])gpl[p]=min(gpl[p],gpl[par[p]]);
			if(!(i&1))dp[i]=min(dp[i],MP(gpl[p].FF+1,gpl[p].SS));
		}
		if(!(i&1)&&s[i]==s[i-1])dp[i]=min(dp[i],MP(dp[i-2].FF,i-2));
	}
	if(dp[n].FF>n)puts("-1");
	else
	{
		putsi(dp[n].FF);
		int p=n;
		while(p)
		{
			if(p-dp[p].SS!=2)putsii((dp[p].SS+2)>>1,(p+1)>>1);
			p=dp[p].SS;
		}
	}
	return 0;
}