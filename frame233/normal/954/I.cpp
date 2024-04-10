// Author -- Frame

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
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
char obuf[1<<23],*T=obuf;
void print(int u)
{
	*T++=u+48;
	*T++=' ';
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
const int N=125005;
char s[N],t[N];
int a[N],b[N];
int ans[N];
int nxt[N];
void kmp(int n,int m,int cost)
{
	int j=0;
	for(int i=2;i<=m;++i)
	{
		while(j&&b[i]!=b[j+1]) j=nxt[j];
		if(b[i]==b[j+1]) ++j;
		nxt[i]=j;
	}
	j=0;
	for(int i=1;i<=n;++i)
	{
		while(j&&a[i]!=b[j+1]) j=nxt[j];
		if(a[i]==b[j+1]) ++j;
		if(j==m)
		{
			chmin(ans[i],cost);
			j=nxt[j];
		}
	}
}
int main()
{
// 	freopen("a.in","r",stdin);
// 	freopen("a.out","w",stdout);
	memset(ans,63,sizeof(ans));
	int n=read_str(s+1),m=read_str(t+1);
	int _i[6];
	_i[5]=0;
	for(_i[0]=0;_i[0]<=5;++_i[0])
	{
		for(_i[1]=0;_i[1]<=4;++_i[1])
		{
			for(_i[2]=0;_i[2]<=3;++_i[2])
			{
				for(_i[3]=0;_i[3]<=2;++_i[3])
				{
					for(_i[4]=0;_i[4]<=1;++_i[4])
					{
						for(register int i=1;i<=n;++i)
						{
							a[i]=_i[s[i]-97]+s[i]-97;
						}
						for(register int i=1;i<=m;++i)
						{
							b[i]=_i[t[i]-97]+t[i]-97;
						}
						kmp(n,m,(!!_i[0])+(!!_i[1])+(!!_i[2])+(!!_i[3])+(!!_i[4]));
					}
				}
			}
		}
	}
	for(int i=m;i<=n;++i)
	{
		print(ans[i]);
	}
	*T++='\n';
	fwrite(obuf,1,T-obuf,stdout);
	return 0;
}