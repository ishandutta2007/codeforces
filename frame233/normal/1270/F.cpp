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
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
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
const int block_size=450;
char a[N];
int s[N];
std::vector<int> v[N<<1];
int qwq[N];
ll calc(int n,int k)
{
	qwq[0]=0;
	for(int i=1;i<=n;++i)
	{
		qwq[i]=s[i]*k-i;
	}
	std::sort(qwq,qwq+n+1);
	ll ans=0;
	for(int i=0;i<=n;++i)
	{
		int j=i;
		while(j<n&&qwq[j+1]==qwq[i]) ++j;
		ans+=1ll*(j-i+1)*(j-i);
		i=j;
	}
	return ans>>1;
}
Finline ll iakioi(int l,int r,int d)
{
	return r/d-(l-1)/d;
}
ll solve(int n,int d)
{
	for(int i=n;i>=0;--i)
	{
		v[s[i]].push_back(i);
	}
	int minn=d*(block_size+1);
	ll ans=0;
	for(int i=0;i<=n;++i)
	{
		if(i+minn>n)
		{
			v[s[i]].pop_back();
			continue;
		}
		if(v[s[i]+d].empty())
		{
			v[s[i]].pop_back();
			continue;
		}
		int pos2=*v[s[i]+d].begin();
		int pos1=v[s[i]+d].back();
		if(pos2<i+minn)
		{
			v[s[i]].pop_back();
			continue;
		}
		chmax(pos1,i+minn);
		ans+=iakioi(pos1-i,pos2-i,d);
		v[s[i]].pop_back();
	}
	return ans;
}
int main()
{
	fprintf(stderr,"%.3lf\n",(sizeof(v))/1024.0/1024.0);
	int n=read_str(a+1);
	for(int i=1;i<=n;++i)
	{
		s[i]=(a[i]=='1')+s[i-1];
	}
	ll ans=0;
	for(int k=1;k<=n&&k<=block_size;++k)
	{
		ans+=calc(n,k);
	}
	for(int d=1;d<=n/block_size;++d)
	{
		ans+=solve(n,d);
	}
	printf("%lld\n",ans);
	return 0;
}