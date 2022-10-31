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

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

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
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void add_edge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int dg[N];
std::vector<std::pair<int,int> > ans;
int maxx;
void dfs(int x,int fa,int last)
{
	int cur=last+1;
	int cnt=dg[x];
	if(fa) --cnt;
	ans.pb(mkpr(x,cur));
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v!=fa)
		{
			if(cur==maxx)
			{
				cur-=cnt+1;
				ans.pb(mkpr(x,cur));
			}
			dfs(v,x,cur);
			++cur;
			ans.pb(mkpr(x,cur));
		}
	}
	if(fa&&last!=cur) ans.pb(mkpr(x,last));
}
int main()
{
	int n;
	read(n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add_edge(x,y),add_edge(y,x);
		++dg[x],++dg[y];
	}
	for(int i=1;i<=n;++i) chmax(maxx,dg[i]);
	dfs(1,0,-1);
	printf("%d\n",SZ(ans));
	for(auto it:ans) printf("%d %d\n",it.first,it.second);
	return 0;
}