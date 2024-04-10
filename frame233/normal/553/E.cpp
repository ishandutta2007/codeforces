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

const int max_len=1<<16,N=max_len+5;
const double PI=acos(-1.0);
struct comp{
	double x,y;
	inline comp operator + (const comp &o)const{return (comp){x+o.x,y+o.y};}
	inline comp operator - (const comp &o)const{return (comp){x-o.x,y-o.y};}
	inline comp operator * (const comp &o)const{return (comp){x*o.x-y*o.y,x*o.y+y*o.x};}
};
comp Omgs[N];
int rev[N];
void setup()
{
	int tmp=max_len>>1;
	for(int i=tmp,t=0;i<max_len;++i,++t) Omgs[i]=(comp){std::cos(2.0*t*PI/max_len),std::sin(2.0*t*PI/max_len)};
	for(int i=tmp-1;i>=1;--i) Omgs[i]=Omgs[i<<1];
}
int calc(int len)
{
	int limit=1;
	while(limit<len) limit<<=1;
	for(int i=1;i<limit;++i) rev[i]=(rev[i>>1]>>1)|(i&1?limit>>1:0);
	return limit;
}
void dft(comp *a,int limit)
{
	for(int i=0;i<limit;++i) if(i<rev[i]) std::swap(a[i],a[rev[i]]);
	for(int len=2;len<=limit;len<<=1)for(int i=0;i<limit;i+=len)
	{
		comp *p=a+i,*q=a+i+(len>>1),*w=Omgs+(len>>1);
		for(int _=0;_<len>>1;++_,++p,++q,++w)
		{
			comp tmp(*q**w);
			*q=*p-tmp,*p=*p+tmp;
		}
	}
}
void idft(comp *a,int limit)
{
	std::reverse(a+1,a+limit),dft(a,limit);
	for(int i=0;i<limit;++i) a[i].x/=(double)limit;
}
void polymul(double *a,double *b,double *c,int n,int m)
{
	static comp f[N],g[N];
	int limit=calc(n+m);
	for(int i=0;i<n;++i) f[i]=(comp){a[i],0.0};
	for(int i=0;i<m;++i) g[i]=(comp){b[i],0.0};
	for(int i=n;i<limit;++i) f[i]=(comp){0.0,0.0};
	for(int i=m;i<limit;++i) g[i]=(comp){0.0,0.0};
	dft(f,limit),dft(g,limit);
	for(int i=0;i<limit;++i) f[i]=f[i]*g[i];
	idft(f,limit);
	for(int i=0;i<limit;++i) c[i]=f[i].x;
}
std::vector<int> v[N];
struct edge{
	int v,nxt,w,id;
}e[105];
int s[105][20005],p[105][20005];
int front[N],edge_cnt;
inline void addedge(int u,int v,int w,int id)
{
	e[++edge_cnt]=(edge){v,front[u],w,id};
	front[u]=edge_cnt;
}
int to[N];
int n,m,t;
double dp[55][20005],val[105][20005];
double a[N],b[N],c[N];
void solve(int l,int r)
{
	if(l==r)
	{
		for(int i=1;i<=n;++i) for(auto id:v[i]) chmin(dp[i][l],val[id][l]+s[id][t+1-l]/100000.0*dp[to[id]][t+1]);
		return;
	}
	int mid=(l+r)>>1;
	solve(mid+1,r);
	for(int x=1;x<=n;++x)
	{
		for(int i=front[x];i;i=e[i].nxt)
		{
			int id=e[i].id;
			for(int j=mid+1;j<=r;++j) a[j-mid-1]=dp[x][j]/100000.0;
			for(int j=1;j<=r-l;++j) b[r-l-j]=p[id][j];
			polymul(a,b,c,r-mid,r-l);
			for(int j=l;j<=mid;++j) val[id][j]+=c[j-(mid+1)+(r-l)];
		}
	}
	solve(l,mid);
}
int _q[2505],_l,_r;
int dis[55];
bool inq[N];
void spfa(int s)
{
	memset(dis,63,sizeof(dis));
	dis[s]=0,_q[_l=_r=1]=s;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		inq[x]=false;
		for(int i=front[x];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(dis[v]>dis[x]+e[i].w)
			{
				dis[v]=dis[x]+e[i].w;
				if(!inq[v]) _q[++_r]=v,inq[v]=true;
			}
		}
	}
}
int main()
{
	setup();
	int x,y,z,X;read(n,m,t,X);
	for(int i=0;i<n;++i)for(int j=0;j<=t+1;++j) dp[i][j]=2e8;
	dp[n][t+1]=X;
	for(int i=0;i<=t;++i) dp[n][i]=0;
	for(int i=1;i<=m;++i)
	{
		read(x,y,z),addedge(y,x,z,i);
		v[x].pb(i),to[i]=y;
		for(int j=0;j<=t+1;++j) val[i][j]=z;
		for(int j=1;j<=t;++j) read(p[i][j]);
		for(int j=t;j>=0;--j) s[i][j]=s[i][j+1]+p[i][j];
		p[i][t+1]=0;
	}
	spfa(n);
	for(int i=1;i<=n;++i) dp[i][t+1]=X+dis[i];
	solve(0,t);
	printf("%.8lf\n",dp[1][0]);
	return 0;
}