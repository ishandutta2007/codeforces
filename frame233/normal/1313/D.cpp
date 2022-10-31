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
struct node{
	int l,r;
	Finline bool operator == (const node &o)const
	{
		return l==o.l&&r==o.r;
	}
}a[N];
int t[N],pos;
std::vector<int> v1[N];
std::vector<int> v2[N];
std::vector<int> v;
int dp[1<<8],tmp[1<<8];
int cnt[1<<8];
bool used[9];
int main()
{
	for(int i=1;i<1<<8;++i) cnt[i]=cnt[i>>1]+(i&1);
	int n,m,k;
	read(n,m,k);
	int l,r;
	for(int i=1;i<=n;++i)
	{
		read(l,r);
		++r;
		t[++pos]=l;
		t[++pos]=r;
		a[i]={l,r};
	}
	std::sort(t+1,t+pos+1);
	pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=n;++i)
	{
		l=std::lower_bound(t+1,t+pos+1,a[i].l)-t;
		r=std::lower_bound(t+1,t+pos+1,a[i].r)-t;
		v1[l].push_back(i);
		v2[r-1].push_back(i);
		a[i]={l,r};
	}
	for(int i=1;i<pos;++i)
	{
		memset(tmp,0,sizeof(tmp));
		int qwq=v1[i].size();
		for(auto it:v1[i])
		{
			v.push_back(it);
		}
		int lim=(int)v.size();
		for(int st=0;st<1<<lim;++st)
		{
			if(cnt[st]&1)
			{
				tmp[st]=dp[st>>qwq]+t[i+1]-t[i];
			}
			else
			{
				tmp[st]=dp[st>>qwq];
			}
		}
		memset(used,0,sizeof(used));
		for(auto it:v2[i])
		{
			for(int j=0;j<lim;++j)
			{
				if(v[j]==it)
				{
					used[j]=1;
					break;
				}
			}
		}
		memset(dp,0,sizeof(dp));
		for(int st=0;st<1<<lim;++st)
		{
			int qaq=0;
			for(int j=0;j<lim;++j)
			{
				if(!used[j])
				{
					qaq=(qaq<<1)|((st>>(lim-j-1))&1);
				}
			}
			chmax(dp[qaq],tmp[st]);
		}
		std::vector<int> cur;
		for(int j=0;j<lim;++j)
		{
			if(!used[j])
			{
				cur.push_back(v[j]);
			}
		}
		v=cur;
	}
	int ans=0;
	for(int i=0;i<1<<8;++i)
	{
		chmax(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}