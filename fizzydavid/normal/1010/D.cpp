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
int go[maxn][2],fa[maxn];
bool v[maxn],ans[maxn][2];
char t[maxn];
bool calc(char c,bool x,bool y)
{
	if(c=='N')return !x;
	if(c=='A')return x&y;
	if(c=='O')return x|y;
	if(c=='X')return x^y;
	assert(false); 
}
void dfs(int x)
{
	if(t[x]=='I')return;
	for(int i=0;i<2;i++)
	{
		if(go[x][i])
		{
			dfs(go[x][i]);
		}
	}
	v[x]=calc(t[x],v[go[x][0]],v[go[x][1]]);
}
void dfs2(int x)
{
	if(x==1)
	{
		ans[x][0]=0;
		ans[x][1]=1;
	}
	else
	{
		for(int i=0;i<2;i++)
		{
			int f=fa[x];
			if(go[f][0]==x)ans[x][i]=ans[f][calc(t[f],i,v[go[f][1]])];
			else ans[x][i]=ans[f][calc(t[f],v[go[f][0]],i)];
		}
	}
	for(int i=0;i<2;i++)
	{
		if(go[x][i])
		{
			fa[go[x][i]]=x;
			dfs2(go[x][i]);
		}
	}
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		char c=getreal();
		
		t[i]=c;
		if(c=='I')
		{
			int x;
			geti(x);
			v[i]=x;
		}
		else if(c=='N')
		{
			int x;
			geti(x);
			go[i][0]=x;
		}
		else
		{
			int x,y;
			getii(x,y);
			go[i][0]=x;go[i][1]=y;
		}
	}
	dfs(1);
	dfs2(1);
	for(int i=1;i<=n;i++)
	{
		if(t[i]=='I')
		{
			putchar('0'+ans[i][v[i]^1]);
		}
	}
	return 0;
}