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
int ans[10][711];
char s[711];
int n;
int dp[711][711][2];
void upd(int &x,int v){x=x+v>=mod?x+v-mod:x+v;}
void solve(int lim)
{
//	cerr<<"solve:"<<lim<<endl;
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int t=0;t<2;t++)
			{
				int &cur=dp[i][j][t];
				if(!cur)continue;
				for(int v=0;v<10;v++)
				{
					if(!t&&v>s[i]-'0')continue;
					upd(dp[i+1][j+(v<=lim)][t|(v<s[i]-'0')],cur);
				}
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		upd(ans[lim][i],dp[n][i][0]);
		upd(ans[lim][i],dp[n][i][1]);
//		cerr<<ans[lim][i]<<" ";
	}
//	cerr<<endl;
	for(int i=n;i>=0;i--)upd(ans[lim][i],ans[lim][i+1]);
//	for(int i=0;i<=n;i++)cerr<<ans[lim][i]<<" ";cerr<<endl;
}
ll pw[711];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*10%mod;
	for(int i=0;i<10;i++)solve(i);
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		for(int v=1;v<10;v++)
		{
			ll cnt=(ans[v][n-i]-ans[v-1][n-i]+mod)%mod;
			sum+=pw[i]*v%mod*cnt%mod;
		}
	}
	sum=(sum%mod+mod)%mod;
	cout<<sum<<endl;
	return 0;
}