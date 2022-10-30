// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=105;
typedef __int128 LL;
struct edge{int v,nxt;}c[N<<1];
int front[N],edge_cnt,n;
inline void addedge(int u,int v){c[++edge_cnt]=(edge){v,front[u]},front[u]=edge_cnt;}
LL f[N];
int col[N],FA[N];
void dfs(int x,int fa)
{
	FA[x]=fa;
	for(int i=front[x];i;i=c[i].nxt)if(c[i].v!=fa)dfs(c[i].v,x);
	auto check=[&](LL st)->bool
	{
		std::priority_queue<std::pair<LL,int>> q;
		for(int _=front[x];_;_=c[_].nxt)if(c[_].v!=fa)q.push({f[c[_].v],c[_].v});
		bool flag=false;
		for(int j=n;j>=1&&!q.empty();--j)
		{
			if(st>>j&1)
			{
				auto [x,v]=q.top();q.pop();
				if(x>>j&1)
				{
					if(!q.empty()&&(q.top().first>>j&1)){flag=true;break;}
					q.push({x^((LL)(1)<<j),v});
				}
				else col[v]=j;
			}
			else if(q.top().first>>j&1){flag=true;break;}
		}
		return !(flag||!q.empty());
	};
	LL st=0;for(int i=1;i<=n;++i)st^=(LL)(1)<<i;
	for(int i=n;i>=1;--i)if(check(st^((LL)(1)<<i)))st^=(LL)(1)<<i;
	assert(check(st)),f[x]=st;
}
bool mark[N];
void DFS(int x,int fa)
{
	mark[x]=true;
	for(int i=front[x];i;i=c[i].nxt)if(c[i].v!=fa)DFS(c[i].v,x);
}
int main()
{
	read(n);int x,y;
	for(int i=1;i<n;++i)read(x,y),addedge(x,y),addedge(y,x);
	dfs(1,0);
	int k=*std::max_element(col+1,col+n+1);
	for(int C=k;C>=1;--C)for(int i=2;i<=n;++i)if(!mark[i]&&!mark[FA[i]]&&col[i]==C)
	{
		printf("? %d %d\n",i,FA[i]),fflush(stdout),read(x);
		DFS(x==i?FA[i]:i,x);
	}
	for(int i=1;i<=n;++i)if(!mark[i])printf("! %d\n",i);
	return fflush(stdout),0;
}