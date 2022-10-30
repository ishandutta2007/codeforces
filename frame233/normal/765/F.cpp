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
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=100005;
int a[N],b[N],c[N],ans[N*3],t[N],val[N<<2],n,q,M;
std::vector<pi> v[N];
void add(int x,int C){for(;x;x-=lowbit(x))chmin(c[x],C);}
int ask(int x){int ans=inf;for(;x<N;x+=lowbit(x))chmin(ans,c[x]);return ans;}
void build()
{
	memset(val,0,sizeof(val));
	for(M=1;M<=n+1;M<<=1);
}
void upd(int x,int C)
{
	chmax(val[x+=M],C);
	for(x>>=1;x;x>>=1)val[x]=max(val[x<<1],val[x<<1|1]);
}
int ask(int l,int r)
{
	if(l>r) return 0;
	int ans=0;
	for(int s=l+M-1,t=r+M+1;s^t^1;s>>=1,t>>=1)
	{
		if(~s&1) chmax(ans,val[s^1]);
		if(t&1) chmax(ans,val[t^1]);
	}
	return ans;
}
int main()
{
	memset(ans,63,sizeof(ans));
	read(n);int x,y;
	for(int i=1;i<=n;++i) read(a[i]);
	read(q);
	for(int i=1;i<=q;++i) read(x,y),v[y].pb({x,i});
	for(int _=0;_<2;++_)
	{
		memset(c,63,sizeof(c)),build();
		for(int i=1;i<=n;++i) t[i]=a[i];
		std::sort(t+1,t+n+1);
		int pos=std::unique(t+1,t+n+1)-t-1;
		for(int i=1;i<=n;++i) b[i]=std::lower_bound(t+1,t+pos+1,a[i])-t;
		upd(b[1],1);
		for(int i=2;i<=n;++i)
		{
			int limit=0,R=std::upper_bound(t+1,t+pos+1,a[i])-t-1;
			while(limit<=a[i])
			{
				int j=ask(std::lower_bound(t+1,t+pos+1,limit)-t,R);
				if(!j) break;
				add(j,a[i]-a[j]),limit=(a[i]+a[j])/2+1;
			}
			for(auto it:v[i]) chmin(ans[it.second],ask(it.first));
			upd(b[i],i);
		}
		for(int i=1;i<=n;++i) a[i]=1e9-a[i];
	}
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}