//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
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
const int maxn=2011;
const int maxm=200111;
int n,m,k,D;
int head[maxn],nxt[maxm],to[maxm],tot=1;
int deg[maxn];
void adde(int x,int y)
{
	nxt[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
	deg[x]++;
}
int ans[maxm];
int col[maxn][maxn];
int it[maxn];
int getc(int x){while(col[x][it[x]])it[x]++;assert(it[x]<D);return it[x];} 
bool vis[maxn];
void sete(int x,int e,int c)
{
	col[x][c]=e;
	col[to[e]][c]=e^1;
	ans[e>>1]=c;
}
void aug(int x,int e,int c,int cp)
{
	int y=to[e];
	if(col[y][c])aug(y,col[y][c],cp,c);
	else col[y][cp]=0,it[y]=0;
	sete(x,e,c);
}
int main()
{
	getiii(n,m,k);
	for(int i=1;i<=k;i++)
	{
		int x,y;
		getii(x,y);
		adde(x,y+n);
		adde(y+n,x);
	}
	for(int i=1;i<=n+m;i++)D=max(D,deg[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=head[i];j;j=nxt[j])
		{
			int c=getc(i);
			int y=to[j];
			if(col[y][c])aug(y,col[y][c],getc(y),c);
			sete(i,j,c);
			it[i]=it[y]=0;
		}
	}
	putsi(D);
	for(int i=1;i<=k;i++)puti(ans[i]+1);
	return 0;
}