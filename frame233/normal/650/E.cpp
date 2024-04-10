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
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=500005;
std::vector<int> e1[N],e2[N];
int fa1[N],fa2[N];
void dfs1(int x,int fa)
{
	fa1[x]=fa;
	for(auto v:e1[x])if(v!=fa)dfs1(v,x);
}
void dfs2(int x,int fa)
{
	fa2[x]=fa;
	for(auto v:e2[x])if(v!=fa)dfs2(v,x);
}
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
std::vector<std::tuple<int,int,int,int>> ans;
void dfs(int x,int fa)
{
	for(auto v:e1[x])if(v!=fa) dfs(v,x);
	if(fa!=fa2[x]&&fa2[fa]!=x) ans.pb({fa,x,find(x),fa2[find(x)]});
}
int main()
{
	int n,x,y;read(n);
	for(int i=1;i<n;++i) read(x,y),e1[x].pb(y),e1[y].pb(x);
	for(int i=1;i<n;++i) read(x,y),e2[x].pb(y),e2[y].pb(x);
	dfs1(1,0),dfs2(1,0);
	for(int i=1;i<=n;++i) fa[i]=(fa1[i]==fa2[i]||fa1[fa2[i]]==i)?fa2[i]:i;
	dfs(1,0);
	printf("%d\n",SZ(ans));
	for(auto it:ans) printf("%d %d %d %d\n",std::get<0>(it),std::get<1>(it),std::get<2>(it),std::get<3>(it));
	return 0;
}