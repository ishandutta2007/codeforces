// Author -- Frame

#include<cstdio>
#include<cstring>
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

const int N=500005;
template<typename _Tp>
class BIT{
public:
	_Tp c[N];
	Finline void add(int x,_Tp C){++x;for(;x<N;x+=lowbit(x))c[x]+=C;}
	Finline _Tp sum(int x){++x;_Tp ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
};
BIT<ll> tr;
int a[N],p[N],b[N];
ll maxx[N];
ll dp[N];
ll ans[N][2];
int mark[N];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	ll sum=0;
	for(int i=1;i<=n;++i) read(p[i]),sum+=p[i];
	int m;
	read(m);
	for(int i=1;i<=m;++i) read(b[i]),mark[b[i]]=i;
	for(int i=1;i<=n;++i)
	{
		if(p[i]>0) tr.add(a[i],p[i]);
		if(mark[a[i]])
		{
			ans[i][0]=tr.sum(a[i]);
			ans[i][1]=tr.sum(b[mark[a[i]]-1]);
		}
	}
	memset(maxx,-63,sizeof(maxx));
	maxx[0]=0;
	ll res=-1e18;
	for(int i=1;i<=n;++i)
	{
		if(mark[a[i]])
		{
			dp[i]=maxx[b[mark[a[i]]-1]]+ans[i][1]+p[i];
			chmax(maxx[a[i]],dp[i]-ans[i][0]);
			if(mark[a[i]]==m) chmax(res,dp[i]-ans[i][0]);
		}
	}
	if(res<-1e17) printf("NO\n");
	else printf("YES\n%lld\n",sum-(res+tr.sum(b[m])));
	return 0;
}