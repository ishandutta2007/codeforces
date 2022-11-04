#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
int a[101010];
int sum[101010];
int t[101010];
int s[101010];
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		s[i]=s[i-1]+a[i]*t[i];
	}
	int ans=0;
	for(int i=1;i<=n-k+1;i++)
		ans=max(ans,s[i-1]+sum[i+k-1]-sum[i-1]+s[n]-s[i+k-1]);
	printf("%d\n",ans);
	return 0;
}