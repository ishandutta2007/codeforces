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
#define heap(...) priority_queue<__VA_ARGS__,vector<__VA_ARGS__ >,greater<__VA_ARGS__ > > 
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
inline void admo(int&a,int b){a=(a+b>=mo?a+b-mo:a+b);}
inline void sumo(int&a,int b){a=(a-b<0?a-b+mo:a-b);}
template<typename T>inline bool upmx(T&a,const T&b){return a<b?a=b,1:0;}
template<typename T>inline bool upmn(T&a,const T&b){return a>b?a=b,1:0;}
template<typename T>inline T gcd(T a,T b){while(b)a%=b,swap(a,b);return a;}
inline int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
#define I inline
struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;

#define WI(S) if(x){if(x<0)P('-'),x=-x;char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){db t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(db x,int y){WL;RT}I Fw&OP()(lf x,int y){WL;RT}};Fw<Cp>out;
const int N=1e6+11;
void NO(){
	puts("Impossible");
	exit(0);
}
char s[N];
int u[N],c[N],d[N],t1,t2;
int n,m;
bool jud(int a,int b,int m,int n){
	return 1ll*a*n-b>=m && a-1ll*b*n<=m;
}
int cnt;
int main(){
#ifdef flukehn
	freopen(".in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.getline(s+1,N);
	debug("%s\n",s+1);
	n=strlen(s+1);
	int a=1,b=0,p=0,o;
	rep(i,2,n){
		if(s[i]=='+') p=1;
		else if(s[i]=='-')p=-1;
		else if(s[i]=='?'){
			u[++cnt]=p;
			if(p>0)++a;
			else ++b;
		}
		else if(isdigit(s[i])){
			o=i;break;
		}
	}
	for(;o<=n;++o)m=m*10+s[o]-'0';
	if(!jud(a,b,m,m))NO();
	int x=m;
	debug("%d %d %d %d\n",a,b,m,cnt);
	per(i,1,a){
		rep(j,1,m){
			if(jud(i-1,b,x-j,m)){
				c[i]=j;
				x-=j;
				break;
			}
		}
	}
	per(i,1,b){
		rep(j,1,m){
			if(jud(0,i-1,x+j,m)){
				d[i]=j;
				x+=j;
				break;
			}
		}
	}
	#ifdef flukehn
	rep(i,1,a)out,c[i],' ';
	out,'\n';
	rep(i,1,b)out,d[i],' ';
	out,'\n';
	rep(i,1,cnt)out,u[i],' ';
	out,'\n';
	#endif
	out,"Possible\n";
	t1=1;
	out,c[1],' ';
	rep(i,1,cnt){
		if(u[i]>0){
			out,"+ ",c[++t1],' ';
		}
		else{
			out,"- ",d[++t2],' ';
		}
	}
	out,"= ",m;
}