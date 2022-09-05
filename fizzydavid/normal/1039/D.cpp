//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
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
const int maxn=100111;
vector<int> con[maxn];
vector<int> son[maxn];
int dfn[maxn],dtot;
void dfs(int x,int pre=-1)
{
	dfn[x]=++dtot;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		dfs(u,x);
		son[dfn[x]].PB(dfn[u]);
	}
}
int getans(int k)
{
	static int len[maxn];
	int cnt=0;
	for(int i=n;i>=1;i--)
	{
		int mx=0,mx2=0;
		for(int j=0;j<son[i].size();j++)
		{
			int u=son[i][j];
			if(len[u]>mx)mx2=mx,mx=len[u];
			else mx2=max(mx2,len[u]);
		}
		if(mx+mx2+1>=k)
		{
			len[i]=0;
			cnt++;
		}
		else len[i]=mx+1;
	}
	return cnt;
}
int ANS[maxn];
void solve(int l,int r,int al,int ar)
{
//	cerr<<"solve:"<<l<<","<<r<<" "<<al<<" "<<ar<<endl;
	if(al==ar)
	{
		for(int i=l;i<=r;i++)ANS[i]=al;
		return;
	}
	if(r<=l+1)
	{
		ANS[l]=al;
		ANS[r]=ar;
		return;
	}
	int m=l+r>>1,am=getans(m);
	solve(l,m,al,am);
	solve(m,r,am,ar);
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
	dfs(1);
	solve(1,n,getans(1),getans(n));
	for(int i=1;i<=n;i++)putsi(ANS[i]);
	return 0;
}