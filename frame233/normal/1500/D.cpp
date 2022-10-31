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

const int N=1505;
struct vec{
	pi a[12];uint p;
	vec(){p=0;std::fill(a,a+12,mkpr(0,0));}
	vec(const pi &o){a[0]=o,p=1,std::fill(a+1,a+12,mkpr(0,0));}
	inline uint size(){return p;}
	inline void push_back(const pi &o){a[p++]=o;}
	inline pi operator [] (int o)const{return a[o];}
	inline pi& operator [] (int o){return a[o];}
};
vec b[N][N],c[N][N];
int d[N][N],n,q,ans[N],X,Y;
bool vis[N*N],flag;
inline int D(pi p){return max(abs(X-p.first),abs(Y-p.second));}
vec merge(vec a,vec b)
{
	vec c;
	int i=0,j=0;
	while(SZ(c)<=q&&(i<SZ(a)||j<SZ(b)))
	{
		if(j==SZ(b)||(i!=SZ(a)&&D(a[i])<=D(b[j])))
		{
			if(!vis[d[a[i].first][a[i].second]])c.pb(a[i]);
			vis[d[a[i].first][a[i].second]]=true,++i;
		}
		else
		{
			if(!vis[d[b[j].first][b[j].second]])c.pb(b[j]);
			vis[d[b[j].first][b[j].second]]=true,++j;
		}
	}
	for(uint i=0;i<a.size();++i)vis[d[a[i].first][a[i].second]]=false;
	for(uint i=0;i<b.size();++i)vis[d[b[i].first][b[i].second]]=false;
	return c;
}
int main()
{
	read(n,q);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)read(d[i][j]);
	for(int i=n;i>=1;--i)
	{
		vec cur;
		for(int j=n;j>=1;--j)
		{
			X=i,Y=j,cur=merge(cur,vec({i,j}));
			b[i][j]=merge(b[i+1][j],vec({i,j}));
			c[i][j]=merge(c[i+1][j+1],merge(cur,b[i][j]));
			++ans[min({n-i+1,n-j+1,SZ(c[i][j])<=q?inf:D(c[i][j][q])})];
		}
	}
	for(int i=n;i>=1;--i)ans[i]+=ans[i+1];
	for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}