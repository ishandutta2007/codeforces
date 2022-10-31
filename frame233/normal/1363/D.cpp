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
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=0x05ad13b4;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
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

const int N=1005;
std::vector<int> v[N];
char s[N];
bool used[N];
void MAIN()
{
	int n,k;
	read(n,k);
	int x;
	for(int i=1;i<=k;++i)
	{
		read(x);
		v[i].resize(x);
		for(int j=0;j<x;++j) read(v[i][j]);
	}
	int maxx;
	printf("? %d",n);
	for(int i=1;i<=n;++i) printf(" %d",i);
	printf("\n");
	fflush(stdout);
	read(maxx);
	auto check=[&](int x)->bool
	{
		memset(used,0,sizeof(used));
		for(int i=1;i<=x;++i)
		{
			for(auto it:v[i])
			{
				used[it]=true;
			}
		}
		std::vector<int> qwq;
		for(int i=1;i<=n;++i) 
		{
			if(!used[i])
			{
				qwq.pb(i);
			}
		}
		printf("? %d",SZ(qwq));
		for(auto it:qwq) printf(" %d",it);
		printf("\n");
		fflush(stdout);
		int a;
		read(a);
		return a!=maxx;
	};
	int l=1,r=k;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	int a;
	memset(used,0,sizeof(used));
	for(auto it:v[l]) used[it]=true;
	std::vector<int> qwq;
	for(int i=1;i<=n;++i) if(!used[i]) qwq.pb(i);
	printf("? %d",SZ(qwq));
	for(auto it:qwq) printf(" %d",it);
	printf("\n");
	fflush(stdout);
	read(a);
	printf("! ");
	for(int i=1;i<l;++i) printf("%d ",maxx);
	printf("%d ",a);
	for(int i=l+1;i<=k;++i) printf("%d ",maxx);
	printf("\n");
	fflush(stdout);
	read_str(s);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}