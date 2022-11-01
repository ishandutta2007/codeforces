#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<bitset>
#include<ctime>
#include<queue>
#include<map>
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
int n,x,y;
bool flag;
int main()
{
	scanf("%d",&n);
	int m=n%10;
	if (m<=5) n-=m;
	  	else n+=10-m;
	printf("%d",n);
	return 0;
}