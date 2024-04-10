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

const int N=300005;
ll X[N],Y[N],x[N],y[N];
int main()
{
	int n;read(n);
	for(int i=1;i<=n;++i)read(x[i],y[i]),X[i]=x[i],Y[i]=y[i];
	std::sort(x+1,x+n+1),std::sort(y+1,y+n+1);
	int mid=(n+1)/2;
	ll ans=0;for(int i=1;i<=n/2;++i)ans+=x[n-i+1]+y[n-i+1]-x[i]-y[i];
	ll dx=abs(x[mid+1]-x[mid]),dy=abs(y[mid+1]-y[mid]);
	if(n&1)chmin(dx,abs(x[mid]-x[mid-1])),chmin(dy,abs(y[mid]-y[mid-1]));
	bool flag=false,t0=false,t1=false;
	for(int i=1;i<=n;++i)flag|=X[i]==x[mid]&&Y[i]==y[mid];
	if(n&1)for(int i=1;i<=n;++i)t0|=X[i]<x[mid]&&Y[i]<y[mid],t1|=X[i]>x[mid]&&Y[i]<y[mid];
	else for(int i=1;i<=n;++i)t0|=X[i]<=x[mid]&&Y[i]<=y[mid],t1|=X[i]>x[mid]&&Y[i]<=y[mid];
	if((n%2==0||flag)&&t0&&t1)ans-=min(dx,dy);
	printf("%lld\n",2LL*ans);
	return 0;
}