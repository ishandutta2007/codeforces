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
int p[200111],sz[200111];
vector<int> son[200111];
vector<int> con[200111],v;
void dfs(int x,int pre=-1)
{
	sz[x]=1;
	for(int i=0;i<son[x].size();i++)
	{
		int u=son[x][i];
		dfs(u,x);
		sz[x]+=sz[u];
	}
	if(pre!=-1)
	{
		if(sz[x]&1)
		{
			con[pre].PB(x);
		}
		else
		{
			con[x].PB(pre);
		}
	}
}
bool vis[200111];
void dfs2(int x)
{
	vis[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(!vis[u])dfs2(u);
	}
	v.PB(x);
}
int main()
{
	int rt;
	geti(n);
	for(int i=1;i<=n;i++)
	{
		geti(p[i]);
		if(p[i]==0)rt=i;
		son[p[i]].PB(i);
	}
	dfs(rt);
	if(sz[rt]%2==0)
	{
		puts("NO");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs2(i);
		}
	}
	puts("YES");
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++)putsi(v[i]);
	return 0;
}