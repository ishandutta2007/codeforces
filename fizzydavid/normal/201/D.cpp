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
const ll hsmod=123123123123123;
const ll B=59;
int n,m;
int a[22];
int l[11];
vector<int> v[11];
char s[500111];
map<ll,int> mp;
int tot;
int getstr(bool F)
{
	scanf("%s",s);
	ll ret=0;
	for(int i=0;i<strlen(s);i++)
	{
		ret=(ret*B+s[i])%hsmod;
	}
	if(F==1)
	{
		int &id=mp[ret];
		if(id==0)id=++tot;
		return id;
	}
	else
	{
		if(mp.find(ret)==mp.end())return 0;
		else return mp[ret];
	}
}
int ta[22];
int id[500111];
bool check(int x)
{
	for(int _=1;_<=m;_++)
	{
		int i=id[_];
		int it=1;
		for(int j=0;j<v[i].size();j++)
		{
			if(it>x)it++;
			else if(v[i][j]==ta[it])it++;
			if(it>n)return true;
		}
	}
	return false;
}
int nxt[500111][16];
int dp[1<<15][110];
int cost[1<<15][15];
void upd(int &x,int v){x=min(x,v);}
int calc(int id)
{
	int sz=v[id].size();
	for(int i=0;i<=n;i++)nxt[sz][i]=sz;
	for(int i=sz-1;i>=0;i--)
	{
		for(int j=0;j<=n;j++)
		{
			nxt[i][j]=v[id][i]==j?i:nxt[i+1][j];
		}
	}
	memset(dp,31,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<=105;j++)
		{
			int &cur=dp[i][j];
			if(cur>sz)continue;
			for(int t=0;t<n;t++)
			{
				if((i>>t)&1)continue;
				upd(dp[i|(1<<t)][j+cost[i][t]],nxt[cur][a[t]]+1);
			}
		}
	}
	int mx=-1;
	for(int j=0;j<=105;j++)
	{
		if(dp[(1<<n)-1][j]<=sz)mx=max(mx,n*(n-1)/2-j+1);
	}
	return mx;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)a[i]=getstr(1);
	for(int i=0;i<(1<<n);i++)
	{
		int cnt=0;
		for(int j=n-1;j>=0;j--)
		{
			if((i>>j)&1)cnt++;
			else cost[i][j]=cnt;
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&l[i]);
		for(int j=1;j<=l[i];j++)
		{
			int x=getstr(0);
			if(x!=0)v[i].PB(x);
		}
		id[i]=i;
	}
	int mx=0,mxi=0;
	for(int i=1;i<=m;i++)
	{
		int cur=calc(i);
		if(cur>mx)
		{
			mx=cur;
			mxi=i;
		}
	}
	if(mxi==0)
	{
		puts("Brand new problem!");
		return 0;
	}
	cout<<mxi<<endl;
	cout<<"[:";
	while(mx--)cout<<'|';
	cout<<":]";
	return 0;
}