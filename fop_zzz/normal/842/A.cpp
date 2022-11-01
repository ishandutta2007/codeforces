#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define For(i,j,k)	for(register ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(register ll i=k;i>=j;--i)
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
ll l,r,x,y,k;
int main()
{
	l=read();r=read();
	x=read();y=read();
	k=read();
	For(i,x,y)
	{
		if(l<=i*k&&i*k<=r)	{puts("YES");return 0;}
	}
	puts("NO");
	
}