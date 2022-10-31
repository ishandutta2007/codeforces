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

const int N=500005;
int a[N];
int t[N];
std::vector<int> v[N];
bool used[N];
int ans[N];
int main()
{
	int n,m;
	read(n,m);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		v[x].pb(y);
		v[y].pb(x);
	}
	for(int i=1;i<=n;++i) read(a[i]),t[i]=i;
	std::sort(t+1,t+n+1,[&](int A,int B)->bool{return a[A]<a[B];});
	for(int id=1;id<=n;++id)
	{
		int i=t[id];
		for(auto it:v[i])
		{
			if(ans[it])
			{
				used[ans[it]]=true;
			}
		}
		for(int j=1;;++j)
		{
			if(!used[j])
			{
				ans[i]=j;
				break;
			}
		}
		for(auto it:v[i])
		{
			if(ans[it])
			{
				used[ans[it]]=false;
			}
		}
	}
	for(int i=1;i<=n;++i) if(ans[i]!=a[i])
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;++i) printf("%d ",t[i]);
	printf("\n");
	return 0;
}