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
int n,m;
int ANS[100111];
vector<int> con[100111];
int RT;
int lv[100111];
int mxlv[100111],son[100111];
void pdfs(int x,int pre=-1)
{
	mxlv[x]=lv[x];son[x]=0;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		lv[u]=lv[x]+1;
		pdfs(u,x);
		if(mxlv[u]>mxlv[x])
		{
			mxlv[x]=mxlv[u];
			son[x]=u;
		}
	}
}
int a[100111],an;
bool f[100111];
void dfs(int x,int g,int pre=-1)
{
	if(!f[g])
	{
		f[g]=1;
		a[an++]=mxlv[x]-lv[x]+1;
	}
	if(son[x])
	{
		dfs(son[x],g,x);
	}
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre||u==son[x])continue;
		dfs(u,u,x);
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
	ANS[1]=1;
	if(n==1)
	{
		puts("1");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(con[i].size()==1)
		{
			RT=i;
			break;
		}
	}
	lv[RT]=1;
	pdfs(RT);
	for(int i=1;i<=n;i++)
	{
		if(lv[i]>lv[RT])
		{
			RT=i;
		}
	}
//	cerr<<"RT="<<RT<<endl;
	lv[RT]=1;
	pdfs(RT);
	dfs(RT,RT);
	sort(a,a+an);
	reverse(a,a+an);
	a[0]--;
//	for(int i=0;i<an;i++)cerr<<a[i]<<" ";cerr<<endl;
	for(int i=2;i<=n;i++)
	{
		ANS[i]=ANS[i-1]+a[i-2];
	}
	for(int i=1;i<=n;i++)puti(ANS[i]);
	return 0;
}