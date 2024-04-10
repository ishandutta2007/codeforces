// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define Finline __inline__ __attribute__ ((always_inline))
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

Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
int n,m,maxx;
int a[N],b[N],dp[N];
bool check(int mid)
{
	if(mid>=maxx) return true;
	memset(dp,-63,sizeof(dp));
	dp[1]=a[1];
	for(int i=2;i<=n;++i)
	{
		if(dp[i-1]+1>=a[i]) chmax(dp[i],a[i]+mid);
		if(dp[i-1]+1>=a[i]-mid) chmax(dp[i],a[i]);
		if(dp[i-2]+1>=a[i]-mid) chmax(dp[i],a[i-1]+mid);
	}
	if(dp[n]+1>=m+a[1]-mid) return true;
	memset(dp,-63,sizeof(dp));
	if(mid<=(a[2]-a[1])) return false;
	dp[2]=a[1]+mid;
	for(int i=3;i<=n;++i)
	{
		if(dp[i-1]+1>=a[i]) chmax(dp[i],a[i]+mid);
		if(dp[i-1]+1>=a[i]-mid) chmax(dp[i],a[i]);
		if(dp[i-2]+1>=a[i]-mid) chmax(dp[i],a[i-1]+mid);
	}
	return dp[n]+1>=m+a[2]-mid;
}
int main()
{
	read(m,n);
	for(int i=1;i<=n;++i) read(a[i]),--a[i];
	std::sort(a+1,a+n+1);
	int id=1;a[0]=a[n]-m;
	for(int i=1;i<=n;++i) if(a[i]-a[i-1]>a[id]-a[id-1]) id=i;
	maxx=a[id]-a[id-1]-1;
	int val=a[id];for(int i=1;i<=n;++i) a[i]=(a[i]-val+m)%m;
	a[0]=0;std::sort(a+1,a+n+1);
	val=a[2];for(int i=1;i<=n;++i) b[i]=(a[i]-val+m)%m;
	std::sort(b+1,b+n+1);
	int l=0,r=maxx;
	while(l<r)
	{
		 int mid=(l+r)>>1;
		 if(check(mid)) r=mid;
		 else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}