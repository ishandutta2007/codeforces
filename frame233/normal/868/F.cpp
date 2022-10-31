// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

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

const int N=100005;
int a[N];
ll f[N],g[N];
int pl,pr;
int cnt[N];
ll ans;
Finline void inc_r()
{
	++pr;
	ans+=cnt[a[pr]]++;
}
Finline void inc_l()
{
	ans-=--cnt[a[pl]];
	++pl;
}
Finline void dec_r()
{
	ans-=--cnt[a[pr]];
	--pr;
}
Finline void dec_l()
{
	--pl;
	ans+=cnt[a[pl]]++;
}
void solve(int L,int R,int l,int r)
{
	if(l>r) return;
	int mid=(l+r)>>1;
	while(pr>mid)
	{
		if(pl==pr+1) dec_l();
		dec_r();
	}
	while(pr<mid) inc_r();
	ll minn=1e18;
	int pos=0;
	for(int i=L;i<=R&&i<mid;++i)
	{
		while(pl<i+1) inc_l();
		while(pl>i+1) dec_l();
		ll tmp=g[i]+ans;
		if(tmp<minn)
		{
			minn=tmp;
			pos=i;
		}
	}
	f[mid]=minn;
	solve(L,pos,l,mid-1);
	solve(pos,R,mid+1,r);
}
int main()
{
	int n,k;
	read(n,k);
	for(int i=1;i<=n;++i) read(a[i]);
	memset(g,63,sizeof(g));
	g[0]=0;
	pl=1,pr=0;
	for(int i=1;i<=k;++i)
	{
		solve(0,n,0,n);
		memcpy(g,f,(n+3)<<3);
	}
	printf("%lld\n",f[n]);
	return 0;
}