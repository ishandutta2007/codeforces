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

const int N=200005;
int f[35],siz[N],Fa[N];
std::vector<int> e[N];
void dfs(int x,int fa)
{
	siz[x]=1,Fa[x]=fa;
	for(auto v:e[x])if(v!=fa)dfs(v,x),siz[x]+=siz[v];
}
std::vector<pi> qwq;
void DFS(int x,int fa)
{
	for(auto v:e[x])if(v!=fa)DFS(v,x),qwq.pb({x,v});
}
bool check(int n,std::vector<pi> E)
{
	if(n==1)return true;
	int cur=std::find(f+1,f+31,n)-f;
	if(cur==31)return false;
	std::vector<int> nd;
	for(auto [x,y]:E)e[x].clear(),e[y].clear(),nd.pb(x),nd.pb(y);
	std::sort(nd.begin(),nd.end()),nd.erase(std::unique(nd.begin(),nd.end()),nd.end());
	for(auto [x,y]:E)e[x].pb(y),e[y].pb(x);
	dfs(nd[0],0);
	std::vector<std::pair<std::pair<int,std::vector<pi>>,std::pair<int,std::vector<pi>>>> v;
	for(auto it:nd)
	{
		if(siz[it]==f[cur-1]||siz[it]==f[cur-2])
		{
			qwq.clear(),DFS(it,Fa[it]);
			std::vector<pi> tp(qwq);qwq.clear();
			DFS(Fa[it],it);
			v.pb({{siz[it],tp},{n-siz[it],qwq}});
		}
	}
	if(SZ(v)>1)v.resize(1);
	for(auto [a,b]:v)if(check(a.first,a.second)&&check(b.first,b.second))return true;
	return false;
}
int main()
{
	f[0]=f[1]=1;for(int i=2;i<=30;++i)f[i]=f[i-1]+f[i-2];
	int n;read(n);
	int x,y;std::vector<pi> E;
	for(int i=1;i<n;++i)read(x,y),E.pb({x,y});
	printf(check(n,E)?"YES\n":"NO\n");
	return 0;
}