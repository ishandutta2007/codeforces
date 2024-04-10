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
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
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

const int N=1000005;
char a[N],b[N],s[N],t[N<<1];
int va[N],vb[N];
struct BIT{
	ll c[N];
	Finline void add(int x,int C){++x;for(;x;x-=lowbit(x))c[x]+=C;}
	Finline ll sum(int x){++x;ll ans=0;for(;x<N;x+=lowbit(x))ans+=c[x];return ans;}
}tr1,tr2;
int qwq[N<<1];
void Z(char *s,int n,int *z)
{
	memset(z,0,(n+3)<<2);
	int l=0,r=0;
	for(int i=2;i<=n;++i)
	{
		if(i<=r) z[i]=min(r-i+1,z[i-l+1]);
		while(i+z[i]<=n&&s[i+z[i]]==s[z[i]+1]) ++z[i];
		if(i+z[i]-1>r) l=i,r=i+z[i]-1;
	}
}
int main()
{
	int n,m;
	read(n,m);
	read_str(a+1);
	read_str(b+1);
	read_str(s+1);
	for(int i=1;i<m;++i) t[i]=s[i];
	t[m]='#';
	for(int i=1;i<=n;++i) t[i+m]=a[i];
	Z(t,n+m,qwq);
	for(int i=1;i<=n;++i) va[i]=qwq[i+m];
	for(int i=m;i>=2;--i) t[m-i+1]=s[i];
	t[m]='#';
	for(int i=1;i<=n;++i) t[i+m]=b[n-i+1];
	Z(t,n+m,qwq);
	for(int i=1;i<=n;++i) vb[i]=qwq[m+n-i+1];
	for(int i=1;i<=n&&i<=m-2;++i)
	{
		tr1.add(vb[i],1);
		tr2.add(vb[i],vb[i]);
	}
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		if(i+m-2<=n)
		{
			tr1.add(vb[i+m-2],1);
			tr2.add(vb[i+m-2],vb[i+m-2]);
		}
		int cnt=tr1.sum(m-va[i]-1);
		ll sum=tr2.sum(m-va[i]-1);
		ans+=1ll*(va[i]-m+1)*cnt+sum;
		tr1.add(vb[i],-1);
		tr2.add(vb[i],-vb[i]);
	}
	printf("%lld\n",ans);
	return 0;
}