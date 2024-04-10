// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
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

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

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

const int N=1000005;
struct node{
	int x,y;
};
std::vector<node> v[N];
int opt[N];
int X[N],Y[N];
struct Union_set1{
	int fa[N];
	int tag[N];
	int node_cnt;
	Finline Union_set1(){for(int i=0;i<N;++i) fa[i]=i;node_cnt=500001;}
	int find(int x)
	{
		if(x==fa[x]) return x;
		int ans=find(fa[x]);
		if(ans!=fa[x]) chmax(tag[x],tag[fa[x]]);
		fa[x]=ans;
		return ans;
	}
	int getval(int x)
	{
		find(x);
		int ans=tag[x];
		if(fa[x]!=x) chmax(ans,tag[fa[x]]);
		return ans;
	}
	void merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		int cur=++node_cnt;
		fa[x]=fa[y]=cur;
	}
}S1;
struct Union_set2{
	int fa[N];
	ll tag[N];
	int siz[N];
	int node_cnt;
	Finline Union_set2(){for(int i=0;i<N;++i) fa[i]=i;node_cnt=500001;}
	int find(int x)
	{
		if(x==fa[x]) return x;
		int ans=find(fa[x]);
		if(ans!=fa[x]) tag[x]+=tag[fa[x]];
		fa[x]=ans;
		return ans;
	}
	ll getval(int x)
	{
		find(x);
		ll ans=tag[x];
		if(fa[x]!=x) ans+=tag[fa[x]];
		return ans;
	}
	void merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		int cur=++node_cnt;
		fa[x]=fa[y]=cur;
		siz[cur]=siz[x]+siz[y];
	}
}S2;
ll ans[N];
int main()
{
	int n,m;
	read(n,m);
	char ch;
	int x,y;
	for(int i=1;i<=m;++i)
	{
		ch=getchar();
		while(ch!='U'&&ch!='M'&&ch!='A'&&ch!='Z'&&ch!='Q') ch=getchar();
		if(ch=='U')
		{
			read(X[i],Y[i]);
			opt[i]=1;
		}
		else if(ch=='M')
		{
			read(x,y);
			S1.merge(x,y);
		}
		else if(ch=='A')
		{
			opt[i]=2;
			read(X[i]);
		}
		else if(ch=='Z')
		{
			read(x);
			chmax(S1.tag[S1.find(x)],i);
		}
		else
		{
			opt[i]=3;
			read(X[i]);
			v[S1.getval(X[i])].push_back((node){X[i],i});
		}
	}
	for(int i=1;i<=n;++i) S2.siz[i]=1;
	for(int i=1;i<=m;++i)
	{
		if(opt[i]==1)
		{
			S2.merge(X[i],Y[i]);
		}
		else if(opt[i]==2)
		{
			S2.tag[S2.find(X[i])]+=S2.siz[S2.find(X[i])];
		}
		else if(opt[i]==3)
		{
			ans[i]+=S2.getval(X[i]);
		}
		for(auto it:v[i])
		{
			ans[it.y]-=S2.getval(it.x);
		}
	}
	for(int i=1;i<=m;++i)
	{
		if(opt[i]==3)
		{
			printf("%lld\n",ans[i]);
		}
	}
	return 0;
}