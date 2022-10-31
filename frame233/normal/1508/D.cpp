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

const int N=2005;
int X[N],Y[N];
struct node{
	int x,y,id;
	inline bool operator < (const node &o)const{return std::atan2(y,x)<std::atan2(o.y,o.x);}
}p[N];
int a[N],col[N];
bool vis[N];
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
	int n;read(n);
	for(int i=1;i<=n;++i)read(X[i],Y[i],a[i]);
	bool flag=true;
	for(int i=1;i<=n;++i)flag&=a[i]==i;
	if(flag)return puts("0"),0;
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=n;++i)if(!vis[i]&&a[i]!=i)for(int j=i;!vis[j];j=a[j])vis[j]=true,col[j]=i,fa[j]=i;
	int m=0,id=0;
	for(int i=1;i<=n;++i)if(a[i]!=i)p[++m]={X[i],Y[i],i};
	for(int i=1;i<=m;++i)if(!id||p[i].x<p[id].x||(p[i].x==p[id].x&&p[i].y<p[id].y))id=i;
	std::swap(p[id],p[1]);
	for(int i=2;i<=m;++i)p[i].x-=p[1].x,p[i].y-=p[1].y;
	std::sort(p+2,p+m+1);
	std::vector<pi> v;
	for(int i=2;i<m;++i)
	{
		int a=col[p[i].id],b=col[p[i+1].id];
		if(find(a)!=find(b))fa[find(a)]=find(b),v.pb({p[i].id,p[i+1].id}),std::swap(::a[p[i].id],::a[p[i+1].id]);
	}
	int rt=p[1].id;
	while(a[rt]!=rt)v.pb({rt,a[rt]}),std::swap(a[rt],a[a[rt]]);
	printf("%d\n",SZ(v));
	for(auto [x,y]:v)printf("%d %d\n",x,y);
	return 0;
}