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
int n,k;
int main()
{
	n=read(),k=read();
	if(n==1)return 0*puts(k?"-1":"1");
	int s=k-(n>>1)+1;
	if(s<=0) return 0*puts("-1");
	printf("%d %d ",s,s<<1);
	for(int i=4,j=2;i<=n;i+=2)
	{
		while(j==s||j==s*2||j-1==s||j-1==s*2) j+=2;
		printf("%d %d ",j,j-1);j+=2;
	}
	if(n&1) puts("1000000000");
	return 0;
}