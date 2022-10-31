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

const int N=1000005;
int a[N];
int n,m;
char s[N];
Finline int getid(int x,int y)
{
	return (x-1)*m+y;
}
bool vis[N+2],used[N+1];
std::vector<int> e[N+3],rev[N+4];
int st[N+5],top;
bool flag;
std::vector<int> v,mark;
bool tag[N];
void dfs(int x)
{
	if(flag) return;
	if(vis[x])
	{
		flag=true;
		while(st[top]!=x) v.push_back(st[top--]);
		v.push_back(st[top--]);
		return;
	}
	vis[x]=true;
	st[++top]=x;
	for(int v:e[x])
	{
		dfs(v);
		if(flag) return;
	}
	vis[x]=false;
	--top;
}
int cur;
void dfs1(int x,int dep)
{
	used[x]=true;
	if(a[x]==0) mark[(cur+dep)%v.size()]=true;
	for(auto it:rev[x])
	{
		if(!tag[it])
		{
			dfs1(it,dep+1);
		}
	}
}
void MAIN()
{
	read(n,m);
	for(int i=1;i<=n*m;++i) e[i].clear(),rev[i].clear(),tag[i]=vis[i]=used[i]=false;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			scanf("%1d",&a[getid(i,j)]);
		}
	}
	for(int i=1;i<=n;++i)
	{
		read_str(s+1);
		for(int j=1;j<=m;++j)
		{
			if(s[j]=='R')
			{
				e[getid(i,j)].push_back(getid(i,j+1));
				rev[getid(i,j+1)].push_back(getid(i,j));
			}
			else if(s[j]=='L')
			{
				e[getid(i,j)].push_back(getid(i,j-1));
				rev[getid(i,j-1)].push_back(getid(i,j));
			}
			else if(s[j]=='U')
			{
				e[getid(i,j)].push_back(getid(i-1,j));
				rev[getid(i-1,j)].push_back(getid(i,j));
			}
			else if(s[j]=='D')
			{
				e[getid(i,j)].push_back(getid(i+1,j));
				rev[getid(i+1,j)].push_back(getid(i,j));
			}
		}
	}
	int ans=0,res=0;
	for(int i=1;i<=n*m;++i)
	{
		if(!used[i])
		{
			flag=false;
			v.clear();
			top=0;
			dfs(i);
			for(auto it:v) tag[it]=true;
			mark.clear();
			mark.resize(v.size());
			for(int j=0;j<(int)v.size();++j)
			{
				cur=j;
				dfs1(v[j],0);
			}
			ans+=v.size();
			for(auto it:mark)
			{
				if(it) ++res;
			}
		}
	}
	printf("%d %d\n",ans,res);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}