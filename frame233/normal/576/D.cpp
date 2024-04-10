// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<bitset>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
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

const int N=155;
struct node{
	int x,y;
	int t;
	Finline bool operator < (const node &o)const
	{
		return t<o.t;
	}
}a[N];
int n;
struct matrix{
	std::bitset<N> a[N];
	Finline matrix operator * (const matrix &o)const
	{
		matrix c;
		for(int i=0;i<N;++i) c.a[i].reset();
		for(int i=0;i<n;++i)
		{	
			for(int k=0;k<n;++k)
			{
				if(a[i].test(k))
				{
					c.a[i]|=o.a[k];
				}
			}
		}
		return c;
	}
	void print()
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				printf("%d",a[i].test(j));
			}
			printf("\n");
		}
		printf("\n");
	}
}M,qwq,qaq,_M;
matrix ksm(matrix a,int b)
{
	matrix res=a;
	--b;
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a,b>>=1;
	}
	return res;
}
int main()
{
	int m;
	read(n,m);
	for(int i=0;i<n;++i) M.a[i].set(i),_M.a[i].set(i);
	for(int i=1;i<=m;++i)
	{
		read(a[i].x,a[i].y,a[i].t);
		--a[i].x,--a[i].y;
	}
	std::sort(a+1,a+m+1);
	if(a[1].t)
	{
		printf("Impossible\n");
		return 0;
	}
	a[m+1].t=a[m].t+n+1;
	for(int i=1;i<=m;++i)
	{
		int j=i;
		while(j<m&&a[j+1].t==a[i].t) ++j;
		for(int k=i;k<=j;++k)
		{
			qwq.a[a[k].x].set(a[k].y);
			_M.a[a[k].x].set(a[k].y);
		}
		if((M*ksm(_M,a[j+1].t-a[i].t)).a[0].test(n-1))
		{
			int l=a[i].t+1;
			int r=a[j+1].t;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if((M*ksm(_M,mid-a[i].t)).a[0].test(n-1)) r=mid;
				else l=mid+1;
			}
			printf("%d\n",l);
			return 0;
		}
		else
		{
			M=M*ksm(qwq,a[j+1].t-a[i].t);
		}
		i=j;
	}
	printf("Impossible\n");
	return 0;
}