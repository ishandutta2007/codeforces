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
void MAIN()
{
	ll n;read(n);
	ll l=1,r=n-1;
	std::vector<ll> v;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		v.pb(mid),l=mid+1;
	}
	std::reverse(v.begin(),v.end());
	ll cur=n;
	int cnt=0;
	for(int i=0;i<SZ(v);++i,++cnt)
	{
		if(i&1) cur+=v[i];
		else cur-=v[i];
	}
	assert(1<=cur&&cur<=n);
	printf("? %lld\n",cur);fflush(stdout);
	int x;read(x);
	l=1,r=n-1;
	ll ans=n;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(cnt&1) cur+=mid;
		else cur-=mid;
		++cnt;
		printf("? %lld\n",cur);fflush(stdout);
		read(x);
		if(x) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("= %lld\n",ans);fflush(stdout);
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}