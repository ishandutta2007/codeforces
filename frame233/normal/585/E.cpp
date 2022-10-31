// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
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

const int N=500005;
const int mod=1000000007;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
const int MAXN=10000005;
bool pr[MAXN];
int p[MAXN],pos;
int mu[MAXN];
int cnt[MAXN];
int s[MAXN],g[MAXN];
int pw2[N];
int solve()
{
	pw2[0]=1;
	for(int i=1;i<N;++i)
	{
		pw2[i]=pw2[i-1];
		add(pw2[i],pw2[i-1]);
	}
	mu[1]=1;
	for(int i=2;i<MAXN;++i)
	{
		if(!pr[i])
		{
			p[++pos]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=pos&&i*p[j]<MAXN;++j)
		{
			pr[i*p[j]]=true;
			if(!(i%p[j]))
			{
				mu[i*p[j]]=0;
				break;
			}
			mu[i*p[j]]=-mu[i];
		}
	}
	for(int i=1;i<=pos;++i)
	{
		for(int j=(MAXN-1)/p[i];j>=1;--j)
		{
			cnt[j]+=cnt[p[i]*j];
		}
	}
	for(int i=1;i<MAXN;++i)
	{
		if(mu[i]==1) s[i]=cnt[i];
		else if(mu[i]==-1) (s[i]=mod-cnt[i])==mod&&(s[i]-=mod);
		g[i]=pw2[cnt[i]]-1;
	}
	for(int i=1;i<=pos;++i)
	{
		for(int j=1,lim=(MAXN-1)/p[i];j<=lim;++j)
		{
			add(s[p[i]*j],s[j]);
			sub(g[j],g[p[i]*j]);
		}
	}
	int ans=0;
	for(int i=2;i<MAXN;++i) add(ans,1ll*s[i]*g[i]%mod);
	return ans;
}
int main()
{
	int n,x;
	read(n);
	for(int i=1;i<=n;++i) read(x),++cnt[x];
	printf("%d\n",solve());
	return 0;
}