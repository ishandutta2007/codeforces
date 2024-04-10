// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

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

const int N=100005;
ll h[N],a[N];
int n,m,k,p;
std::map<int,int> mp;
bool check(ll o)
{
	mp.clear();
	for(int i=1;i<=m;++i) mp[i]=k;
	for(int i=1;i<=n;++i)
	{
		ll lim=o-a[i];
		int cur=m;
		while(cur>1)
		{
			int l=1,r=cur;
			while(l<r)
			{
				int mid=(l+r+1)>>1;
				if(lim-1ll*a[i]*(cur-mid)<0) l=mid;
				else r=mid-1;
			}
			lim-=1ll*a[i]*(cur-l);
			while(lim<0)
			{
				auto it=mp.upper_bound(l);
				if(it==mp.end()) return false;
				if(!--it->second) mp.erase(it);
				lim+=p;
			}
			cur=l;
		}
		lim-=h[i];
		while(lim<0)
		{
			auto it=mp.begin();
			if(it==mp.end()) return false;
			if(!--it->second) mp.erase(it);
			lim+=p;
		}
	}
	return true;
}
int main()
{
	read(n,m,k,p);
	ll l=0,r=1e13;
	for(int i=1;i<=n;++i)
	{
		read(h[i],a[i]);
		chmax(l,a[i]);
	}
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}