// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
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
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=400005;
int a[N];
int cnt[N<<1];
int sum[N<<1];
int suf[N<<1];
void MAIN()
{
	int n,k;
	read(n,k);
	for(int i=0;i<=(k<<1)+1;++i) cnt[i]=sum[i]=suf[i]=0;
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=n>>1;++i) ++cnt[a[i]+a[n-i+1]],++sum[max(a[i],a[n-i+1])],++suf[min(a[i],a[n-i+1])];
	for(int i=1;i<=k<<1;++i) sum[i]+=sum[i-1];
	for(int i=k<<1;i>=0;--i) suf[i]+=suf[i+1];
	int ans=inf;
	for(int i=1;i<=k<<1;++i)
	{
		chmin(ans,(n>>1)-cnt[i]+(i>k?sum[i-k-1]:0)+suf[i]);
	}
	printf("%d\n",ans);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}