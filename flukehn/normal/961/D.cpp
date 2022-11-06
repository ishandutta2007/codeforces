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
int n,vis[N];
pii a[N];
pii b[N];
int tot;
bool jud(){
	//b
	if(tot<=2)return 1;
	int A,B;
	A=b[2].fi-b[1].fi;
	B=b[2].se-b[1].se;
	rep(i,3,tot){
		int C=b[i].fi-b[1].fi,D=b[i].se-b[1].se;
		if(1ll*A*D!=1ll*B*C)return 0;
	}
	return 1;
}
bool check(){
	if(n<=4)return 1;
	debug("2: %d %d\n",a[2].fi,a[2].se);
	int A,B;
	tot=0;
	A=a[2].fi-a[1].fi;
	B=a[2].se-a[1].se;
	memset(vis,0,sizeof vis);
	rep(i,3,n){
		int C=a[i].fi-a[1].fi,D=a[i].se-a[1].se;
		if(1ll*A*D!=1ll*B*C)b[++tot]=a[i];
		else{
			debug("F : %d %d\n",a[i].fi,a[i].se);
			vis[i]=1;
		}
	}
	
	if(jud())return 1;
	debug("ok\n");
	rep(i,3,n)if(!vis[i]){swap(a[i],a[2]);break;}
	
	tot=0;
	A=a[2].fi-a[1].fi,B=a[2].se-a[1].se;
	debug("2: %d %d\n",a[2].fi,a[2].se);
	rep(i,3,n){
		int C=a[i].fi-a[1].fi,D=a[i].se-a[1].se;
		if(1ll*A*D!=1ll*B*C)b[++tot]=a[i];
		else{
			debug("F : %d %d\n",a[i].fi,a[i].se);
		}
	}
	return jud();
}
int main(){
#ifdef flukehn
	freopen("1.in","r",stdin);
#endif
	in,n;
	rep(i,1,n)in,a[i].fi,a[i].se;
	rep(i,1,100){
		random_shuffle(a+1,a+n+1);
	if(check()){out,"YES\n";return 0;}
	}
	debug("%d %d\n",a[1].fi,a[1].se);
	out,"NO\n";
}