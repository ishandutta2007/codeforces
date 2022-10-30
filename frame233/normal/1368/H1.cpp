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
char s[N];
int L[N],R[N],U[N],D[N];
int dp[N][2];
void get(int *a)
{
	int l=read_str(s+1);
	for(int i=1;i<=l;++i) a[i]=s[i]=='R';
}
int main()
{
	int n,m,q;read(n,m,q);
	get(L),get(R),get(U),get(D);
	int ans=inf;
	for(int __=0;__<2;++__)
	{
		if(__) std::swap(n,m),std::swap(L,U),std::swap(R,D);
		int qwq=std::accumulate(U+1,U+m+1,0);
		dp[0][0]=qwq,dp[0][1]=m-qwq;
		for(int i=1;i<=n;++i)
		{
			dp[i][0]=min(dp[i-1][0],dp[i-1][1]+m)+L[i]+R[i];
			dp[i][1]=min(dp[i-1][0]+m,dp[i-1][1])+2-L[i]-R[i];
		}
		qwq=std::accumulate(D+1,D+m+1,0);
		chmin(ans,min(dp[n][0]+qwq,dp[n][1]+m-qwq));
	}
	printf("%d\n",ans);
	return 0;
}