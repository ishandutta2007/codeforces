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

const int N=200005;
int l[N],r[N];
int t[N];
int type[N];
int main()
{
	int q;
	read(q);
	int x;
	char ch;
	int cnt=0;
	int node_cnt=0;
	while(q--)
	{
		++cnt;
		ch=getchar();
		while(ch!='L'&&ch!='R'&&ch!='?') ch=getchar();
		read(x);
		if(ch=='L')
		{
			++node_cnt;
			l[cnt]=l[cnt-1]+1;
			r[cnt]=r[cnt-1];
			t[x]=cnt;
			type[x]=0;
		}
		else if(ch=='R')
		{
			++node_cnt;
			l[cnt]=l[cnt-1];
			r[cnt]=r[cnt-1]+1;
			t[x]=cnt;
			type[x]=1;
		}
		else
		{
			l[cnt]=l[cnt-1];
			r[cnt]=r[cnt-1];
			if(type[x]) printf("%d\n",min(r[cnt]-r[t[x]],node_cnt-(r[cnt]-r[t[x]-1])));
			else printf("%d\n",min(l[cnt]-l[t[x]],node_cnt-(l[cnt]-l[t[x]-1])));
		}
	}
    return 0;
}