#include<iostream>
#include<cstdio>
#define MN 1048576
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int m,c[50];
long long t,a[MN+5],b[MN+5],p;
long long mul(long long x,long long y){return ((x*y-(long long)((long double)x/p*y+1e-3)*p)%p+p)%p;}
long long pow(long long x,long long k)
{
	long long sum=1;
	for(;k;k>>=1,x=mul(x,x))
		if(k&1)	sum=mul(sum,x);
	return sum;
}

void FWT(long long*a,int l,int r)
{
	if(l==r) return;
	int mid=l+r>>1;
	FWT(a,l,mid);FWT(a,mid+1,r);
	for(int i=0;i<=mid-l;++i)
	{
		long long x=a[l+i],y=a[mid+1+i];
		a[l+i]=(x+y)%p,a[mid+1+i]=(x-y+p)%p;
	} 
}

void IFWT(long long*a,int l,int r)
{
	if(l==r) return;
	int mid=l+r>>1;
	for(int i=0;i<=mid-l;++i)
	{
		long long x=a[l+i],y=a[mid+1+i];
		a[l+i]=(x+y)%p,a[mid+1+i]=(x-y+p)%p;
	} 
	IFWT(a,l,mid);IFWT(a,mid+1,r);
}

int main()
{
	m=read();scanf("%lld",&t);p=1LL*read()*(1<<m);
	for(int i=0;i<1<<m;++i) a[i]=read()%p;
	for(int i=0;i<=m;++i) c[i]=read()%p;
	for(int i=0;i<1<<m;++i)
	{
		int num=0;
		for(int j=0;j<m;++j) if(i&(1<<j)) ++num;
		b[i]=c[num];	
	}
	FWT(a,0,(1<<m)-1);FWT(b,0,(1<<m)-1);
	for(int i=0;i<1<<m;++i) a[i]=mul(a[i],pow(b[i],t));
	IFWT(a,0,(1<<m)-1);
	for(int i=0;i<1<<m;++i) printf("%lld\n",a[i]>>m);
	return 0;
}