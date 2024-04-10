#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#define maxn 505
using namespace std;
long long n;
long long ans;
long long allsum;
long long a[maxn][maxn];
long long ex,ey;
bool judge()
{
	for(long long i=1;i<=n;i++)
	{
		long long nowsum=0;
		for(long long j=1;j<=n;j++) 
		{
			if(a[i][j]<=0) return false;
			nowsum+=a[i][j];
		}
		if(nowsum!=allsum) return false;
	}
	for(long long j=1;j<=n;j++)
	{
		long long nowsum=0;
		for(long long i=1;i<=n;i++) 
			nowsum+=a[i][j];
		if(nowsum!=allsum) return false;
	}
	
	long long nowsum=0;
	for(long long i=1;i<=n;i++) nowsum+=a[i][i];
	if(nowsum!=allsum) return false;
	nowsum=0;
	for(long long i=1;i<=n;i++) nowsum+=a[i][n+1-i];
	if(nowsum!=allsum) return false;
	return true;
}
int main()
{
	allsum=0;
	scanf("%I64d",&n);
	if(n==1)
	{
		int a;
		scanf("%d",&a);
		printf("1\n");
		return 0;
	}
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=n;j++)
		{
			scanf("%I64d",&a[i][j]);
			if(a[i][j]==0) ex=i,ey=j;
		}
	for(long long i=1;i<=n;i++)
	{
		if(i==ex) continue;
		for(long long j=1;j<=n;j++)
			allsum+=a[i][j]; 
		if(allsum) break;
	}
	long long nowsum=0;
	for(long long j=1;j<=n;j++)
	{
		if(j==ey) continue;
		nowsum+=a[ex][j];
	}	
	a[ex][ey]=allsum-nowsum;

	if(judge())
		printf("%I64d\n",a[ex][ey]); 
	else printf("-1\n");
	
	return 0;
}