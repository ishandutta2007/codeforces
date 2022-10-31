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
	static uint seed=416;
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

const int N=500005;
int d1[N],d2[N];
const int MAXN=10000005;
bool pr[MAXN];
int p[MAXN],pos;
int md[MAXN];
void sieve()
{
	for(int i=2;i<MAXN;++i)
	{
		if(!pr[i])
		{
			p[++pos]=i;
			md[i]=i;
		}
		for(int j=1;j<=pos&&i*p[j]<MAXN;++j)
		{
			pr[i*p[j]]=true;
			md[i*p[j]]=p[j];
			if(!(i%p[j]))
			{
				break;
			}
		}
	}
}
int main()
{
	sieve();
	int n;
	read(n);
	int x;
	for(int i=1;i<=n;++i)
	{
		read(x);
		int tmp=md[x];
		while(!(x%tmp)) x/=tmp;
		if(x>1&&x!=tmp) d1[i]=tmp,d2[i]=x;
		else d1[i]=d2[i]=-1;
	}
	for(int i=1;i<=n;++i) printf("%d ",d1[i]);
	printf("\n");
	for(int i=1;i<=n;++i) printf("%d ",d2[i]);
	printf("\n");
	return 0;
}