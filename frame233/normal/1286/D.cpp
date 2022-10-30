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

const int N=100005;
const int mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
const int inv100=ksm(100);
struct mat{
	ll a,b,c,d;
	inline mat operator * (const mat &o)const
	{
		return (mat){(a*o.a+b*o.c)%mod,(a*o.b+b*o.d)%mod,(c*o.a+d*o.c)%mod,(c*o.b+d*o.d)%mod};
	}
}M[N];
void print(int x)
{
	for(int i=1;i<=100;++i)for(int j=1;j<=100;++j)if(1LL*i*ksm(j)%mod==x) return fprintf(stderr,"%d/%d\n",i,j),void();
}
struct seg_tr{
	#define ls(x) ((x)<<1)
	#define rs(x) ((x)<<1|1)
	mat f[N<<2];
	void build(int l,int r,int cur)
	{
		if(l==r) return f[cur]=M[l],void();
		int mid=(l+r)>>1;
		build(l,mid,ls(cur)),build(mid+1,r,rs(cur));
		f[cur]=f[ls(cur)]*f[rs(cur)];
	}
	void upd(int pos,int l,int r,int cur)
	{
 		if(l==r) return f[cur]=M[l],void();
 		int mid=(l+r)>>1;
 		pos<=mid?upd(pos,l,mid,ls(cur)):upd(pos,mid+1,r,rs(cur));
		f[cur]=f[ls(cur)]*f[rs(cur)];
	}
	inline int ask(){return (f[1].a+f[1].b)%mod;}
}tr;
int x[N],v[N],p[N];
struct info{
	int x,a,b;
	double val;
	ll coef;
	inline bool operator < (const info &o)const{return val<o.val;}
}a[N<<1];
int main()
{
	int n;read(n);
	for(int i=1;i<=n;++i)
	{
		read(x[i],v[i],p[i]);
		int tmp=1LL*p[i]*inv100%mod;
		M[i]={(1-tmp+mod)%mod,tmp,(1-tmp+mod)%mod,tmp};
	}
	int pos=0;
	for(int i=1;i<n;++i)
	{
		a[++pos]={i,1,0,(double)(x[i+1]-x[i])/(v[i]+v[i+1]),1LL*(x[i+1]-x[i])*ksm(v[i]+v[i+1])%mod};
		if(v[i]>v[i+1]) a[++pos]={i,1,1,(double)(x[i+1]-x[i])/(v[i]-v[i+1]),1LL*(x[i+1]-x[i])*ksm(v[i]-v[i+1])%mod};
		if(v[i]<v[i+1]) a[++pos]={i,0,0,(double)(x[i+1]-x[i])/(v[i+1]-v[i]),1LL*(x[i+1]-x[i])*ksm(v[i+1]-v[i])%mod};
	}
	std::sort(a+1,a+pos+1);
	tr.build(1,n,1);
	int ans=0;
	for(int i=1;i<=pos;++i)
	{
		int orig=tr.ask();
		int id=a[i].x,s=a[i].a,t=a[i].b;
		(t?(s?M[id+1].d:M[id+1].b):(s?M[id+1].c:M[id+1].a))=0;
		tr.upd(id+1,1,n,1);
		add(ans,1LL*(orig-tr.ask()+mod)*a[i].coef%mod);
	}
	printf("%d\n",ans);
	return 0;
}