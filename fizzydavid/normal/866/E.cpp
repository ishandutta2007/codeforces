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
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
char s[15];
int htod(char c){return c<='9'?c-'0':c-'a'+10;}
char dtoh(int x){return x<10?'0'+x:'a'+x-10;}
int n;
int d[15];
int sumd[1<<14];
int lowbit[1<<14];
ll dp[1<<14];
int tag[1<<13];
ll ans=8e18;
void solve(int T)
{
//	cerr<<"solve:"<<T<<endl;
//	for(int i=0;i<n;i++)cerr<<d[i]<<" ";cerr<<endl;
	sumd[0]=d[n-1];
	for(int i=1;i<(1<<n-1);i++)sumd[i]=sumd[i&(~(1<<lowbit[i]))]+d[lowbit[i]];
	dp[0]=0,tag[0]=T;
	if(sumd[0]<0||sumd[0]>=16)return;
	for(int i=1;i<(1<<n-1);i++)
	{
		if(sumd[i]<0||sumd[i]>=16)continue;
		dp[i]=8e18;tag[i]=T;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				int ni=i&(~(1<<j));
				if(tag[ni]==T)
				{
					dp[i]=min(dp[i],dp[ni]+((1ll*sumd[ni])<<(j<<2)));
				}
			}
		}
	}
	if(tag[(1<<n-1)-1]==T)ans=min(ans,dp[(1<<n-1)-1]);
}
int tot;
void dfs(int x,int cnt)
{
	if(x==n-1)
	{
		if(cnt==0)solve(++tot);
		return;
	}
	dfs(x+1,cnt);
	if(cnt)
	{
		d[x]-=16;
		d[x+1]++;
		dfs(x+1,cnt-1);
		d[x]+=16;
		d[x+1]--;
	}
}
int main()
{
	for(int i=1;i<(1<<14);i++)lowbit[i]=__builtin_ctz(i&(-i));
	scanf("%s",s);
	n=strlen(s);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cnt+=htod(s[i]);
	}
	if(cnt%15!=0)
	{
		puts("NO");
		return 0;
	}
	for(int i=0;i<n;i++)d[i]=htod(s[n-i-1]);
	cnt/=15;
	dfs(0,cnt);
	if(ans>7e18)puts("NO");
	else
	{
		for(int i=n-1;i>=0;i--)putchar(dtoh((ans>>(i<<2))&15));
		puts("");
	}
	return 0;
}