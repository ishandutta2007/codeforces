// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
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
const ll INF=0x3f3f3f3f3f3f3f3f;

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
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=400005;
int n,m,k;
struct edge{
	int v,w;
	Finline bool operator < (const edge &o)const
	{
		return w<o.w;
	}
};
std::vector<edge> e[N],_[N];
int mark[15][15];
std::vector<pi> ban[15][15];
int valid[15][15];
int dg[N],ans;
void dfs(int dep)
{
	if(dep==k+1)
	{
		++ans;return;
	}
	int qwq=(1<<dep)-1;
	for(int i=1;i<=dep;++i) if(!mark[dep][i]) qwq&=valid[dep][i];
	for(int i=1;i<=dep;++i)
	{
		if(((qwq>>(i-1))&1)&&!mark[dep][i])
		{
			for(auto it:ban[dep][i]) ++mark[it.first][it.second];
			dfs(dep+1);
			for(auto it:ban[dep][i]) --mark[it.first][it.second];
		}
	}
}
int main()
{
	read(n,m,k);
	int x,y,z;
	for(int i=1;i<=m;++i)
	{
		read(x,y,z);
		++dg[x];
		_[x].pb((edge){y,z});
		e[y].pb((edge){x,z});
	}
	for(int i=1;i<=n;++i) std::sort(e[i].begin(),e[i].end()),std::sort(_[i].begin(),_[i].end());
	for(int i=1;i<=k;++i) for(int j=1;j<=i;++j) valid[i][j]=(1<<i)-1;
	for(int i=1;i<=n;++i)
	{
		std::vector<pi> v,tmp;
		for(auto it:e[i])
		{
			int k=std::lower_bound(_[it.v].begin(),_[it.v].end(),(edge){i,it.w})-_[it.v].begin()+1;
			v.pb(mkpr(dg[it.v],k));
		}
		if(v.empty()) continue;
		std::sort(v.begin(),v.end());
		pi last=mkpr(-1,-1);
		for(auto it:v)
		{
			if(it!=last) tmp.pb(it);
			else mark[it.first][it.second]=1;
			last=it;
		}
		v=tmp;
		int vis=0;
		for(auto it:v)
		{
			if(it.first==v.back().first) vis|=1<<(it.second-1);
			for(auto _:v) if(it!=_) ban[it.first][it.second].pb(_);
		}
		valid[v.back().first][v.back().second]&=vis;
	}
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=i;++j)
		{
			std::sort(ban[i][j].begin(),ban[i][j].end());
			ban[i][j].erase(std::unique(ban[i][j].begin(),ban[i][j].end()),ban[i][j].end());
//			for(auto it:ban[i][j]) printf("(%d,%d) -> (%d,%d)\n",i,j,it.first,it.second);
		}
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}