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

const int N=300005;
const int mod=998244353;
std::vector<int> v[N];
ll f[N][3];
void dfs(int x,int fa)
{
	f[x][2]=1;
	for(auto it:v[x])
	{
		if(it!=fa)
		{
			dfs(it,x);
			ll sum=(f[it][0]+f[it][1]+f[it][2])%mod;
			f[x][0]=((f[x][0]+f[x][2])%mod*(sum+f[it][2])%mod+f[x][0]*sum)%mod;
			f[x][1]=((f[x][1]+f[x][2])%mod*(f[it][0]+f[it][2])%mod+f[x][1]*sum)%mod;
			f[x][2]=f[x][2]*sum%mod;
		}
	}
}
int main()
{
	int n,x,y;
	read(n);
	for(int i=1;i<n;++i)
	{
		read(x,y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	printf("%lld\n",(f[1][0]+f[1][1]+f[1][2]-1+mod)%mod);
	return 0;
}