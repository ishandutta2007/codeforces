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
#define getchar() (*p1++)
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
char ibuf[1<<25],*p1=ibuf;
char obuf[1<<25],buf[23],*T=obuf,*Q=buf;
Finline void print(register ll u)
{
    if(u)
    {
    	if(u<0) *T++='-',u=-u;
        while(u) *Q++=u%10+48,u/=10;
        while(Q!=buf) *T++=*--Q;
    }
    else *T++=48;
    *T++=' ';
}
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
 
const int N=1000005;
int a[N];
int _q[N],_l,_r;
ll ans[N];
ll d[N];
void I_AK_IOI(int w)
{
	int n;
	read(n);
	int len=w-n+1;
	for(int i=1;i<=n;++i) read(a[i]);
	_l=1,_r=0;
	if(len>n)
	{
		for(int i=1;i<=n;++i)
		{
			while(_l!=_r+1&&a[_q[_r]]<a[i]) --_r;
			_q[++_r]=i;
			ans[i]+=max(0,a[_q[_l]]);
		}
		d[n+1]+=max(0,a[_q[_l]]);
		d[w-n+1]-=max(0,a[_q[_l]]);
		for(int i=w-n+1;i<=w;++i)
		{
			while(_l!=_r+1&&i-_q[_l]>=len) ++_l;
			ans[i]+=max(0,a[_q[_l]]);
		}
		return;
	}
	for(int i=1;i<len;++i)
	{
		while(_l!=_r+1&&a[_q[_r]]<a[i]) --_r;
		_q[++_r]=i;
		ans[i]+=max(0,a[_q[_l]]);
	}
	for(int i=len;i<=n;++i)
	{
		while(_l!=_r+1&&a[_q[_r]]<a[i]) --_r;
		_q[++_r]=i;
		while(_l!=_r+1&&i-_q[_l]>=len) ++_l;
		ans[i]+=a[_q[_l]];
	}
	for(int i=n+1;i<=w;++i)
	{
		while(_l!=_r+1&&i-_q[_l]>=len) ++_l;
		ans[i]+=max(0,a[_q[_l]]);
	}
}
int main()
{
	fread(ibuf,1,1<<25,stdin);
	int n,w;
	read(n,w);
	for(int i=1;i<=n;++i)
	{
		I_AK_IOI(w);
	}
	for(int i=1;i<=w;++i)
	{
		d[i]+=d[i-1];
		print(ans[i]+d[i]);
	}
	fwrite(obuf,1,T-obuf,stdout);
    return 0;
}