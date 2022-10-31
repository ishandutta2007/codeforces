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
const ll INF=0x7fffffffffffffff;
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
 
struct trie{
	struct node{
		int ch[2];
		int siz;
	}f[N<<6];
	int node_cnt;
	void Insert(int x)
	{
		int cur=0,tmp;
		for(int i=30;i>=0;--i)
		{
			tmp=(x>>i)&1;
			if(!f[cur].ch[tmp]) f[cur].ch[tmp]=++node_cnt;
			cur=f[cur].ch[tmp];
			++f[cur].siz;
		}
	}
	void Delete(int x)
	{
		int cur=0,tmp;
		for(int i=30;i>=0;--i)
		{
			tmp=(x>>i)&1;
			if(!f[cur].ch[tmp]) f[cur].ch[tmp]=++node_cnt;
			--f[f[cur].ch[tmp]].siz;
			if(!f[f[cur].ch[tmp]].siz)
			{
				int t=cur;
				cur=f[cur].ch[tmp];
				f[t].ch[tmp]=0;
			}
			else
			{
				cur=f[cur].ch[tmp];
			}
		}
	}
	int Query(int x)
	{
		int ans=0,tmp,cur=0;
		for(int i=30;i>=0;--i)
		{
			tmp=(x>>i)&1;
			if(f[cur].ch[tmp^1])
			{
				ans|=(1<<i);
				cur=f[cur].ch[tmp^1];
			}
			else
			{
				cur=f[cur].ch[tmp];
			}
		}
		return ans;
	}
}tr;
int main()
{
	int n;
	read(n);
	char ch;
	int x;
	tr.Insert(0);
	while(n--)
	{
		ch=getchar();
		while(ch!='+'&&ch!='-'&&ch!='?') ch=getchar();
		if(ch=='+')
		{
			read(x);
			tr.Insert(x);
		}
		else if(ch=='-')
		{
			read(x);
			tr.Delete(x);
		}
		else
		{
			read(x);
			printf("%d\n",tr.Query(x));
		}
	}
    return 0;
}