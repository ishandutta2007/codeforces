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
std::vector<int> e[N];
struct DSU{
	int fa[N];
	void init(int n){std::iota(fa+1,fa+n+1,1);}
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	inline bool merge(int x,int y)
	{
		x=find(x),y=find(y);
		return x==y?false:(fa[x]=y,true);
	}
}rest,all,o;
bool mark[N];
int _q[N],_l,_r;
struct edge{
	int u,v,w;
	inline bool operator < (const edge &o)const{return w<o.w;}
}a[N];
int main()
{
	int n,m;read(n,m);
	int qwq=0;
	for(int i=1,x,y,z;i<=m;++i)read(x,y,z),e[x].pb(y),e[y].pb(x),a[i]={x,y,z},qwq^=z;
	rest.init(n+1),all.init(n),o.init(n);
	int cnt=0;
	for(int i=1;i<=n;++i)if(rest.fa[i]==i)
	{
		_q[_l=_r=1]=i;
		while(_l!=_r+1)
		{
			int x=_q[_l++];
			for(auto v:e[x])mark[v]=true;
			int v=rest.find(1);
			while(v<=n)
			{
				if(!mark[v])all.merge(x,v),rest.merge(v,v+1),_q[++_r]=v;
				v=rest.find(v+1);
			}
			for(auto v:e[x])mark[v]=false;
		}
		++cnt;
	}
	std::sort(a+1,a+m+1);
	if((1LL*n*(n-1)/2-m)>(n-cnt))qwq=0;
	ll ans=0;
	for(int i=1;i<=m;++i)
	{
		auto [u,v,w]=a[i];
		if(all.merge(u,v))ans+=w,o.merge(u,v);
		else if(o.merge(u,v))chmin(qwq,w);
	}
	printf("%lld\n",ans+qwq);
	return 0;
}