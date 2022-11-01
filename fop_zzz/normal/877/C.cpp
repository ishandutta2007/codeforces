#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define maxm 10011
#define maxn 511
#define pb push_back
#define ll  long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c<='9'&&c>='0')	t=t*10+c-48,c=getchar();
	return t*f;
}
int n;
int main()
{
	n=read();
	printf("%d\n",n/2+n/2+(n+1)/2);
	for(int i=2;i<=n;i+=2)	printf("%d ",i);
	for(int i=1;i<=n;i+=2)	printf("%d ",i);
	for(int i=2;i<=n;i+=2)	printf("%d ",i);
}