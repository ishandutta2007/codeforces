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

const int N=400005;
const double PI=acos(-1.0);
const double cyc=2.0*PI;
struct vec{
	int x,y;
	inline double angle()const{return std::atan2(y,x);}
	inline double len()const{return sqrt(x*x+y*y);}
}a[N];
struct node{
	double l,r;
	bool opt;
	inline bool operator < (const node &o)const
	{
		return r<o.r;
	}
};
double t[N];
struct BIT{
	int c[N];
	inline void add(int x,int C){for(;x;x-=lowbit(x))c[x]+=C;}
	inline int sum(int x){int ans=0;for(;x<N;x+=lowbit(x))ans+=c[x];return ans;}
}tr,TR;
int n;
ll solve0(std::vector<node> v)
{
	int p=0;
	for(auto it:v) t[++p]=it.l,t[++p]=it.r;
	std::sort(t+1,t+p+1),p=std::unique(t+1,t+p+1)-t-1;
	std::sort(v.begin(),v.end());
	ll ans=0;
	memset(tr.c,0,sizeof(tr.c));
	for(auto it:v)
	{
		int l=std::lower_bound(t+1,t+p+1,it.l)-t,r=std::lower_bound(t+1,t+p+1,it.r)-t;
		if(it.opt) ans+=tr.sum(l);
		tr.add(l,-1),tr.add(r,1);
	}
	return ans;
}
ll solve1(std::vector<node> v)
{
	int p=0;
	for(auto it:v) t[++p]=it.l,t[++p]=it.r;
	std::sort(t+1,t+p+1),p=std::unique(t+1,t+p+1)-t-1;
	std::sort(v.begin(),v.end());
	ll ans=0;
	memset(tr.c,0,sizeof(tr.c));
	memset(TR.c,0,sizeof(TR.c));
	for(auto it:v)
	{
		int l=std::lower_bound(t+1,t+p+1,it.l)-t,r=std::lower_bound(t+1,t+p+1,it.r)-t;
		if(it.opt) ans+=tr.sum(l),TR.add(l,-1),TR.add(r,1),tr.add(l,-1),tr.add(r,1);
		else ans+=TR.sum(l),tr.add(l,-1),tr.add(r,1);
		
	}
	return ans;
}
ll calc(double R)
{
	std::vector<node> v0,v1;
	for(int i=1;i<=n;++i)
	{
		if(a[i].x*a[i].x+a[i].y*a[i].y<=R*R) continue;
		double cur=a[i].angle(),A=acos(R/a[i].len());
		double l=cur-A,r=cur+A;
		if(l<0) l+=cyc,r+=cyc;
		if(r>=cyc) v1.pb({l,r,true});
		else v0.pb({l,r,true}),v1.pb({l,r,false}),v1.pb({l+cyc,r+cyc,false});
	}
	return solve0(v0)+solve1(v1);
}
int main()
{
	ll k;read(n,k);k=1LL*n*(n-1)/2-k+1;
	for(int i=1;i<=n;++i) read(a[i].x,a[i].y);
	double l=0,r=1e5;
	int T=80;
	while(T--)
	{
		double mid=(l+r)/2.0;
		if(calc(mid)<k) r=mid;
		else l=mid;
	}
	printf("%.12lf\n",l);
	return 0;
}