// luogu-judger-enable-o2
// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
#include<bitset>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-8;

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
const double alpha=0.997;
int opt[N];
std::string name[N];
int id[N];
std::map<std::string,int> S;
std::bitset<45> mp[45];
std::bitset<45> used;
int sq[45];
int ans,m;
int calc(int *arr)
{
	used.reset();
	int ans=0;
	for(int i=1;i<=m;++i)
	{
		if(!used.test(arr[i]))
		{
			++ans;
			used|=mp[arr[i]];
		}
	}
	return ans;
}
void SA()
{
	double T=3000;
	while(T>1e-8)
	{
		int u=Rand()%m+1,v=Rand()%m+1;
		while(u==v)
		{
			u=Rand()%m+1;
			v=Rand()%m+1;
		}
		std::swap(sq[u],sq[v]);
		int tmp=calc(sq);
		int D=ans-tmp;
		if(D<0)
		{
			ans=tmp;
		}
		else
		{
			if(exp((double)-D/T)*_RAND_MAX_<Rand())
			{
				std::swap(sq[u],sq[v]);
			}
		}
		T*=alpha;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n,cnt=0;
	std::cin>>n>>m;
	if(m==1)
	{
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		std::cin>>opt[i];
		if(opt[i]==2)
		{
			std::cin>>name[i];
			if(S.find(name[i])==S.end())
			{
				S[name[i]]=++cnt;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(opt[i]==2)
		{
			id[i]=S[name[i]];
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(opt[i]==1)
		{
			for(int j=1;j<=40;++j)
			{
				if(used.test(j))
				{
					for(int k=1;k<=40;++k)
					{
						if(used.test(k))
						{
							mp[j][k]=1;
						}
					}
				}
			}
			used.reset();
		}
		else
		{
			used.set(id[i],true);
		}
	}
	for(int j=1;j<=40;++j)
	{
		if(used.test(j))
		{
			for(int k=1;k<=40;++k)
			{
				if(used.test(k))
				{
					mp[j][k]=1;
				}
			}
		}
	}
	for(int i=1;i<=m;++i) sq[i]=i;
	ans=calc(sq);
	std::random_shuffle(sq+1,sq+m+1);
	chmax(ans,calc(sq));
	
	SA();SA();SA();SA();
				   SA();
			    SA();
			 SA();
		 SA();
	  SA();
	SA();SA();SA();SA();
	
	
	SA();SA();SA();SA();
				   SA();
			    SA();
			 SA();
		 SA();
	  SA();
	SA();SA();SA();SA();
	
	
	SA();SA();SA();
	SA();		   SA();
	SA();
	SA();
	SA();SA();SA();SA();
				   SA();
				   SA();
	SA();		   SA();
		 SA();SA();SA();
	
	
	SA();SA();
	SA();  SA();
	SA();	  SA();
	SA();	    SA();
	SA();		  SA();
	SA();		  SA();
	SA();		  SA();
	SA();		SA();
	SA();	  SA();
	SA();  SA();
	SA();SA();
	
	
	SA();SA();
	SA();  SA();
	SA();	  SA();
	SA();	    SA();
	SA();		  SA();
	SA();		  SA();
	SA();		  SA();
	SA();		SA();
	SA();	  SA();
	SA();  SA();
	SA();SA();
	
	printf("%d\n",ans);
    return 0;
}