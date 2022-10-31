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

const int N=500005;
int a[N],b[N],c[N],id[N<<1];
ll d[N];
void exgcd(ll &x,ll &y,ll a,ll b)
{
	if(!b)return x=1,y=0,void();
	exgcd(y,x,b,a%b),y-=a/b*x;
}
int main()
{
	int n,m;ll k;read(n,m,k);
	for(int i=0;i<n;++i)read(a[i]);
	for(int i=0;i<m;++i)read(b[i]);
	if(n>m)std::swap(a,b),std::swap(n,m);
	memset(id,255,sizeof(id));
	for(int i=0;i<m;++i)id[b[i]]=i;
	for(int i=0;i<n;++i)c[i]=id[a[i]];
	int g=gcd(n,m);
	ll L=1LL*n/g*m;
	for(int i=0;i<n;++i)if(~c[i])
	{
		ll a=i,b=c[i],x,y;
		if((b-a)%g){d[i]=1e18;continue;}
		exgcd(x,y,n,m),y=-y;
		x*=(b-a)/g,y*=(b-a)/g;
		d[i]=((x*n+a)%L+L)%L;
	}
	ll l=0,r=1e18;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		ll all=mid/L,ans=mid,R=mid%L;
		for(int i=0;i<n;++i)if(~c[i]&&d[i]<1e18)ans-=all,ans-=R>d[i];
		if(ans>=k)r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}