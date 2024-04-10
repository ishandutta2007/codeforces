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

const int N=5005;
struct edge{
	int v,nxt;
}c[N*40];
int front[N],edge_cnt;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int col[N];
bool vis[N];
std::vector<pi> v;
int c1,c2;
int tag[N],id;
void dfs(int x,int C)
{
	if(col[x]!=-1)
	{
		if(col[x]!=C)
		{
			printf("NO\n");
			exit(0);
		}
		return;
	}
	vis[x]=true;
	col[x]=C;
	tag[x]=id;
	if(C) ++c1;
	else ++c2;
	for(int i=front[x];i;i=c[i].nxt)
	{
		dfs(c[i].v,C^1);
	}
}
bool dp[N][N];
bool opt[N][N];
bool st[N];
void print(int n,int cnt)
{
	if(!n) return;
	print(n-1,cnt-(opt[n][cnt]?v[n].first:v[n].second));
	st[n]=opt[n][cnt];
}
int ans[N];
int main()
{
	int n,m;
	read(n,m);
	int n1,n2,n3;
	read(n1,n2,n3);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		addedge(x,y),addedge(y,x);
	}
	memset(col,255,sizeof(col));
	v.pb(mkpr(-1,-1));
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			++id;
			c1=c2=0;
			dfs(i,0);
			v.pb(mkpr(c1,c2));
		}
	}
	dp[0][0]=true;
	for(int i=1;i<SZ(v);++i)
	{
		c1=v[i].first,c2=v[i].second;
		for(int j=c1;j<=n;++j)
		{
			if(dp[i-1][j-c1])
			{
				dp[i][j]=true;
				opt[i][j]=1;
			}
		}
		for(int j=c2;j<=n;++j)
		{
			if(dp[i-1][j-c2])
			{
				dp[i][j]=true;
				opt[i][j]=0;
			}
		}
	}
	if(dp[SZ(v)-1][n2])
	{
		printf("YES\n");
		print(SZ(v)-1,n2);
		for(int i=1;i<=n;++i)
		{
			if(st[tag[i]]==col[i])
			{
				ans[i]=2;
			}
			else
			{
				if(n1) ans[i]=1,--n1;
				else ans[i]=3;
			}
		}
		for(int i=1;i<=n;++i) printf("%d",ans[i]);
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}