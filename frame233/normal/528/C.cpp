// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
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
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=400005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt=-1;
Finline void add(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int dg[N];
bool vis[N];
int cnt=0;
std::vector<std::pair<int,int> > ans;
void dfs(int x)
{
	for(int i=front[x];~i;i=front[x])
	{
		front[x]=c[i].nxt;
		if(vis[i>>1]) continue;
		vis[i>>1]=true;
		dfs(c[i].v);
		++cnt;
		if(cnt&1) ans.push_back(std::make_pair(x,c[i].v));
		else ans.push_back(std::make_pair(c[i].v,x));
	}
}
int main()
{
	memset(front,255,sizeof(front));
	int n,m;
	read(n,m);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
		++dg[x],++dg[y];
	}
	std::vector<int> v;
	for(int i=1;i<=n;++i)
	{
		if(dg[i]&1)
		{
			v.push_back(i);
		}
	}
	for(int i=0;i<(int)v.size();i+=2)
	{
		add(v[i],v[i+1]);
		add(v[i+1],v[i]);
		++m;
	}
	if(m&1) add(1,1),add(1,1),++m;
	dfs(1);
	printf("%d\n",(int)ans.size());
	for(auto it:ans) printf("%d %d\n",it.first,it.second);
	return 0;
}