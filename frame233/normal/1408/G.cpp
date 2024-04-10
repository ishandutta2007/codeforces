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

const int N=1505;
const int mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
struct edge{
	int x,y,w;
	inline bool operator < (const edge &o)const
	{
		return w<o.w;
	}
}c[N*N];
int fa[N],siz[N],cnt[N];
int dp[N][N],tmp[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
	int n;read(n);
	int x,pos=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			read(x);
			if(i<j) c[++pos]=(edge){i,j,x};
		}
	}
	for(int i=1;i<=n;++i) fa[i]=i,siz[i]=1,cnt[i]=1,dp[i][1]=1;
	std::sort(c+1,c+pos+1);
	for(int i=1;i<=pos;++i)
	{
		int x=c[i].x,y=c[i].y;
		int a=find(x),b=find(y);
		if(a!=b)
		{
			memset(tmp,0,(siz[a]+siz[b]+3)<<2);
			for(int j=0;j<=siz[a];++j) for(int k=0;k<=siz[b];++k) add(tmp[j+k],1ll*dp[a][j]*dp[b][k]%mod);
			siz[a]+=siz[b];
			cnt[a]+=cnt[b];
			fa[b]=a;
			memcpy(dp[a],tmp,(siz[a]+3)<<2);
		}
		a=find(a),b=find(b);
		if(++cnt[a]==siz[a]*siz[a]) ++dp[a][1];
		if(++cnt[b]==siz[b]*siz[b]) ++dp[b][1];
	}
	int rt=find(1);
	for(int i=1;i<=n;++i) printf("%d%c",dp[rt][i]," \n"[i==n]);
	return 0;
}