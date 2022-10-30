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

const int N=500005;
const int mod=998244853;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
const int base=23333;
char s[N];
ull B[5+((mod+63)>>6)];
Finline void set(int pos)
{
	B[pos>>6]|=1ull<<(pos&63);
}
Finline void reset(int pos)
{
	B[pos>>6]&=~(1ull<<(pos&63));
}
Finline bool test(int pos)
{
	return (B[pos>>6]>>(pos&63))&1;
}
int f[N];
int dp[N];
int main()
{
	int n;read(n);
	read_str(s+1);
	for(int i=1;i<=n;++i) s[i]-=96;
	int mid;
	for(int i=1;i<=n;++i) f[i]=s[i],dp[i]=1;
	for(mid=2;mid<=1000;++mid)
	{
		bool flag=false;
		for(int i=n-mid+1;i>=1;--i)
		{
			if(dp[i+mid]>=mid-1) set(f[i+mid]);
			if((dp[i]==mid-1&&test(f[i]))||(dp[i+1]>=mid-1&&test(f[i+1])))
			{
				dp[i]=mid;
				flag=true;
			}
		}
		if(!flag)
		{
			--mid;
			break;
		}
		for(int i=1;i<=n;++i) if(dp[i]>=mid-1) reset(f[i]);
		for(int i=n-mid+1;i>=1;--i) f[i]=(1ll*f[i]*base+s[i+mid-1])%mod;
	}
	printf("%d\n",mid);
	return 0;
}