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

const int N=100005;
std::vector<int> e[N];
int dp[N][2];
struct node{
	int first,second;
	Finline node():first(-inf),second(-inf){}
	Finline node operator += (int o)
	{
		if(o>first)
		{
			second=first;
			first=o;
		}
		else chmax(second,o);
		return *this;
	}
};
int ans=1;
void dfs(int x,int fa)
{
	int cnt=0;
	node a,b;
	for(auto v:e[x])
	{
		if(v!=fa)
		{
			dfs(v,x);
			a+=dp[v][0];
			b+=max(dp[v][0],dp[v][1]);
			++cnt;
		}
	}
	if(!cnt)
	{
		dp[x][0]=0;
		dp[x][1]=1;
		return;
	}
	dp[x][0]=b.first+cnt-1;
	dp[x][1]=1+a.first;
	chmax(ans,dp[x][1]);
	if(!fa)
	{
		chmax(ans,a.first+a.second+1);
		chmax(ans,b.first+b.second+cnt-2);
	}
	else
	{
		chmax(ans,a.first+a.second+1);
		chmax(ans,b.first+b.second+1+cnt-2);
	}
}
int main()
{
	int n;
	read(n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}