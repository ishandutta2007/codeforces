#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define For(i,j,k)	for(register int i=j;i<=k;++i)
#define Dow(i,j,k)	for(register int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define pb push_back
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=(t*10+c-48),c=getchar();
	return t*f;
}
int a[2001],tot,flag,n,m;
int x,y;
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	m=read();
	For(i,1,n)
		For(j,i+1,n)	if(a[i]>a[j])	tot++;
	bool flag=(tot&1);
	For(i,1,m)
	{
		x=read();y=read();swap(x,y);
		if((x-y)*(x-y+1)/2&1)	flag^=1;
		if(flag)	puts("odd");else puts("even");
	}
}