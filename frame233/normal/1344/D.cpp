// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<int,int> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
int n;
ll k;
ll a[N];
Finline ll D(ll x,ll b)
{
	return -3*b*b-3*b-1+a[x];
}
ll tmp;
ll ans[N];
bool b[N];
bool check(ll x)
{
	ll cnt=0;
	for(int i=1;i<=n;++i)
	{
		ll l=0,r=a[i]-1;
		while(l<r)
		{
			ll mid=(l+r+1)>>1;
			if(D(i,mid)>x) l=mid;
			else r=mid-1;
		}
		if(D(i,l)>x) cnt+=l+1,ans[i]=l+1;
		else ans[i]=l;
		b[i]=l+1<a[i]&&D(i,l+1)==x;
	}
	tmp=cnt;
	return cnt<=k;
}
signed main()
{
	read(n,k);
	for(int i=1;i<=n;++i) read(a[i]);
	ll l=-4e18,r=4e18;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	check(l);
	k-=tmp;
	for(int i=1;i<=n;++i)
	{
		if(k&&b[i])
		{
			--k;
			++ans[i];
		}
	}
	for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}