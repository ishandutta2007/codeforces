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


inline bool isp(int n){
    if(n<2)return 0;
    if(n==2)return 1;
    for(int i=2;i*i<=n;++i){
        if(n%i==0)return 0;
    }
    return 1;
}
const int N=10011;
int tot,a[N],b[N],f[N];
void bf(){
	f[0]=0,f[1]=0;
	For(i,2,N){
		if(isp(i))f[i]=1;
		else {
			rep(j,2,i)if(i%j==0){f[i]=i/j;break;}
			//f[i]=inf;
			debug("f[%d]=%d\n",i,f[i]);
			rep(j,2,i-2){
				upmn(f[i],f[i-j]+f[j]);
			}
		}
	}
}

int S(int n){
	if(n<N)return f[n];
	if(isp(n))return 1;
	if(n&1){
		if(isp(n-2))return 2;
		else return 3;
	}
	else return 2;
}

int main(){
	bf();
	int n=in;
	out,S(n),'\n';
}