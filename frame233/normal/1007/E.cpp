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
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=205;
ll a[N],b[N],c[N],sa[N],sb[N],sc[N],f[N][N][2],g[N][N][2];
int main()
{
	int n,t,s;read(n,t,s);
	for(int i=1;i<=n;++i)read(a[i],b[i],c[i]);
	a[n+1]=1e18,c[n+1]=1e18;for(int i=1;i<=n+1;++i)sa[i]=a[i]+sa[i-1],sb[i]=b[i]+sb[i-1],sc[i]=c[i]+sc[i-1];
	memset(f,63,sizeof(f)),memset(g,63,sizeof(g));
	for(int j=0;j<=t;++j)for(int k=0;k<2;++k)f[0][j][k]=g[0][j][k]=0;
	for(int i=1;i<=n+1;++i)for(int j=0;j<=t;++j)for(int k=0;k<2;++k)
	{
		if(f[i-1][j][k]<INF&&k*a[i]+j*b[i]<=c[i])
		{
			chmin(f[i][j][k],f[i-1][j][k]);
			ll need=(k*sa[i-1]+j*sb[i-1]+s-1)/s;
			if(need*s<=k*sa[i]+j*sb[i])chmin(g[i][j][k],need);
		}
		for(int r=0;r<j;++r)if(g[i][r][k]<INF&&f[i-1][j-r][0]<INF)
		{
			ll qwq=k*sa[i]+r*sb[i]-s*g[i][r][k];
			ll need=(max(qwq+(j-r)*b[i]-c[i],0LL)+s-1)/s;
			if(need*s<=qwq)
			{
				chmin(f[i][j][k],g[i][r][k]+need+f[i-1][j-r][0]);
				ll NEED=((j-r)*sb[i-1]+s-1)/s;
				if(NEED*s<=(j-r)*sb[i]+qwq+c[i]-need*s)chmin(g[i][j][k],g[i][r][k]+need+NEED);
			}
		}
	}
	printf("%lld\n",f[n+1][t][1]);
	return 0;
}