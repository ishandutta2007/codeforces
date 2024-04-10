#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<cmath>
#include<cstring>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define ll  long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
ll n,sum,a[200001],top,ans[200001];
int main()
{
	n=read();
	ll sum=(n+1)*n/2;
	if(sum&1)
	{
		puts("1");sum--;
	}else puts("0");
	sum/=2;
	Dow(i,1,n)
	{
		if(i<=sum)	sum-=i,ans[++top]=i;
		if(sum==0)	break;
	}
	cout<<top<<' ';
	For(i,1,top)	printf("%d ",ans[i]);
}