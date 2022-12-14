#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,s[25],res[25];
void Add(int x,int ad){for(int i=2;x>1;++i) while(x%i==0) x/=i,s[i]+=ad;}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int x=getchar()-'0';
		for(int j=2;j<=x;++j) Add(j,1);	
	}
	for(;;)
	{
		int g=7;
		for(;g>=0&&!s[g];--g);
		if(g<0) return 0;
		printf("%d",g);
		for(int j=2;j<=g;++j) Add(j,-1);		
	}
	return 0;
}