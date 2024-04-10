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
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937_64 myrand(114514);
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

const int N=200005;
int b[N];
struct node{
	ull a,b,c;
	Finline void operator ^= (const node &o){a^=o.a,b^=o.b,c^=o.c;}
	Finline bool operator < (const node &o)const{return a==o.a?b==o.b?c<o.c:b<o.b:a<o.a;}
}a[N];
std::map<node,ll> mp1,mp2;
int main()
{
	int n,m;read(n,m);
	int x,y;
	for(int i=1;i<=n;++i)
	{
		read(x,y);
		++b[x],--b[y+1];
		node val=(node){myrand(),myrand(),myrand()};
		a[x+1]^=val,a[y+1]^=val;
	}
	for(int i=1;i<=m;++i) a[i]^=a[i-1],b[i]+=b[i-1];
	for(int i=1;i<=m;++i) a[i]^=a[i-1];
	ll ans=0;
	for(int i=1;i<=m;++i)
	{
		++mp1[a[i]];
		mp2[a[i]]+=i-1;
		ans+=1ll*mp1[a[i]]*i-mp2[a[i]];
	}
	for(int i=1;i<=m;++i)
	{
		if(b[i]) continue;
		int j=i;
		while(j<m&&!b[j+1]) ++j;
		int len=j-i+1;
		ans-=1ll*len*(len+1)*(len+2)/6;
		i=j;
	}
	printf("%lld\n",ans);
	return 0;
}