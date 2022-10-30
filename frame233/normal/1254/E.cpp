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
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=500005;
const int mod=1000000007;
ll fac[N];
bool mark[N];
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
struct node{
	int fir,end;
	std::vector<int> e,nxt;
	void init()
	{
		std::sort(e.begin(),e.end());
		nxt.resize(SZ(e));
		for(auto &&it:nxt) it=-1;
		fir=end=-1;
	}
	inline int getid(int x)
	{
		return std::lower_bound(e.begin(),e.end(),x)-e.begin();
	}
	int calc()
	{
		memset(mark,0,SZ(nxt));
		for(auto it:nxt)
		{
			if(it==-1) continue;
			if(mark[it]){puts("0");exit(0);}
			mark[it]=true;
		}
		if(~fir&&mark[fir]){puts("0");exit(0);}
		if(~end&&~nxt[end]){puts("0");exit(0);}
		for(int i=0;i<SZ(nxt);++i) fa[i]=i;
		for(int i=0;i<SZ(nxt);++i)
		{
			if(~nxt[i])
			{
				if(find(i)==find(nxt[i])){puts("0");exit(0);}
				fa[find(i)]=find(nxt[i]);
			}
		}
		int cnt=0;
		int A=fir==-1?-1:find(fir),B=end==-1?-1:find(end);
		for(int i=0;i<SZ(nxt);++i) if(fa[i]==i) cnt+=i!=A&&i!=B;
		if(~A&&A==B&&cnt){puts("0");exit(0);}
		return fac[cnt];
	}
}a[N];
int Fa[N],dep[N],n;
void dfs(int x,int fa)
{
	Fa[x]=fa,dep[x]=dep[fa]+1;
	for(auto v:a[x].e) if(v!=fa) dfs(v,x);
}
void upd(int x,int y)
{
	if(x==y){puts("0");exit(0);}
	int X=x,Y=y;
	std::vector<int> v1,v2;
	while(dep[x]>dep[y]) v1.pb(x),x=Fa[x];
	while(dep[y]>dep[x]) v2.pb(y),y=Fa[y];
	while(x!=y) v1.pb(x),v2.pb(y),x=Fa[x],y=Fa[y];
	std::vector<int> v(v1);v.pb(x);std::reverse(v2.begin(),v2.end());for(auto it:v2) v.pb(it);
	x=X,y=Y;
	if(~a[x].fir||~a[y].end){puts("0");exit(0);}
	a[x].fir=a[x].getid(v[1]),a[y].end=a[y].getid(v[SZ(v)-2]);
	for(int i=1;i+1<SZ(v);++i)
	{
		int cur=v[i];
		int A=a[cur].getid(v[i-1]),B=a[cur].getid(v[i+1]);
		if(~a[cur].nxt[A]||A==a[cur].end||B==a[cur].fir){puts("0");exit(0);}
		a[cur].nxt[A]=B;
	}
}
int main()
{
	fac[0]=1;for(int i=1;i<N;++i) fac[i]=fac[i-1]*i%mod;
	read(n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		a[x].e.pb(y),a[y].e.pb(x);
	}
	for(int i=1;i<=n;++i) a[i].init();
	dfs(1,0);
	for(int i=1;i<=n;++i)
	{
		read(x);
		if(x) upd(x,i);
	}
	int ans=1;
	for(int i=1;i<=n;++i) ans=1ll*ans*a[i].calc()%mod;
	printf("%d\n",ans);
	return 0;
}