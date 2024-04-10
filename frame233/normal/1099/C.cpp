// luogu-judger-enable-o2
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
 
const int N=100005;
char s[N];
char ans[N];
int main()
{
	scanf("%s",s+1);
	int l=strlen(s+1);
	int k;
	read(k);
	int cnt1=0,cnt2=0,len=0;
	for(int i=1;i<=l;++i)
	{
		if(s[i]!='?'&&s[i]!='*')
		{
			++len;
		}
		else if(s[i]=='?')
		{
			++cnt1;
		}
		else
		{
			++cnt2;
		}
	}
	len-=cnt1+cnt2;
	if(len>k)
	{
		printf("Impossible\n");
		return 0;
	}
	int pos=0;
	if(cnt2)
	{
		int tmp=k-len;
		bool first=0;
		for(int i=1;i<=l;++i)
		{
			if(s[i]!='?'&&s[i]!='*')
			{
				ans[++pos]=s[i];
			}
			else if(s[i]=='?')
			{
				--pos;
			}
			else
			{
				if(!first)
				{
					first=1;
					for(int j=1;j<tmp;++j) ans[++pos]=s[i-1];
				}
				else
				{
					--pos;
				}
			}
		}
	}
	else
	{
		if(len+cnt1<k)
		{
			printf("Impossible\n");
			return 0;
		}
		else
		{
			int tmp=k-len;
			for(int i=1;i<=l;++i)
			{
				if(s[i]!='*'&&s[i]!='?')
				{
					ans[++pos]=s[i];
				}
				else if(s[i]=='?')
				{
					if(tmp)
					{
						--tmp;
					}
					else
					{
						--pos;
					}
				}
			}
		}
	}
	for(int i=1;i<=k;++i) printf("%c",ans[i]);
	printf("\n");
    return 0;
}