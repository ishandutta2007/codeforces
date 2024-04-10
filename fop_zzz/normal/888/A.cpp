#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
int n,a[20001],ans;
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	For(i,2,n-1)	if(a[i]>a[i-1]&&a[i]>a[i+1])	ans++;else	if(a[i]<a[i-1]&&a[i]<a[i+1])	ans++;
	cout<<ans<<endl;
}