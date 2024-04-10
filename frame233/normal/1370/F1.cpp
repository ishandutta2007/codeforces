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
const ll INF=0x3f3f3f3f3f3f3f3f;

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

const int N=1005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int dep[N];
std::vector<int> v;
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa) continue;
		dfs(v,x);
	}
}
int goal;
std::vector<int> cur,res;
void getpath(int x,int fa)
{
	cur.pb(x);
	if(x==goal)
	{
		res=cur;
		return;
	}
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa) continue;
		getpath(v,x);
	}
	cur.pop_back();
}
bool mark[N];
char s[20];
void MAIN()
{
	edge_cnt=0;
	memset(front,0,sizeof(front));
	int n;
	read(n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		addedge(x,y),addedge(y,x);
	}
	printf("? %d ",n);
	for(int i=1;i<=n;++i) printf("%d ",i);
	printf("\n");
	fflush(stdout);
	read(x,y);
	int l=(y>>1)-1,r=y;
	int A=0;
	dfs(x,0);
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		v.clear();
		for(int i=1;i<=n;++i) if(dep[i]>=mid) v.pb(i);
		if(v.empty())
		{
			r=mid-1;
			continue;
		}
		printf("? %d ",SZ(v));
		for(auto it:v) printf("%d ",it);
		printf("\n");
		fflush(stdout);
		int a,b;
		read(a,b);
		if(b==y) l=mid,A=a;
		else r=mid-1;
	}
	cur.clear(),res.clear();
	goal=A;
	getpath(x,0);
	memset(mark,0,sizeof(mark));
	for(auto it:res) mark[it]=true;
	mark[x]=0;
	v.clear();
	for(int i=1;i<=n;++i) if(dep[i]==y-dep[A]&&!mark[i]) v.pb(i);
	if(SZ(v)!=1)
	{
		printf("? %d ",SZ(v));
		for(auto it:v) printf("%d ",it);
		printf("\n");
		fflush(stdout);
		read(y);
	}
	else y=v.back();
	printf("! %d %d\n",A,y);
	fflush(stdout);
	read_str(s);
}
int main()
{
	dep[0]=-1;
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}