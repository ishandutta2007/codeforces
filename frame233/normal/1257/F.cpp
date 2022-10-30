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
Finline int read_str(char *s)
{
    register char ch(getchar());
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=105;
int a[N];
struct node{
	int a[N],x;
}st1[1<<15],tmp;
int cnt[1<<15];
Finline int count(const int &x)
{
	return cnt[x&0x7fff]+cnt[(x>>15)&0x7fff];
}
int n;
int ws;
struct trie{
	int ch[3500005][16];
	int val[3500005];
	int node_cnt;
	void insert(const node &o)
	{
		int cur=0,tmp;
		for(int i=0;i<n;++i)
		{
			tmp=o.a[i];
			if(!ch[cur][tmp]) ch[cur][tmp]=++node_cnt;
			cur=ch[cur][tmp];
		}
		val[cur]=o.x;
	}
	int Query(const node &o)
	{
		int cur=0,tmp;
		for(int i=0;i<n;++i)
		{
			tmp=o.a[i];
			if(ws-tmp<0||ws-tmp>15) return -1;
			if(!ch[cur][ws-tmp]) return -1;
			cur=ch[cur][ws-tmp];
		}
		return val[cur];
	}
}tr;
int main()
{
	for(int i=0;i<1<<15;++i) cnt[i]=cnt[i>>1]+(i&1);
	read(n);
	for(int i=0;i<n;++i) read(a[i]);
	for(int st=0;st<1<<15;++st)
	{
		for(int i=0;i<n;++i)
		{
			tmp.a[i]=count((a[i]&0x7fff)^st);
		}
		tmp.x=st;
		st1[st]=tmp;
	}
	for(int st=0;st<1<<15;++st)
	{
		for(int i=0;i<n;++i)
		{
			tmp.a[i]=count(((a[i]>>15)&0x7fff)^st);
		}
		tmp.x=st<<15;
		tr.insert(tmp);
	}
	int qwq;
	for(ws=0;ws<=29;++ws)
	{
		for(int i=0;i<1<<15;++i)
		{
			if(~(qwq=tr.Query(st1[i])))
			{
				printf("%d\n",st1[i].x|qwq);
				return 0;
			}
		}
	}
	printf("-1\n");
    return 0;
}