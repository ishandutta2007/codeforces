#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int maxn=1010;

int a[maxn];
int sum=0,n;

int ans[maxn];
int num=1;

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),sum+=a[i];
	
	int now=a[1];
	ans[1]=1;
	for (int i=2; i<=n; i++) if (a[i]*2<=a[1]) now+=a[i],ans[++num]=i;
	
	if (now*2>sum)
	{
		printf("%d\n",num);
		for (int i=1; i<=num; i++) printf("%d ",ans[i]);
	}
	else printf("0\n");
	
	return 0;
}