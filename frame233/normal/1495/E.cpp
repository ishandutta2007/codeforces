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

const int N=200005;
int p[N],k[N],b[N],w[N],a[5000005],t[5000005],orig[5000005];
ll seed,base;
inline int get()
{
	ll ret=seed;
	seed=(seed*base+233)%1000000007;
	return ret;
}
int main()
{
	int n,m;read(n,m);
	for(int i=1;i<=m;++i)read(p[i],k[i],b[i],w[i]);
	for(int i=1;i<=m;++i)
	{
		seed=b[i],base=w[i];
		for(int j=p[i-1]+1;j<=p[i];++j)t[j]=get()%2,a[j]=get()%k[i]+1,orig[j]=a[j];
	}
	ll s0=0,s1=0;
	for(int i=1;i<=n;++i)(t[i]?s1:s0)+=a[i];
	if(s1<s0||(s0==s1&&t[1]==1))
	{
		std::swap(s0,s1);
		for(int i=1;i<=n;++i)t[i]=!t[i];
	}
	int cur=1;
	if(t[1])
	{
		--a[1];
		while(cur<=n&&t[cur]==1)++cur;
	}
	ll sum=0,tp;
	for(int i=cur;i<=n;++i)
	{
		if(!t[i])sum+=a[i],a[i]=0;
		else tp=min(sum,(ll)a[i]),sum-=tp,a[i]-=tp;
	}
	for(int i=1;i<=n;++i)if(t[i]==1)tp=min(sum,(ll)a[i]),sum-=tp,a[i]-=tp;
	ll ans=1;for(int i=1;i<=n;++i)ans=ans*((((orig[i]-a[i])^(1LL*i*i))+1)%1000000007)%1000000007;
	printf("%lld\n",ans);
	return 0;
}