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

const int N=1000005;
char s[N];
int n,dp[N];
int sum[N];
int a[N],p;
Finline int calc(int l,int r){return l<0?inf:(l>r?0:sum[r]-sum[l-1]);}
bool check(int mid)
{
	memset(dp,-63,(p+3)<<2);
	dp[0]=0;
	for(int i=1;i<=p;++i)
	{
		if(calc(dp[i-1]+1,a[i]-1)<=0) chmax(dp[i],a[i]+mid);
		if(calc(dp[i-1]+1,a[i]-mid-1)<=0) chmax(dp[i],a[i]);
		if(i>=2&&calc(dp[i-2]+1,a[i]-mid-1)<=0) chmax(dp[i],a[i-1]+mid);
	}
	return calc(dp[p]+1,n)<=0;
}
int main()
{
	read(n);
	read_str(s+1);
	int cB=0,cD=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='*') ++cB;
		else if(s[i]=='P') ++cD;
	}
	if(cD==1)
	{
		int pos=0;
		for(int i=1;i<=n;++i) if(s[i]=='P') pos=i;
		int c1=0,c2=0,p1=0,p2=0;
		for(int i=pos-1;i>=1;--i) if(s[i]=='*') ++c1,p1=pos-i;
		for(int i=pos+1;i<=n;++i) if(s[i]=='*') ++c2,p2=i-pos;
		if(c1!=c2)
		{
			if(c1>c2) printf("%d %d\n",c1,p1);
			else printf("%d %d\n",c2,p2);
		}
		else printf("%d %d\n",c1,min(p1,p2));
		return 0;
	}
	printf("%d ",cB);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+(s[i]=='*');
	for(int i=1;i<=n;++i) if(s[i]=='P') a[++p]=i;
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}