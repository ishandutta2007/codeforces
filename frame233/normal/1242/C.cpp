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
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
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
 
const int N=100005;
std::map<ll,int> mp;
std::vector<int> v[17];
int idg[17],odg[17];
ll _sum[17];
bool used[17];
int num[17],to[17];
std::pair<int,int> __[1<<15];
bool can[1<<15];
bool f[1<<15];
int opt[1<<15];
int n;
ll sum;
void output(int st)
{
	int _=__[st].first,it=__[st].second;
	int cur=_;
	ll qwq=it;
	for(int i=1;i<=n;++i)
	{
		if(used[cur]) break;
		ll tmp=_sum[cur]-qwq;
		int pos=mp[sum-tmp];
		num[cur]=qwq;
		used[cur]=1;
		qwq=sum-tmp;
		to[pos]=cur;
		cur=pos;
	}
}
void print(int st)
{
	if(st)
	{
		if(can[st])
		{
			output(st);
		}
		else
		{
			print(opt[st]);
			print(st^opt[st]);
		}
	}
}
int main()
{
	read(n);
	int x,y;
	for(int i=1;i<=n;++i)
	{
		read(x);
		while(x--)
		{
			read(y);
			v[i].push_back(y);
			sum+=y;
			mp[y]=i;
			_sum[i]+=y;
		}
	}
	if(sum%n)
	{
		printf("No\n");
		return 0;
	}
	sum/=n;
	for(int _=1;_<=n;++_)
	{
		for(auto it:v[_])
		{
			memset(idg,0,sizeof(idg));
			memset(odg,0,sizeof(odg));
			memset(used,0,sizeof(used));
			int cur=_;
			ll qwq=it;
			bool flag=0;
			for(int i=1;i<=n;++i)
			{
				if(used[cur]) break;
				ll tmp=_sum[cur]-qwq;
				if(mp.find(sum-tmp)==mp.end())
				{
					flag=1;
					break;
				}
				int pos=mp[sum-tmp];
				num[cur]=qwq;
				used[cur]=1;
				qwq=sum-tmp;
				++odg[cur];
				to[pos]=cur;
				++idg[cur=pos];
				if(used[cur]&&qwq!=num[cur])
				{
					flag=1;
					break;
				}
			}
			if(flag) continue;
			for(int i=1;i<=n;++i)
			{
				if(used[i]&&(idg[i]!=1||odg[i]!=1))
				{
					flag=1;
					break;
				}
			}
			int st=0;
			for(int i=1;i<=n;++i)
			{
				if(used[i])
				{
					st|=1<<(i-1);
				}
			}
			if(!flag)
			{
				can[st]=1;
				__[st]=std::make_pair(_,it);
			}
		}
	}
	f[0]=1;
	for(int st=0;st<1<<n;++st)
	{
		if(can[st])
		{
			f[st]=1;
			opt[st]=st;
			continue;
		}
		for(int S=(st-1)&st;S;S=(S-1)&st)
		{
			if(f[S]&&f[st^S])
			{
				f[st]=1;
				opt[st]=S;
				break;
			}
		}
	}
	memset(used,0,sizeof(used));
	if(f[(1<<n)-1])
	{
		printf("Yes\n");
		print((1<<n)-1);
		for(int i=1;i<=n;++i) printf("%d %d\n",num[i],to[i]);
	}
	else
	{
		printf("No\n");
	}
    return 0;
}