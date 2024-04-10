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
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

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
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
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

const int N=205;
std::vector<int> v[N];
char s[N];
int dg[N];
bool vis[N],flag;
std::vector<int> ans;
void dfs(int x,int fa)
{
	if(vis[x])
	{
		flag=true;
		return;
	}
	if(flag) return;
	vis[x]=true;
	ans.push_back(x);
	for(auto it:v[x])
	{
		if(it!=fa)
		{
			dfs(it,x);
			if(flag) return;
		}
	}
}
void MAIN()
{
	ans.clear();
	for(int i=0;i<26;++i) v[i].clear();
	memset(vis,0,26);
	flag=0;
	int n=read_str(s+1);
	for(int i=1;i<n;++i)
	{
		v[s[i]-97].push_back(s[i+1]-97);
		v[s[i+1]-97].push_back(s[i]-97);
	}
	std::vector<int> qwq;
	for(int i=0;i<26;++i)
	{
		std::sort(v[i].begin(),v[i].end());
		v[i].erase(std::unique(v[i].begin(),v[i].end()),v[i].end());
		dg[i]=(int)v[i].size();
		if(dg[i]>2)
		{
			printf("NO\n");
			return;
		}
		if(dg[i]==1)
		{
			qwq.push_back(i);
		}
		if(!dg[i])
		{
			ans.push_back(i);
		}
	}
	for(auto it:qwq)
	{
		if(!vis[it])
		{
			dfs(it,-1);
			if(flag)
			{
				printf("NO\n");
				return;
			}
		}
	}
	if((int)ans.size()!=26)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for(auto it:ans) printf("%c",it+97);
	printf("\n");
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}