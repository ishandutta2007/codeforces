// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
const int S=1414;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
int n;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int t[N],pos;
int Fa[N];
int id[N];
void dfs(int x,int fa)
{
	Fa[x]=fa;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v!=fa)
		{
			dfs(v,x);
		}
	}
	t[++pos]=x;
	id[x]=pos;
}
int dp[N];
int Dp(int k)
{
	int ans=0;
	for(int p=1;p<=n;++p)
	{
		int i=t[p];
		int m1=0,m2=0;
		for(int _=front[i];_;_=c[_].nxt)
		{
			int v=c[_].v;
			if(v!=Fa[i])
			{
				if(dp[v]>m1)
				{
					m2=m1;
					m1=dp[v];
				}
				else if(dp[v]>m2) m2=dp[v];
			}
		}
		if(m1+m2+1>=k) ++ans,dp[i]=0;
		else dp[i]=m1+1;
	}
	return ans;
}
int main()
{
	read(n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		addedge(x,y),addedge(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n&&i<=S;++i)
	{
		printf("%d\n",Dp(i));
	}
	int cur=S+1;
	while(cur<=n)
	{
		int ans=Dp(cur);
		int l=cur,r=n;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(Dp(mid)==ans) l=mid;
			else r=mid-1;
		}
		for(int i=cur;i<=l;++i) printf("%d\n",ans);
		cur=l+1;
	}
	return 0;
}