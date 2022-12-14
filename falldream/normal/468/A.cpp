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
	int n=read();
	if(n<=3) return 0*puts("NO");
	puts("YES");
	if(n&1)
	{
		puts("5 * 4 = 20");
		puts("20 + 3 = 23");
		puts("23 + 2 = 25");
		puts("25 - 1 = 24");
		for(int i=7;i<=n;i+=2) printf("%d - %d = 1\n",i,i-1),puts("24 * 1 = 24");	
	}
	else 
	{
		puts("1 * 2 = 2");
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		for(int i=6;i<=n;i+=2) printf("%d - %d = 1\n",i,i-1),puts("24 * 1 = 24");	
	}
	return 0;
}