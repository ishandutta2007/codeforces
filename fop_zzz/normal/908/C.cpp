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
int n,r,a[1010];
double tmp[1010];
double sqr(double x){return x*x;}
int main()
{
	n=read();
	r=read();
	For(i,1,n)
	{
		a[i]=read();
		tmp[i]=r;
		for(int j=1;j<i;j++)
			if(a[i]-a[j]<=2*r)	tmp[i]=max(tmp[i],tmp[j]+2*sqrt(sqr(r)-sqr((double)(a[i]-a[j])/2)));
		printf("%.7lf ",tmp[i]);
	}
}