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
vector<int> con[200111];
int fa[200111],omsk[200111],msk[200111],sz[200111];

ll ans[200111];
bool ban[200111];
pair<int,int> pdfs(int x,int pre,int tot)
{
	pair<int,int> ret=MP(mod,0);
	sz[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(ban[u]||u==pre)continue;
		ret=min(ret,pdfs(u,x,tot));
		sz[x]+=sz[u];
	}
	if(sz[x]*2>=tot)ret=min(ret,MP(sz[x],x));
	return ret;
}
ll cans[200111];
int arr[200111],an;
void dfs(int x,int pre=-1)
{
	sz[x]=1;
	cans[x]=0;
	arr[an++]=x;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre||ban[u])continue;
		fa[u]=x;
		msk[u]=msk[x]^omsk[u];
		dfs(u,x);
		sz[x]+=sz[u];
	}
}
int cnt[1<<20];
void dfs2(int x,int pre,int coef)//change
{
//	cerr<<"change:"<<x<<" "<<coef<<endl;
	cnt[msk[x]]+=coef;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre||ban[u])continue;
		dfs2(u,x,coef);
	}
}
int tmp;
void dfs3(int x,int pre=-1)//query
{
//	cerr<<"query:"<<x<<endl;
	cans[x]+=cnt[msk[x]^tmp];
	for(int i=0;i<20;i++)cans[x]+=cnt[msk[x]^(1<<i)^tmp];
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre||ban[u])continue;
		dfs3(u,x);
	}
}
void sumup(int x,int pre=-1)
{
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre||ban[u])continue;
		sumup(u,x);
		cans[x]+=cans[u];
	}
}
void solve(int x)
{
//	cerr<<"solve:"<<x<<endl;
	an=0;
	msk[x]=omsk[x];
	dfs(x);
//	for(int i=1;i<=n;i++)cerr<<msk[i]<<" ";cerr<<endl;
	tmp=msk[x];
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(ban[u])continue;
		dfs2(u,x,1);
	}
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(ban[u])continue;
		dfs2(u,x,-1);
		dfs3(u,x);
		dfs2(u,x,1);
	}
//	for(int i=1;i<=n;i++)cerr<<cans[i]<<" ";cerr<<endl;
	
	sumup(x);
	cans[x]/=2;
//	for(int i=1;i<=n;i++)cerr<<cans[i]<<" ";cerr<<endl;
	for(int i=0;i<an;i++)
	{
		ans[arr[i]]+=cans[arr[i]];
	}
	for(int i=0;i<an;i++)
	{
		cans[arr[i]]=msk[arr[i]]==0;
		for(int j=0;j<20;j++)cans[arr[i]]|=msk[arr[i]]==(1<<j);
	}
	sumup(x);
//	for(int i=1;i<=n;i++)cerr<<cans[i]<<" ";cerr<<endl;
	for(int i=0;i<an;i++)
	{
		ans[arr[i]]+=cans[arr[i]];
	}
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(ban[u])continue;
		dfs2(u,x,-1);
	}
	
	ban[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(ban[u])continue;
		solve(pdfs(u,x,sz[u]).SS);
	}
}
int main()
{
	geti(n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	for(int i=1;i<=n;i++)
	{
		char c=getreal();
		omsk[i]=1<<(c-'a');
	}
	solve(pdfs(1,-1,n).SS);
	for(int i=1;i<=n;i++)puti(ans[i]);
	return 0;
}