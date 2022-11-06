#include<bits/stdc++.h>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef std::pair<int,int> pii;

#define xx first
#define yy second

template<typename T> inline T max(T a,T b){return a>b?a:b;}
template<typename T> inline T min(T a,T b){return a<b?a:b;}
template<typename T> inline T abs(T a){return a>0?a:-a;}
template<typename T> inline bool repr(T &a,T b){return a<b?a=b,1:0;}
template<typename T> inline bool repl(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline T gcd(T a,T b){T t;if(a<b){while(a){t=a;a=b%a;b=t;}return b;}else{while(b){t=b;b=a%b;a=t;}return a;}}
template<typename T> inline T sqr(T x){return x*x;}
#define mp(a,b) std::make_pair(a,b)
#define pb push_back
#define I inline
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof(x.end())i=x.begin();i!=x.end();++i)

struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define RX x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;char t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int&x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char&x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf&x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf&x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;

#define y1 yy1

const int N=1007,inf=0x3f3f3f3f;

int n,m,k,x1,y1,x2,y2,dis[N][N],fl[N][N],fr[N][N],fu[N][N],fd[N][N];
char s[N][N];
pii q[N*N];

inline void remove(int x,int y)
{
	fl[x][y]=x-1;
	fr[x][y]=x+1;
	fu[x][y]=y-1;
	fd[x][y]=y+1;
}

int main()
{
	mset(dis,0x3f);
	in,n,m,k;
	fo1(i,n)in,s[i]+1;
	in,x1,y1,x2,y2;
	if(x1==x2&&y1==y2)return puts("0"),0;
	int qe=0;
	q[qe++]=mp(x1,y1);
	dis[x1][y1]=0;
	remove(x1,y1);
	fo(i,0,n+1)fo(j,0,m+1)fl[i][j]=s[i][j]=='.'?i:0;
	fo(i,0,n+1)fo(j,0,m+1)fr[i][j]=s[i][j]=='.'?i:n+1;
	fo(i,0,n+1)fo(j,0,m+1)fu[i][j]=s[i][j]=='.'?j:0;
	fo(i,0,n+1)fo(j,0,m+1)fd[i][j]=s[i][j]=='.'?j:m+1;
	for(int i=0;i<qe;i++)
	{
		int x=q[i].xx,y=q[i].yy,d=dis[x][y];
		//out,x,' ',y,' ',d,'\n';
		for(int j=x;;j=fl[j][y])
		{
			for(;fl[j][y]!=j;j=fl[j][y]=fl[fl[j][y]][y]);
			if(!j||x-j>k)break;
			dis[j][y]=d+1;
			q[qe++]=mp(j,y);
			remove(j,y);
		}
		for(int j=x;;j=fr[j][y])
		{
			for(;fr[j][y]!=j;j=fr[j][y]=fr[fr[j][y]][y]);
			if(j>n||j-x>k)break;
			dis[j][y]=d+1;
			q[qe++]=mp(j,y);
			remove(j,y);
		}
		for(int j=y;;j=fu[x][j])
		{
			for(;fu[x][j]!=j;j=fu[x][j]=fu[x][fu[x][j]]);
			if(!j||y-j>k)break;
			dis[x][j]=d+1;
			q[qe++]=mp(x,j);
			remove(x,j);
		}
		for(int j=y;;j=fd[x][j])
		{
			for(;fd[x][j]!=j;j=fd[x][j]=fd[x][fd[x][j]]);
			if(j>m||j-y>k)break;
			dis[x][j]=d+1;
			q[qe++]=mp(x,j);
			remove(x,j);
		}
	}
	out,dis[x2][y2]==inf?-1:dis[x2][y2],'\n';
}