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

const int N=3005;
std::vector<int> v[N];
ll dp[N<<1][N],sum[N];
int node_cnt,k;
int solve(int l,int r)
{
	int cur=++node_cnt;
	if(l==r)
	{
		ll qwq=0;
		for(int i=0;i<k&&i<SZ(v[l]);++i) qwq+=v[l][i],dp[cur][i+1]=qwq;
		return cur;
	}
	int mid=(l+r)>>1;
	int ls=solve(l,mid),rs=solve(mid+1,r);
	for(int i=l;i<=mid;++i) for(int j=k;j>=SZ(v[i]);--j) chmax(dp[rs][j],dp[rs][j-SZ(v[i])]+sum[i]);
	for(int i=mid+1;i<=r;++i) for(int j=k;j>=SZ(v[i]);--j) chmax(dp[ls][j],dp[ls][j-SZ(v[i])]+sum[i]);
	for(int i=0;i<=k;++i) dp[cur][i]=max(dp[ls][i],dp[rs][i]);
	return cur;
}
int main()
{
	int n;read(n,k);
	for(int i=1;i<=n;++i)
	{
		int m;read(m);
		v[i].resize(m);
		for(auto &&it:v[i]) read(it),sum[i]+=it;
	}
	int rt=solve(1,n);
	printf("%lld\n",dp[rt][k]);
	return 0;
}