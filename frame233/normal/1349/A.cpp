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
typedef std::pair<int,int> pl;

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

const int N=200005;
ll ksm(ll a,ll b)
{
	ll res=1;
	while(b) res*=a,--b;
	return res;
}
int a[N];
std::vector<int> v[N];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		int x=a[i];
		for(int j=2;j*j<=a[i];++j)
		{
			if(!(x%j))
			{
				int cnt=0;
				while(!(x%j)) ++cnt,x/=j;
				v[j].pb(cnt);
			}
		}
		if(x>1) v[x].pb(1);
	}
	ll ans=1;
	for(int i=1;i<N;++i)
	{
		std::sort(v[i].begin(),v[i].end());
		if(SZ(v[i])==n)
		{
			ans*=ksm(i,v[i][1]);
		}
		else if(SZ(v[i])==n-1)
		{
			ans*=ksm(i,v[i][0]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}