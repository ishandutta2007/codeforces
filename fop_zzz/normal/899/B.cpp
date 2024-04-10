#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll  long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
int a[2001],q[2001],n,k[20];
int month1[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int month2[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
inline void check()
{
	for(int i=1;i<=3;++i)
	{
		for(int j=(i-1)*12+1;j<=i*12;++j)	
		{
			if(k[i]==1)	q[j]=month1[j-(i-1)*12];
			else	q[j]=month2[j-(i-1)*12];
		}	
	}
	for(int i=1;i<=36-n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(a[j]!=q[i+j-1])	break;
			if(j==n)	{puts("YES");exit(0);}
		}
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)	a[i]=read();
	k[1]=1;k[2]=1;k[3]=1;
	check();
	k[1]=2;k[2]=1;k[3]=1;
	check();
	k[1]=1;k[2]=2;k[3]=1;
	check();
	k[1]=1;k[2]=1;k[3]=2;
	check();
	puts("NO");
}