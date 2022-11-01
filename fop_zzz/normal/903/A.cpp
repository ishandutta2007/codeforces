#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll unsigned long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
int n,x;
int main()
{
	n=read();
	For(i,1,n) 
	{
		int x=read(),flag=0;
		for(int i=0;i<=50;i++)if(x>=i*7){
			int k=x-i*7;
			if(k%3==0)flag=1;
		}
		puts(flag?"YES":"NO");
	}
}