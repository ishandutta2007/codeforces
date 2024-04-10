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

const int N=505;
int ask(std::vector<int> S,std::vector<int> T,int u)
{
	printf("%d\n",SZ(S));
	for(auto it:S) printf("%d ",it);
	printf("\n%d\n",SZ(T));
	for(auto it:T) printf("%d ",it);
	printf("\n%d\n",u);fflush(stdout);
	int x;read(x);return x;
}
int siz[N],t[N],cur;
std::vector<int> rest;
std::vector<pi> E;
bool mark[N];
void solve(int l,int r)
{
	if(l>r) return;
	int ans=ask({1},{rest.begin()+l,rest.begin()+r+1},cur);
	if(!ans) return;
	if(l==r) return mark[l]=true,E.pb({rest[l],cur}),void();
	int mid=(l+r)>>1;
	solve(l,mid),solve(mid+1,r);
}
int main()
{
	int n;read(n);
	std::vector<int> v(n-1);std::iota(v.begin(),v.end(),2);
	for(int i=2;i<=n;++i) siz[i]=ask({1},v,i),t[i]=i;
	std::sort(t+2,t+n+1,[&](int A,int B)->bool{return siz[A]<siz[B];});
	for(int _=2;_<=n;++_)
	{
		memset(mark,0,sizeof(mark));
		int i=cur=t[_];
		solve(0,SZ(rest)-1);
		std::vector<int> qwq={i};
		for(int i=0;i<SZ(rest);++i) if(!mark[i]) qwq.pb(rest[i]);
		rest=qwq;
	}
	for(auto it:rest) E.pb({1,it});
	printf("ANSWER\n");
	for(auto it:E) printf("%d %d\n",it.first,it.second);
	fflush(stdout);
	return 0;
}