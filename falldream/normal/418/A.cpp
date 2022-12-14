#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main()
{
	int n=read(),k=read();
	if(n*(n-1)/2<n*k) return 0*puts("-1");
	printf("%d\n",n*k); 
	for(int i=1;i<=n;++i) for(int j=1;j<=k;++j) printf("%d %d\n",i,(i+j-1)%n+1); 
	return 0;
}