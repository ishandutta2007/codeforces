#include<iostream>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,L[MN+5],a[MN+5],A[MN+5];
long long sum[MN+5];
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
		if(read()==1)	
		{
			int x=read();
			sum[i]=sum[i-1]+1;L[i]=-1;A[i]=x;
			if(m<MN) a[++m]=x;	
		}
		else 
		{
			int l=read(),c=read();
			sum[i]=sum[i-1]+1LL*l*c;L[i]=l;
			for(int i=1;m<MN&&i<=c;++i)
				for(int j=1;j<=l&&m<MN;++j)
					a[++m]=a[j];
		}
	for(int Q=read();Q;--Q)
	{
		long long x;scanf("%lld",&x);
		int pos=lower_bound(sum+1,sum+n+1,x)-sum;
		if(L[pos]==-1) 	printf("%d ",A[pos]);
		else printf("%d ",a[(x-sum[pos-1]-1)%L[pos]+1]);
	}
	return 0;
}