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
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=400005;
int a[N],b[N],pos[N];
int to[N],cnt[N];
struct edge{
	int v,nxt;
	std::vector<int> w;
}c[N<<1];
int front[N],edge_cnt=-1;
Finline void addedge(int u,int v,const std::vector<int> &w)
{
	c[++edge_cnt]=(edge){v,front[u],w};
	front[u]=edge_cnt;
	
	c[++edge_cnt]=(edge){u,front[v],w};
	front[v]=edge_cnt;
}
int sum,cur;
bool mark[N<<1];
std::vector<int> v1,v2;
void dfs(int x,bool flag)
{
	mark[x]=true;
	if(cnt[x]==2) for(int i=front[x];~i;i=c[i].nxt) sum+=SZ(c[i].w);
	for(int i=front[x];~i;i=c[i].nxt)
	{
		if(!mark[c[i].v])
		{
			if(flag) cur+=SZ(c[i].w);
			dfs(c[i].v,!flag);
			return;
		}
	}
}
std::vector<int> res;
void getans(int x,bool flag)
{
	mark[x]=true;
	for(int i=front[x];~i;i=c[i].nxt)
	{
		if(!mark[c[i].v])
		{
			if(flag) for(auto it:c[i].w) res.pb(it);
			getans(c[i].v,!flag);
			return;
		}
	}
}
void MAIN()
{
	int n;
	read(n);
	res.clear();
	memset(mark,0,(n+3)<<1);
	memset(pos,0,(n+3)<<2);
	memset(cnt,0,(n+3)<<2);
	edge_cnt=-1,memset(front,255,(n+3)<<2);
	for(int i=1;i<=n;++i) read(a[i]),++cnt[a[i]];
	for(int i=1;i<=n;++i) read(b[i]),++cnt[b[i]];
	for(int i=1;i<=n;++i)
	{
		if(cnt[i]!=2)
		{
			printf("-1\n");
			return;
		}
	}
	memset(cnt,0,(n+3)<<2);
	for(int i=1;i<=n;++i) ++cnt[a[i]],pos[a[i]]=i;
	for(int i=1;i<=n;++i) if(cnt[a[i]]==1) to[a[i]]=b[i];
	for(int i=1;i<=n;++i)
	{
		if(cnt[a[i]]==2)
		{
			std::vector<int> qaq;
			int cur=i;
			while(cur)
			{
				qaq.pb(cur);
				if(!pos[b[cur]])
				{
					addedge(a[i],b[cur],qaq);
					break;
				}
				cur=pos[b[cur]];
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(cnt[i]!=1&&!mark[i])
		{
			cur=0,sum=0;
			dfs(i,1);
			if(sum-cur<cur) front[i]=c[front[i]].nxt;
		}
	}
	memset(mark,0,n+3);
	for(int i=1;i<=n;++i) if(cnt[i]!=1&&!mark[i]) getans(i,1);
	printf("%d\n",SZ(res));for(auto it:res) printf("%d ",it);
	printf("\n");
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}