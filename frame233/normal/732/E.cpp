// luogu-judger-enable-o2
// Author -- Frame
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<chrono>
 
#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;
const double eps=1e-8;
 
uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
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
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}
 
const int N=200005;
struct custom_hash{
    Finline static uint64_t splitmix64(uint64_t x)
    {
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    Finline size_t operator()(uint64_t x)const
    {
        static const uint64_t FIXED_RANDOM=std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};
std::unordered_map<ll,std::vector<int> > mp;
int ans1[N],ans2[N];
struct node{
	int val,id;
	Finline bool operator < (const node &o)const
	{
		return val<o.val;
	}
}a[N];
int main()
{
	int n,m;
	ll x;
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		read(x);
		mp[x].push_back(i);
	}
	int res1=0,res2=0;
	for(int i=1;i<=m;++i)
	{
		read(a[i].val);
		a[i].id=i;
	}
	std::sort(a+1,a+m+1);
	for(int i=1;i<=m;++i)
	{
		x=a[i].val;
		if(mp.find(x)!=mp.end())
		{
			ans1[*--mp[x].end()]=a[i].id;
			mp[x].pop_back();
			++res1;
			if(mp[x].empty())
			{
				mp.erase(mp.find(x));
			}
			continue;
		}
		int cnt=0;
		while(x>1)
		{
			++cnt;
			x=(x+1)>>1;
			if(mp.find(x)!=mp.end())
			{
				ans1[*--mp[x].end()]=a[i].id;
				mp[x].pop_back();
				++res1;
				res2+=cnt;
				ans2[a[i].id]=cnt;
				if(mp[x].empty())
				{
					mp.erase(mp.find(x));
				}
				break;
			}
		}
	}
	printf("%d %d\n",res1,res2);
	for(int i=1;i<=m;++i)
	{
		printf("%d ",ans2[i]);
	}
	printf("\n");
	for(int i=1;i<=n;++i)
	{
		printf("%d ",ans1[i]);
	}
	printf("\n");
    return 0;
}