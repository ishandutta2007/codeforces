#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define inf 1e9
#define ll long long
#define pa pair<int,int>
#define y1 fuck
#define For(i,j,k) for(ll i=j;i<=k;i++)
#define Dow(i,j,k) for(ll i=k;i>=j;i--)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
ll n,k,a[2001],cnt;
int main()
{
	n=read();k=read();
	For(i,1,n)
		a[i]=read();
	while(1)
	{
		if(a[1]==n)	{writeln(n);return 0;}
		if(a[1]>a[2])	
		{
			cnt++;
			if(cnt==k)	{writeln(a[1]);return 0;}
			ll tmp=a[2];
			For(i,2,n-1)	a[i]=a[i+1];
			a[n]=tmp;
		}
		else
		{
			cnt=1;
			ll tmp=a[1];
			For(i,1,n-1)	a[i]=a[i+1];
			a[n]=tmp;
			if(cnt==k)	{writeln(a[1]);return 0;}
		}
		
	}
}