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

const int N=200005;
int f[N][19];
int a[N];
int Log2[N];
Finline int Query(const int &l,const int &r)
{
	int k=Log2[r-l+1];
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int maxx[N<<1];
int t[N<<1];
int E[N][2];
void MAIN()
{
	int n;
	read(n);
	int tmp=0;
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		t[i]=a[i];
		chmax(tmp,a[i]);
	}
	int m;
	read(m);
	int qwq=0;
	for(int i=1;i<=m;++i)
	{
		read(E[i][0]),read(E[i][1]);
		t[i+n]=E[i][0];
		chmax(qwq,E[i][0]);
	}
	if(tmp>qwq)
	{
		printf("-1\n");
		return;
	}
	std::sort(t+1,t+n+m+1);
	int len=std::unique(t+1,t+n+m+1)-t-1;
	for(int i=1;i<=n;++i) a[i]=std::lower_bound(t+1,t+len+1,a[i])-t;
	for(int i=n;i>=1;--i)
	{
		f[i][0]=a[i];
		for(int j=1;j<=18&&i+(1<<(j-1))<=n;++j)
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	memset(maxx,0,4*(n+m+3));
	for(int i=1;i<=m;++i)
	{
		E[i][0]=std::lower_bound(t+1,t+len+1,E[i][0])-t;
		chmax(maxx[E[i][0]],E[i][1]);
	}
	for(int i=len-1;i>=1;--i) chmax(maxx[i],maxx[i+1]);
	int cur=1;
	int cnt=0;
	while(cur<=n)
	{
		int l=cur,r=n;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(maxx[Query(cur,mid)]>=mid-cur+1) l=mid;
			else r=mid-1;
		}
		++cnt;
		cur=l+1;
	}
	printf("%d\n",cnt);
}
int main()
{
	for(int i=2;i<=200000;++i) Log2[i]=Log2[i>>1]+1;
	int _;
	read(_);
	while(_--) MAIN();
    return 0;
}