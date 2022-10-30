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

const int N=200005;
std::vector<int> d[N];
std::set<int> S;
int cnt[N];
int main()
{
	for(int i=1;i<N;++i) for(int j=i;j<N;j+=i) d[j].pb(i);
	int n,m;read(n,m);
	ll A,B;read(A,B);
	int l=1,r=0;
	for(int x1=1;x1<=n;++x1)
	{
		int L=min(max(1ll,(A+x1-1)/x1),(ll)m+1),R=min((ll)m,B/x1);
		while(r<R)
		{
			++r;
			for(auto it:d[r]) if(++cnt[it]==1) S.insert(it);
		}
		while(r>R)
		{
			for(auto it:d[r]) if(!--cnt[it]) S.erase(it);
			--r;
		}
		while(l>L)
		{
			--l;
			for(auto it:d[l]) if(++cnt[it]==1) S.insert(it);
		}
		while(l<L)
		{
			for(auto it:d[l]) if(!--cnt[it]) S.erase(it);
			++l;
		}
		bool flag=false;
		for(auto a:d[x1])
		{
			auto it=S.upper_bound(a);
			if(it!=S.end())
			{
				int b=*it;
				ll x2=1ll*b*(x1/a);
				ll y1=1ll*((L+b-1)/b)*b;
				ll y2=1ll*(y1/b)*a;
				if(x2<=n)
				{
					printf("%d %lld %lld %lld\n",x1,y1,x2,y2);
					flag=true;
					break;
				}
			}
		}
		if(!flag) puts("-1");
	}
	return 0;
}