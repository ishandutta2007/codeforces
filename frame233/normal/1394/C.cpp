// Author -- Frame

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

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

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
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=300005;
int x[N],y[N],n;
char s[N<<1];
int X,Y;
bool check(int mid)
{
	int l1=0,r1=inf;
	int l2=0,r2=inf;
	int l3=-inf,r3=inf;
	for(int i=1;i<=n;++i)
	{
		chmax(l1,x[i]-mid),chmin(r1,x[i]+mid);
		chmax(l2,y[i]-mid),chmin(r2,y[i]+mid);
		chmax(l3,y[i]-x[i]-mid),chmin(r3,y[i]-x[i]+mid);
	}
	chmax(l3,l2-r1),chmin(r3,r2-l1);
	if(l1>r1||l2>r2||l3>r3) return false;
	X=max(l1,l2-l3),Y=l3+X;
	if(!X&&!Y) ++X,++Y;
	assert(X>=l1&&X<=r1&&Y>=l2&&Y<=r2&&Y-X>=l3&&Y-X<=r3);
	return true;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)
	{
		int len=read_str(s);
		for(int j=0;j<len;++j) s[j]=='B'?++x[i]:++y[i];
	}
	int l=0,r=1e6;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);check(l);
	while(X--) putchar('B');
	while(Y--) putchar('N');
	putchar('\n');
	return 0;
}