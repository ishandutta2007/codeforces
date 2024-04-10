#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define foe(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
#ifdef flukehn
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
typedef double db;
typedef long long ll;
typedef long double lf;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int inf=~0u>>1,mo=1e9+7;
template<typename T>inline bool upmx(T&a,const T&b){return a<b?a=b,1:0;}
template<typename T>inline bool upmn(T&a,const T&b){return a>b?a=b,1:0;}
template<typename T>inline T gcd(T a,T b){while(b)a%=b,swap(a,b);return a;}
inline int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
#define I inline
struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define RX x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){db u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;char t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int&x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char&x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(db&x){RX;RL;RT}I OP db(){db x;TR}I Fr&OP,(lf&x){RX;RL;RT}I OP lf()
{lf x;TR}I Fr&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){db t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(db x,int y){WL;RT}I Fw&OP()(lf x,int y){WL;RT}};Fw<Cp>out;
const int N=1e5+11;
//#define lf double
const lf eps=1e-15;
int n,w;
int x[N],v[N];
pii a[N];
int f[N];
lf C[2*N];int tot=0;
int c[N*2];
void add(int x){
	for(;x<=n;x+=x&-x)c[x]++;
}
int query(int x){
	int r=0;
	for(;x;x-=x&-x)r+=c[x];
	return r;
}
struct Po{
	lf x,y;
	//int f;
	int yy;
	bool operator<(const Po&t)const{
		return abs(x-t.x)>eps?x<t.x:yy<t.yy;
	}
}e[2*N];
int cmp(const Po&a,const Po&b){
	return a.y<b.y;
}
int main(){
#ifdef flukehn
	freopen(".in","r",stdin);
#endif
	in,n,w;
	rep(i,1,n)in,x[i],v[i];
	if(!w){
		rep(i,1,n){
			int r=gcd(x[i],v[i]);
			a[i]=mp(x[i]/r,v[i]/r);
		}
		sort(a+1,a+n+1);
		rep(i,1,n){
			if(a[i]==a[i-1])f[i]=f[i-1]+1;
		}
		ll ans=0;
		rep(i,1,n)ans+=f[i];
		out,ans;
		return 0;
	}
	rep(i,1,n){
		lf a=(lf)1/x[i],b=(lf)v[i]/x[i]/w;
		e[i]=(Po){a+b,a-b,0};
		//debug("%Lf %Lf\n",a+b,a-b);
		//e[++tot]=(Po){a,b,1};
		//C[i]=e[i].y;
	}
	//sort(C+1,C+n+1);
	sort(e+1,e+n+1,cmp);
	int t=1;
	e[1].yy=1;
	rep(i,2,n){
		if(abs(e[i].y-e[i-1].y)>eps)e[i].yy=++t;
		else e[i].yy=t;
	}
	/*rep(i,1,n){
		while(abs(C[t]-e[i].y)>eps)++t;
		e[i].yy=t;
	}*/
	sort(e+1,e+n+1);
	ll ans=0;
	rep(i,1,n){
		int f=e[i].yy;
		//f=n-f+1;
		ans+=query(f);
		add(f);
		//debug("%Lf %Lf\n",e[i].x,e[i].y);
		//debug("%d %lld\n",f,ans);
	}
	out,ans;
}