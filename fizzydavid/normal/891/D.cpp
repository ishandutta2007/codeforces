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
int n,sz[500111];
struct state//first bit - number of 1  second bit - number of key
{
	int a[4];
	void init(){memset(a,0,sizeof(a));a[0]=1;}
	state(){init();}
	state merge(const state &t)
	{
		state ret;
		ret.a[0]=a[0]*t.a[0];
		ret.a[1]=a[1]*t.a[0]+a[0]*t.a[1];
		ret.a[2]=a[2]*t.a[0]+a[0]*t.a[2];
		ret.a[3]=a[0]*t.a[3]+a[1]*t.a[2]+a[2]*t.a[1]+a[3]*t.a[0];
		return ret;
	}
	state occ()
	{
		state ret;
		ret.a[0]=a[1];
		ret.a[1]=a[0];
		ret.a[2]=a[0]+a[3];
		ret.a[3]=a[2];
		return ret;
	}
};
vector<int> con[500111];
state dp[500111],dpu[500111];
void dfs1(int x,int pre=-1)
{
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)
		{
			swap(con[x][i],con[x][con[x].size()-1]);
			con[x].resize(con[x].size()-1);
			i--;
			continue;
		}
		dfs1(u,x);
		sz[x]+=sz[u];
		dp[x]=dp[x].merge(dp[u]);
	}
	sz[x]++;
	dp[x]=dp[x].occ();
}
ll ans;
state pre[500111],suf[500111];
void dfs2(int x)
{
	if(x==1)pre[0].init();else pre[0]=dpu[x];
	suf[con[x].size()+1].init();
	for(int i=1;i<=con[x].size();i++)pre[i]=pre[i-1].merge(dp[con[x][i-1]]);
	for(int i=con[x].size();i>=1;i--)suf[i]=suf[i+1].merge(dp[con[x][i-1]]);
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		dpu[u]=pre[i].merge(suf[i+2]);
		dpu[u]=dpu[u].occ();
	}
	if(x!=1)
	{
		if(sz[x]&1)ans+=1ll*dp[x].a[2]*dpu[x].a[2];
		else ans+=1ll*dp[x].a[0]*dpu[x].a[0]*sz[x]*(n-sz[x]);
	}
	for(int i=0;i<con[x].size();i++)dfs2(con[x][i]);
}
int main()
{
	geti(n);
	if(n&1)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	dfs1(1);
	dfs2(1);
	cout<<ans<<endl;
	return 0;
}