// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>

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

const int N=200005;
int f[N][21],g[N][21];
int Log2[N];
int a[N];
ll ans;
std::map<int,int> mp[N];
int node_cnt;
int Query(int l,int r)
{
	int k=Log2[r-l+1];
	if(f[l][k]>f[r-(1<<k)+1][k]) return g[l][k];
	return g[r-(1<<k)+1][k];
}
int solve(int l,int r)
{
	if(l>r) return 0;
	if(l==r)
	{
		mp[l][a[l]]=1;
		return l;
	}
	int pos=Query(l,r);
	int ls=solve(l,pos-1);
	int rs=solve(pos+1,r);
	if(mp[ls].size()<mp[rs].size())
	{
		std::swap(ls,rs);
	}
	for(auto it:mp[rs])
	{
		if(mp[ls].find(a[pos]-it.first)!=mp[ls].end())
		{
			ans+=1ll*mp[ls][a[pos]-it.first]*it.second;
		}
	}
	for(auto it:mp[rs])
	{
		mp[ls][it.first]+=it.second;
	}
	++mp[ls][a[pos]];
	return ls;
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=2;i<=n;++i) Log2[i]=Log2[i>>1]+1;
	for(int i=n;i>=1;--i)
	{
		f[i][0]=a[i];
		g[i][0]=i;
		for(int j=1;j<=20&&i+(1<<(j-1))<=n;++j)
		{
			f[i][j]=f[i][j-1];
			g[i][j]=g[i][j-1];
			if(f[i+(1<<(j-1))][j-1]>f[i][j])
			{
				f[i][j]=f[i+(1<<(j-1))][j-1];
				g[i][j]=g[i+(1<<(j-1))][j-1];
			}
		}
	}
	solve(1,n);
	printf("%lld\n",ans);
	return 0;
}