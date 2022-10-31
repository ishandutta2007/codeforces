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

const int N=100005;
/*
1,2		xy
3~33	2^k
34		0
40~200	temp
*/
int d,p;
int mod,C[15][15];
int k[15],a[15][15];
int cur=201;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll ksm(ll a,ll b=p-2)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p,b>>=1;
	}
	return res;
}
void add(int a,int b,int c)
{
	printf("+ %d %d %d\n",a,b,c);
}
void powd(int a,int b)
{
	printf("^ %d %d\n",a,b);
}
void clear(int x)
{
	powd(34,x);
}
void mul(int a,int C)
{
	add(a,34,100);
	for(int i=100;i<130;++i) add(i,i,i+1);
	clear(a);
	for(int i=0;i<=30;++i) if((C>>i)&1) add(100+i,a,a);
}
void _div(int a,int C)
{
	mul(a,ksm(C));
}
int pow2(int a)
{
	add(a,34,40);
	for(int i=40;i<40+d;++i) add(i,35,i+1);
	for(int i=0;i<=d;++i) powd(40+i,40+i);
	++cur;clear(cur);
	for(int i=40;i<=40+d;++i) mul(i,k[i-40]),add(i,cur,cur);
	return cur;
}
int main()
{
	read(d,p);
	mod=p;
	for(int i=1;i<=30;++i) add(2+i,2+i,2+i+1);
	int tar=p-1;for(int i=0;i<=30;++i) if((tar>>i)&1) add(3+i,34,34);
	for(int i=0;i<15;++i) for(int j=C[i][0]=1;j<=i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	for(int i=0;i<=d;++i)
	{
		for(int j=0;j<=d;++j) a[i][j]=1ll*C[d][i]*ksm(j,d-i)%mod;
		a[i][d+1]=(i==2);
	}
	for(int i=0;i<=d;++i)
	{
		int pos=i;
		for(int j=i;j<=d;++j) if(a[j][i]){pos=j;break;}
		std::swap(a[i],a[pos]);
		assert(a[i][i]);
		ll inv=ksm(a[i][i]);
		for(int j=i;j<=d+1;++j) a[i][j]=1ll*a[i][j]*inv%mod;
		for(int j=0;j<=d;++j)
		{
			if(i==j) continue;
			for(int k=d+1;k>=i;--k) sub(a[j][k],1ll*a[j][i]*a[i][k]%mod);
		}
	}
	for(int i=0;i<=d;++i) k[i]=a[i][d+1];
	add(1,2,++cur);
	int xy2=pow2(cur);
	int x2=pow2(1);
	int y2=pow2(2);
	mul(x2,p-1);
	add(x2,xy2,xy2);
	mul(y2,p-1);
	add(y2,xy2,xy2);
	mul(xy2,(p+1)>>1);
	printf("f %d\n",xy2);
	return 0;
}