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
int n,m,adj[25];
int dp[1<<22];
pair<int,int> pre[1<<22];
int main()
{
	getii(n,m);
	if(m==n*(n-1)/2)
	{
		puts("0");
		return 0;
	}
	for(int i=0;i<n;i++)adj[i]=1<<i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		x--;y--;
		adj[x]|=1<<y;
		adj[y]|=1<<x;
	}
	memset(dp,31,sizeof(dp));
	int mx=dp[0];
	for(int i=0;i<n;i++)dp[adj[i]]=1,pre[adj[i]]=MP(i,0);
	for(int i=0;i<(1<<22);i++)
	{
		int cur=dp[i];
		if(cur==mx)continue;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				if(dp[i]+1<dp[i|adj[j]])
				{
					dp[i|adj[j]]=dp[i]+1;
					pre[i|adj[j]]=MP(j,i);
				}
			}
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	int x=(1<<n)-1;
	vector<int>v;
	while(x)v.PB(pre[x].FF+1),x=pre[x].SS;
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
	return 0;
}