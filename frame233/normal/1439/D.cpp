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

const int N=505;
int mod;
struct FastMod{
	typedef __uint128_t LLL;
	ull b,m;
	void init(ull b){this->b=b,m=ull((LLL(1)<<64)/b);}
	inline ull operator()(ull a){
		ull r=a-(ull)((LLL(m)*a)>>64)*b;
		return r>=b?r-b:r;
	}
}M;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int f[N],g[N],dp1[N][N],dp2[N][N],C[N][N];
inline ll s(int x){return x*(x+1)/2;}
int main()
{
	int n,m;read(n,m,mod),M.init(mod);
	for(int i=0;i<N;++i) for(int j=C[i][0]=1;j<=i;++j) C[i][j]=C[i-1][j-1],add(C[i][j],C[i-1][j]);
	g[0]=1;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=i;++j)
		{
			int tmp=C[i-1][j-1],coef=M(M(1LL*g[j-1]*g[i-j])*tmp);
			add(f[i],M(M(M(1LL*f[j-1]*g[i-j]+1LL*g[j-1]*f[i-j])*(i+1))*tmp));
			add(f[i],M((s(j-1)+s(i-j))*coef));
			add(g[i],M(1LL*coef*(i+1)));
		}
	}
	dp2[0][0]=1;
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=m;++j)
		{
			add(dp1[i+1][j],dp1[i][j]),add(dp2[i+1][j],dp2[i][j]);
			for(int k=1;i+k<=n&&j+k<=m;++k)
			{
				int tmp=C[j+k][j];
				add(dp1[i+k+1][j+k],M(M(1LL*tmp*dp1[i][j])*g[k]));
				add(dp1[i+k+1][j+k],M(M(1LL*tmp*dp2[i][j])*f[k]));
				add(dp2[i+k+1][j+k],M(M(1LL*tmp*dp2[i][j])*g[k]));
			}
		}
	}
	printf("%d\n",dp1[n+1][m]);
	return 0;
}