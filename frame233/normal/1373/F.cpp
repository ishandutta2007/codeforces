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
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=2000005;
ll a[N],b[N],s[N];
int _q[N],_l,_r;
void MAIN()
{
	int n;
	read(n);
	ll qwq=0;
	for(int i=1;i<=n;++i) read(a[i]),a[i+n]=a[i],qwq-=a[i];
	for(int i=1;i<=n;++i) read(b[i]),b[i+n]=b[i],qwq+=b[i];
	if(qwq<0)
	{
		printf("NO\n");
		return;
	}
	for(int i=1;i<=n<<1;++i) s[i]=s[i-1]+b[i]-a[i];
	_l=1,_r=0;
	for(int i=n<<1;i>=1;--i)
	{
		while(_l!=_r+1&&s[_q[_r]]>=s[i]) --_r;
		_q[++_r]=i;
		while(_l!=_r+1&&_q[_l]>i+n-1) ++_l;
		if(s[_q[_l]]-s[i]+b[i]<0)
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}