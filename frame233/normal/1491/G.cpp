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
int a[N],n;
bool vis[N];
std::vector<pi> ans;
void solve(const std::vector<int> &a,const std::vector<int> &b)
{
	ans.pb({a.back(),b.back()});
	for(int i=0;i+1<SZ(b);++i)ans.pb({a.back(),b[i]});
	for(int i=0;i+1<SZ(a);++i)ans.pb({b.back(),a[i]});
	ans.pb({a.back(),b.back()});
}
void solve(const std::vector<int> &a)
{
	if(SZ(a)==2)
	{
		int x=0;
		for(int i=1;i<=n;++i)if(std::find(a.begin(),a.end(),i)==a.end())x=i;
		ans.pb({a[0],x}),ans.pb({a[1],x}),ans.pb({a[0],x});
		return;
	}
	ans.pb({a.back(),a[0]});
	for(int i=1;i+2<SZ(a);++i)ans.pb({a.back(),a[i]});
	ans.pb({a[SZ(a)-2],a[0]}),ans.pb({a[SZ(a)-2],a.back()}),ans.pb({a[0],a.back()});
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	std::vector<std::vector<int>> v;
	for(int i=1;i<=n;++i)if(!vis[i])
	{
		if(a[i]==i)continue;
		std::vector<int> qwq;
		for(int cur=i;!vis[cur];cur=a[cur])vis[cur]=true,qwq.pb(cur);
		v.pb(qwq);
	}
	for(int i=0;i+1<SZ(v);i+=2)solve(v[i],v[i+1]);
	if(SZ(v)&1)solve(v.back());
	printf("%d\n",SZ(ans));
	for(auto [x,y]:ans)printf("%d %d\n",x,y);
	return 0;
}