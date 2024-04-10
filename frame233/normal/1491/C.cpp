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

const int N=5005;
ll a[N],n,d[N];
void MAIN()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		ans+=a[i]-1;
		if(a[i]==1)continue;
		memset(d,0,sizeof(d));
		++d[i+2];
		if(i+a[i]+1<=n)--d[i+a[i]+1];
		for(int j=i+1;j<=n;++j)
		{
			d[j]+=d[j-1];
			ll to=max(0LL,a[j]-d[j]);
			if(j+to+1<=n)++d[j+to+1];
			if(j+a[j]+1<=n)--d[j+a[j]+1];
			if(a[j]-d[j]<0)d[j+1]+=d[j]-a[j],d[j+2]-=d[j]-a[j];
			a[j]=max(1LL,a[j]-d[j]);
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}