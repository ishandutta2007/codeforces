// luogu-judger-enable-o2
// Author -- Frame
 
#pragma GCC optimize(2)
 
#include<cstdio>
#include<cstring>
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
const ll INF=0x7ffffffffffffff;
const double eps=1e-8;
 
uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool ismax(_Tp &a,const _Tp &b){return a>b?1:a=b,0;}
template <typename _Tp>Finline bool ismin(_Tp &a,const _Tp &b){return a<b?1:a=b,0;}
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
 
const int N=100005;
void MAIN()
{
	int b,w;
	read(b,w);
	int block=b+w;
	if(b==w)
	{
		printf("YES\n");
		for(int i=1;i<=block;++i) printf("%d %d\n",1,i);
		return;
	}
	std::vector<std::pair<int,int> > v;
	if(b>w)
	{
		if(w==1)
		{
			if(b<=4)
			{
				v.push_back(std::make_pair(2,2));
				if(b>=1)
				{
					v.push_back(std::make_pair(1,2));
				}
				if(b>=2)
				{
					v.push_back(std::make_pair(2,1));
				}
				if(b>=3)
				{
					v.push_back(std::make_pair(3,2));
				}
				if(b>=4)
				{
					v.push_back(std::make_pair(2,3));
				}
				printf("YES\n");
				for(auto it:v) printf("%d %d\n",it.first,it.second);
				return;
			}
			else
			{
				printf("NO\n");
				return;
			}
		}
		for(int i=1;w;++i)
		{
			v.push_back(std::make_pair(2,i+1));
			if((i+1)&1)
			{
				--b;
			}
			else
			{
				--w;
			}
		}
		int now=v.size();
		for(int i=0;i<now&&b;i+=2)
		{
			if(!i||i==now-1)
			{
				if(b<=3)
				{
					if(b>=1)
					{
						v.push_back(std::make_pair(1,v[i].second));
					}
					if(b>=2)
					{
						v.push_back(std::make_pair(3,v[i].second));
					}
					if(b>=3)
					{
						if(!i) v.push_back(std::make_pair(2,1));
						else v.push_back(std::make_pair(v[i].first,v[i].second+1));
					}
					b=0;
				}
				else
				{
					v.push_back(std::make_pair(1,v[i].second));
					v.push_back(std::make_pair(3,v[i].second));
					if(!i) v.push_back(std::make_pair(2,1));
					else v.push_back(std::make_pair(v[i].first,v[i].second+1));
					b-=3;
				}
			}
			else
			{
				if(b<=2)
				{
					if(b>=1)
					{
						v.push_back(std::make_pair(1,v[i].second));
					}
					if(b>=2)
					{
						v.push_back(std::make_pair(3,v[i].second));
					}
					b=0;
				}
				else
				{
					v.push_back(std::make_pair(1,v[i].second));
					v.push_back(std::make_pair(3,v[i].second));
					b-=2;
				}
			}
		}
		if(b)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			for(auto it:v) printf("%d %d\n",it.first,it.second);
		}
	}
	else
	{
		if(b==1)
		{
			if(w<=4)
			{
				v.push_back(std::make_pair(2,3));
				if(w>=1)
				{
					v.push_back(std::make_pair(2,2));
				}
				if(w>=2)
				{
					v.push_back(std::make_pair(2,4));
				}
				if(w>=3)
				{
					v.push_back(std::make_pair(1,3));
				}
				if(w>=4)
				{
					v.push_back(std::make_pair(3,3));
				}
				printf("YES\n");
				for(auto it:v) printf("%d %d\n",it.first,it.second);
				return;
			}
			else
			{
				printf("NO\n");
				return;
			}
		}
		for(int i=1;b;++i)
		{
			v.push_back(std::make_pair(2,i+2));
			if(i&1)
			{
				--b;
			}
			else
			{
				--w;
			}
		}
		int now=v.size();
		for(int i=0;i<now&&w;i+=2)
		{
			if(!i||i==now-1)
			{
				if(w<=3)
				{
					if(w>=1)
					{
						v.push_back(std::make_pair(1,v[i].second));
					}
					if(w>=2)
					{
						v.push_back(std::make_pair(3,v[i].second));
					}
					if(w>=3)
					{
						if(!i) v.push_back(std::make_pair(2,2));
						else v.push_back(std::make_pair(v[i].first,v[i].second+1));
					}
					w=0;
				}
				else
				{
					v.push_back(std::make_pair(1,v[i].second));
					v.push_back(std::make_pair(3,v[i].second));
					if(!i) v.push_back(std::make_pair(2,2));
					else v.push_back(std::make_pair(v[i].first,v[i].second+1));
					w-=3;
				}
			}
			else
			{
				if(w<=2)
				{
					if(w>=1)
					{
						v.push_back(std::make_pair(1,v[i].second));
					}
					if(w>=2)
					{
						v.push_back(std::make_pair(3,v[i].second));
					}
					w=0;
				}
				else
				{
					v.push_back(std::make_pair(1,v[i].second));
					v.push_back(std::make_pair(3,v[i].second));
					w-=2;
				}
			}
		}
		if(w)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			for(auto it:v) printf("%d %d\n",it.first,it.second);
		}
	}
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}
//