#include<iostream>
#include<cstdio>
#define MN 500000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,k,c[MN+5];
int main()
{
	n=read();k=read();
	for(int i=1;i<=n;++i) c[i]=read();
	int l=1,r=1e9,mid,res,res2;
	while(l<=r)
	{
		mid=l+r>>1;long long t1=0,t2=0;
		for(int j=n;j;--j) 
			 if(c[j]>mid) t1+=c[j]-mid;	
		else if(c[j]<mid) t2+=mid-c[j];
	//	printf("Solvemax mid=%d t1=%lld t2=%lld\n",mid,t1,t2);
		if(t1<=k&&t1<=t2) res=mid,r=mid-1;
		else l=mid+1;
	}
	l=1,r=1e9;
	while(l<=r)
	{
		mid=l+r>>1;long long t1=0,t2=0;
		for(int j=n;j;--j) 
			 if(c[j]>mid) t1+=c[j]-mid;	
		else if(c[j]<mid) t2+=mid-c[j];
	//	printf("Solvemin mid=%d t1=%lld t2=%lld\n",mid,t1,t2);
		if(t2<=k&&t2<=t1) res2=mid,l=mid+1;
		else r=mid-1;	
	}
//	printf("%d %d\n",res,res2);
	printf("%d\n",res-res2);
	return 0;
}