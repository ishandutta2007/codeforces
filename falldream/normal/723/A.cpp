#include<iostream>
#include<cstdio>
#define INF 2000000000
#define ll long long
#define MAXN  
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int a,b,c;
int main()
{
	a=read();b=read();c=read();
	cout<<max(a,max(b,c))-min(a,min(b,c));
	return 0;
}