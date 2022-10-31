// Author -- Frame
 
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
 
Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
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
 
const int N=1000005;
ll dp[N],a[N];
int main()
{
	int n;ll r1,r2,r3,d;read(n,r1,r2,r3,d);
	for(int i=1;i<=n;++i) read(a[i]);
	dp[0]=-d;
	for(int i=1;i<=n;++i)
	{
		dp[i]=dp[i-1]+d+r1*a[i]+r3;
		if(i>1) chmin(dp[i],dp[i-2]+d+d+d+d+min(r1*(a[i-1]+1),r2)+min(min(r1*(a[i]+1),r2)+r1,r1*a[i]+r3)+r1);
	}
	ll ans=dp[n];
	chmin(ans,dp[n-2]+d+d+d+min(r1*(a[n-1]+1),r2)+r1*a[n]+r3+r1);
	chmin(ans,dp[n-1]+min(r2,a[n]*r1+r1)+r1+d+d+d);
	printf("%lld\n",ans);
	return 0;
}