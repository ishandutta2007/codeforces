// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
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
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=400005;
struct node{
	int a,t;
}a[N];
std::vector<int> v[N];
int t[N];
std::multiset<int> S;
int main()
{
	int n;
	read(n);
	int pos=0;
	for(int i=1;i<=n;++i)
	{
		read(a[i].a);
		t[++pos]=a[i].a;
	}
	for(int i=1;i<=n;++i) read(a[i].t);
	std::sort(t+1,t+pos+1);
	pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=n;++i)
	{
		v[std::lower_bound(t+1,t+pos+1,a[i].a)-t].push_back(a[i].t);
	}
	for(int i=pos+1;i<=pos+n;++i) t[i]=t[i-1]+1;
	pos+=n;
	ll ans=0,sum=0;
	for(int i=1;i<=pos;++i)
	{
		for(auto it:v[i]) S.insert(it),sum+=it;
		int cnt=t[i+1]-t[i];
		int qwq=0;
		while(!S.empty()&&cnt)
		{
			ans+=qwq*(*--S.end());
			sum-=*--S.end();
			S.erase(--S.end());
			--cnt;
			++qwq;
		}
		ans+=sum*(t[i+1]-t[i]);
	}
	printf("%lld\n",ans);
	return 0;
}