#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,M,sum[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int getc(){char c=getchar();while(c<'a'||c>'z')c=getchar();return c;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,M)sum[i]=0;For(i,1,N)For(j,1,M)sum[j]+=getc();
		For(i,1,N-1)For(j,1,M)sum[j]-=getc();For(i,1,M)putchar(sum[i]);puts("");
	}
	return 0;
}