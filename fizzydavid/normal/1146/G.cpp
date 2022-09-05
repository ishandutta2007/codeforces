//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod = 1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it, len;
	fastio() {it=len=0;}
	inline char get()
	{
		if (it<len) return s[it++]; it=0;
		len=fread(s, 1, 100000, stdin);
		if (len==0) return EOF; else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while (c==' '||c=='\n') c=get();
		if (it>0) it--;
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
	ll r=0; bool ng=0; char c; c=_buff.get();
	while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
	if (c=='-') ng=1, c=_buff.get();
	while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
	return ng?-r:r;
}
template <class T> inline void putnum(T x)
{
	if (x<0) putchar('-'), x=-x;
	register short a[20]={}, sz=0;
	while (x) a[sz++]=x%10, x/=10;
	if(sz==0) putchar('0');
	for (int i=sz-1; i>=0; i--) putchar('0'+a[i]);
}
inline char getreal() {char c=_buff.get(); while (c<=32) c=_buff.get(); return c;}
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
namespace Flow
{
	const int maxn=100111,maxe=1000111*2;
	int head[maxn],to[maxe],nxt[maxe],cap[maxe],tot=1;
	void init()
	{
		memset(head,0,sizeof(head));tot=1;
	}
	void adde(int x,int y,int c)
	{
//		cerr<<"adde:"<<x<<","<<y<<" "<<c<<endl;
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
		cap[tot]=c;
		nxt[++tot]=head[y];
		head[y]=tot;
		to[tot]=x;
		cap[tot]=0;
	}
	void adde_2(int x,int y,int c,int c2)
	{
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
		cap[tot]=c;
		nxt[++tot]=head[y];
		head[y]=tot;
		to[tot]=x;
		cap[tot]=c2;
	}
	int lv[maxn],q[maxn],qn;
	void bfs(int S,int N)
	{
		for(int i=0;i<=N;i++)lv[i]=-1;
		qn=0;
		q[qn++]=S;lv[S]=0;
		for(int i=0;i<qn;i++)
		{
			int u=q[i];
			for(int j=head[u];j;j=nxt[j])
			{
				if(cap[j]&&lv[to[j]]==-1)
				{
					lv[to[j]]=lv[u]+1;
					q[qn++]=to[j];
				}
			}
		}
	}
	int it[maxn];
	int dfs(int x,int T,int f)
	{
		if(x==T)return f;
		int of=f;
		for(int &i=it[x];i&&f;i=nxt[i])
		{
			int u=to[i];
			if(cap[i]&&lv[u]==lv[x]+1)
			{
				int d=dfs(u,T,min(f,cap[i]));
				if(d)
				{
					cap[i]-=d;
					cap[i^1]+=d;
					f-=d;
					if(f==0)return of;
				}
			}
		}
		return of-f;
	}
	int max_flow(int S,int T,int N=-1)
	{
		if(N==-1)N=maxn-1;
		int ans=0;
		while(true)
		{
			bfs(S,N);
			if(lv[T]==-1)return ans;
			for(int i=0;i<=N;i++)it[i]=head[i];
			ans+=dfs(S,T,2147483647);
		}
	}
};
int n, h, m, S, T;
void add(int x, int y)
{
	Flow::adde(x, y, 1e9);
}
int main()
{
	getiii(n, h, m);
	S = n*h+m+1, T = S+1;
	Flow::init();
	int ans = 0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=h; j++)
		{
			int c = j*2-1;
			ans += c;
			Flow::adde(S, (i-1)*h+j, c);
			if (j>1) add((i-1)*h+j, (i-1)*h+j-1);
		}
	}
	for (int i=1; i<=m; i++)
	{
		int l, r, c, w;
		getii(l, r);
		getii(c, w);
		if (c<h)
		{
			int cur = n*h+i;
			for (int j=l; j<=r; j++)
			{
				add((j-1)*h+c+1, cur);
			}
			Flow::adde(cur, T, w);
		}
	}
	cout<<ans-Flow::max_flow(S, T, T)<<endl;
	return 0;
}