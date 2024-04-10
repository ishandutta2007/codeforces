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

const int N=19;
int a[N][N];
ll g[1<<18][N],f[N][1<<18];
ll qwq[1<<18];
int cnt[1<<18];
void FWT_or(ll *a,int lim)
{
	for(int len=1;len<=lim;len<<=1)
	{
		for(int pos=0;pos<lim;pos+=len)
		{
			for(int i=pos;i<pos+(len>>1);++i)
			{
				a[i+(len>>1)]+=a[i];
			}
		}
	}
}
void IFWT_or(ll *a,int lim)
{
	for(int len=1;len<=lim;len<<=1)
	{
		for(int pos=0;pos<lim;pos+=len)
		{
			for(int i=pos;i<pos+(len>>1);++i)
			{
				a[i+(len>>1)]-=a[i];
			}
		}
	}
}
void FWT_and(ll *a,int lim)
{
	for(int len=1;len<=lim;len<<=1)
	{
		for(int pos=0;pos<lim;pos+=len)
		{
			for(int i=pos;i<pos+(len>>1);++i)
			{
				a[i]+=a[i+(len>>1)];
			}
		}
	}
}
void IFWT_and(ll *a,int lim)
{
	for(int len=1;len<=lim;len<<=1)
	{
		for(int pos=0;pos<lim;pos+=len)
		{
			for(int i=pos;i<pos+(len>>1);++i)
			{
				a[i]-=a[i+(len>>1)];
			}
		}
	}
}
std::vector<int> v;
int n;
ll res[387];
int id;
std::map<std::vector<int>,int> mp;
ll tmp[1<<18],ans[1<<18];
void dfs(int sum,int last)
{
	if(sum==n)
	{
		mp[v]=++id;
		for(int i=0;i<1<<n;++i) tmp[i]=1;
		for(auto it:v)
		{
			for(int i=0;i<1<<n;++i)
			{
				tmp[i]*=f[it][i];
			}
		}
		IFWT_or(tmp,1<<n);
		res[id]=tmp[(1<<n)-1];
		return;
	}
	for(int i=last;i<=n-sum;++i)
	{
		v.push_back(i);
		dfs(sum+i,i);
		v.pop_back();
	}
}
int main()
{
	read(n);
	for(int i=0;i<1<<n;++i) cnt[i]=cnt[i>>1]+(i&1);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			scanf("%1d",&a[i][j]);
		}
		g[1<<i][i]=1;
	}
	for(int st=0;st<1<<n;++st)
	{
		for(int j=0;j<n;++j)
		{
			if(!g[st][j]) continue;
			for(int k=0;k<n;++k)
			{
				if(a[j][k]&&!((st>>k)&1))
				{
					g[st|(1<<k)][k]+=g[st][j];
				}
			}
		}
		for(int j=0;j<n;++j) qwq[st]+=g[st][j];
	}
	for(int i=1;i<=n;++i)
	{
		for(int st=0;st<1<<n;++st)
		{
			if(cnt[st]==i)
			{
				f[i][st]=qwq[st];
			}
		}
		FWT_or(f[i],1<<n);
	}
	dfs(0,1);
	for(int i=0;i<1<<(n-1);++i)
	{
		std::vector<int> tmp;
		int last=-1;
		for(int j=0;j<n;++j)
		{
			if(!((i>>j)&1))
			{
				tmp.push_back(j-last);
				last=j;
			}
		}
		std::sort(tmp.begin(),tmp.end());
		ans[i]=res[mp[tmp]];
	}
	IFWT_and(ans,1<<(n-1));
	for(int i=0;i<1<<(n-1);++i) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}