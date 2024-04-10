// luogu-judger-enable-o2
// Author -- Frame
 
#pragma GCC optimize(2)
 
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
const uint _RAND_MAX_=4294967295u;
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
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}
 
const int N=1000005;
const int mod1=1000000007;
const int mod2=1000000009;
const int base=23333;
ll g[N],f[N];
ll _g[N],_f[N];
ll pw1[N],pw2[N];
char s[N];
char ans[1000005];
int pos;
void hash(char *s,const int &len)
{
	for(int i=1;i<=len;++i)
	{
		f[i]=(f[i-1]*base+s[i])%mod1;
		g[i]=(g[i-1]*base+s[i])%mod2;
	}
}
void extend_(char *s,const int &len)
{
	for(int i=1;i<=len;++i)
	{
		ans[++pos]=s[i];
	}
}
Finline bool check(int x1,int y1,int x2,int y2)
{
	return ((f[y1]-f[x1-1]*pw1[y1-x1+1])%mod1+mod1)%mod1==((_f[y2]-_f[x2-1]*pw1[y2-x2+1])%mod1+mod1)%mod1
	&&     ((g[y1]-g[x1-1]*pw2[y1-x1+1])%mod2+mod2)%mod2==((_g[y2]-_g[x2-1]*pw2[y2-x2+1])%mod2+mod2)%mod2;
}
int main()
{
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=1e6;++i)
	{
		pw1[i]=pw1[i-1]*base%mod1;
		pw2[i]=pw2[i-1]*base%mod2;
	}
	int n;
	read(n);
	int l=read_str(s+1);
	extend_(s,l);
	hash(s,l);
	for(int j=1;j<=pos;++j)
	{
		_f[j]=(_f[j-1]*base+ans[j])%mod1;
		_g[j]=(_g[j-1]*base+ans[j])%mod2;
	}
	int last=l;
	for(int i=2;i<=n;++i)
	{
		l=read_str(s+1);
		hash(s,l);
		int len=0;
		for(int j=min(l,last);j>=1;--j)
		{
			if(check(1,j,last-j+1,last))
			{
				len=j;
				break;
			}
		}
		int t=pos+1;
		extend_(s+len,l-len);
		for(int j=t;j<=pos;++j)
		{
			_f[j]=(_f[j-1]*base+ans[j])%mod1;
			_g[j]=(_g[j-1]*base+ans[j])%mod2;
		}
		last=pos;
	}
	printf("%s\n",ans+1);
    return 0;
}