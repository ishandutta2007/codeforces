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
int n,lim;long long tot=0;
int main()
{
	n=read();int d=(n+1)>>1;lim=n>>1;
	if(n==5) return 0*puts("1 2 3\n1 3 3\n2 4 2\n4 5 1\n3 4\n3 5");
	for(int i=1;i<d;++i) 
	{
		printf("%d %d %d\n",i,i+1,(int)min(100000LL,1LL*(i+1)*(i+2)/2-2-tot));
		tot=1LL*(i+1)*(i+2)/2-2;
	}
	for(int i=1;i<=d;++i) if(i!=n-i+1) printf("%d %d %d\n",i,n-i+1,1);
	for(int i=d+1;i<n;++i) if(lim) --lim,printf("%d %d\n",i,n);
	if(lim) printf("%d %d\n",n-2,n-1); 
	return 0;
}