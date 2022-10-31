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

const int N=1000005;
std::vector<int> v[N],e[N];
int ans=1;
bool used[N];
int col[N];
void dfs(int x,int fa)
{
	for(auto it:v[x])
	{
		if(col[it]) used[col[it]]=true;
	}
	int cur=1;
	for(auto it:v[x])
	{
		if(col[it]) continue;
		while(used[cur]) ++cur;
		col[it]=cur;
		used[cur]=true;
	}
	for(auto it:v[x]) used[col[it]]=false;
	for(auto to:e[x])
	{
		if(to!=fa)
		{
			dfs(to,x);
		}
	}
}
int main()
{
	int n,m;
	read(n,m);
	int x,y;
	for(int i=1;i<=n;++i)
	{
		read(x);
		chmax(ans,x);
		for(int j=1;j<=x;++j) read(y),v[i].pb(y);
	}
	for(int i=1;i<n;++i)
	{
		read(x,y);
		e[x].pb(y);
		e[y].pb(x);
	}
	dfs(1,0);
	printf("%d\n",ans);
	for(int i=1;i<=m;++i)
	{
		if(!col[i]) col[i]=1;
		printf("%d ",col[i]);
	}
	printf("\n");
	return 0;
}