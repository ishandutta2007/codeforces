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
int k,f[1011],nf[1011];
char s[1011];
int cnt1[1024];
int pw2[1024];
int dp[1024][1024][2];
void upd(int &x,int v){x=x+v>=mod?x+v-mod:x+v;}
int main()
{
	for(int i=1;i<1024;i++)cnt1[i]=cnt1[i-(i&(-i))]+1;
	pw2[0]=1;
	for(int i=1;i<1024;i++)pw2[i]=pw2[i-1]*2%mod;
	scanf("%s",s);
	scanf("%d",&k);
	if(k==0)
	{
		puts("1");
		return 0;
	}
	f[1]=1;
	for(int i=1;i<k;i++)
	{
		memset(nf,0,sizeof(nf));
		for(int j=2;j<=1000;j++)
		{
			nf[j]=f[cnt1[j]];
		}
		swap(f,nf);
	}
//	for(int i=1;i<=20;i++)cerr<<f[i];cerr<<endl;
	int n=strlen(s);
	dp[0][0][1]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int t=0;t<2;t++)
			{
				int &cur=dp[i][j][t];
				if(!cur)continue;
//				cerr<<i<<","<<j<<","<<t<<" "<<cur<<endl;
				for(int v=0;v<2;v++)
				{
					if(t==1&&v>s[i]-'0')continue;
					upd(dp[i+1][j+(v==1)][t&(v==s[i]-'0')],cur);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		if(f[i])
		{
			upd(ans,dp[n][i][0]);
			upd(ans,dp[n][i][1]);
		}
	}
	cout<<(ans-(k==1)+mod)%mod<<endl;
	return 0;
}