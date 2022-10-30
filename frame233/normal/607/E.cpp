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

const int N=100005;

const long double eps=1e-10,PI=acos(-1.0);
inline int dcmp(long double a)
{
	return a>eps?1:a<-eps?-1:0;
}
long double k[N],b[N];
std::pair<long double,int> t[N<<1];
int n,m;
bool tag[N];
std::vector<int> v1[N];
int v2[N],pos;
int A[N],B[N];
void init(long double mid)
{
	pos=0;
	for(int i=1;i<=n;++i)
	{
		long double K=k[i],B=b[i];
		long double D=mid*mid*(K*K+1)-B*B;
		if(D>=0)
		{
			D=std::sqrt(D);
			long double x1=(-K*B-D)/(K*K+1),x2=(-K*B+D)/(K*K+1);
			long double y1=x1*K+B,y2=x2*K+B;
			t[++pos]=mkpr(std::atan2(y1,x1),i),t[++pos]=mkpr(std::atan2(y2,x2),i);
			tag[i]=true;
			::A[i]=::B[i]=0;
		}
		else tag[i]=false;
	}
	std::sort(t+1,t+pos+1);
	int id=0;
	for(int i=1;i<=pos;++i)
	{
		++id;
		if(!A[t[i].second]) A[t[i].second]=id;
		else B[t[i].second]=id;
	}
}
struct BIT{
	int c[N];
	void add(int x,int C){for(;x<N;x+=lowbit(x))c[x]+=C;}
	int sum(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}tr;
ll calc(long double mid)
{
	init(mid);
	memset(tr.c,0,sizeof(tr.c));
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		if(tag[i])
		{
			int l=A[i],r=B[i];
			v1[l].pb(r),++v2[r];
		}
	}
	for(int i=1;i<=pos;++i)
	{
		for(auto it:v1[i])
		{
			ans+=tr.sum(it);
			tr.add(it,1);
		}
		tr.add(i,-v2[i]);
		v1[i].clear(),v2[i]=0;
	}
	return ans;
}
struct node{
	int val,id;
	inline bool operator < (const node &o)const
	{
		return val==o.val?id<o.id:val<o.val;
	}
};
std::set<node> S;
std::vector<node> V1[N];
std::vector<node> V2[N];
inline long double getdis(int x,int y)
{
	long double X=(b[x]-b[y])/(k[y]-k[x]);
	long double Y=X*k[x]+b[x];
	return sqrt(X*X+Y*Y);
}
long double solve(long double mid)
{
	init(mid);
	for(int i=1;i<=n;++i)
	{
		if(tag[i])
		{
			int l=A[i],r=B[i];
			V1[l].pb((node){r,i});
			V2[r].pb((node){r,i});
		}
	}
	long double ans=0;
	int cnt=0;
	for(int i=1;i<=pos;++i)
	{
		std::sort(V1[i].begin(),V1[i].end());
		for(auto it:V1[i])
		{
			for(auto _=S.lower_bound((node){i,0}),end=S.upper_bound((node){it.val,inf});_!=end;++_) ans+=getdis(_->id,it.id),++cnt;
			S.insert(it);
		}
		for(auto it:V2[i]) S.erase(it);
		V1[i].clear(),V2[i].clear();
	}
	return ans-1.0*(cnt-m)*mid;
}
int main()
{
	read(n);
	long double X,Y;
	int x,y;read(x,y,m);
	X=x/1000.0,Y=y/1000.0;
	for(int i=1;i<=n;++i)
	{
		read(x,y);
		k[i]=x/1000.0,b[i]=y/1000.0;
		b[i]=b[i]+k[i]*X-Y;
	}
	long double l=0,r=2.2e9;
	int T=60;
	while(T--)
	{
		long double mid=(l+r)/2.0;
		if(calc(mid)<m) l=mid;
		else r=mid;
	}
	printf("%.8Lf\n",solve(l));
	return 0;
}