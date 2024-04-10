#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#define maxn 10005
using namespace std; 
int mos[maxn]={0,1,2,3,4,5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	if(n==1)
	{
		if(a[0]==15) printf("DOWN\n");
		else if(!a[0])printf("UP\n");
		else printf("-1\n"); 
		return 0;
	} 
	if(a[n-1]==0) printf("UP\n");
	else 
	{
		if(a[n-1]==15) 
		{
			printf("DOWN\n");
			return 0;
		}
		
		if(a[n-2]>a[n-1]) printf("DOWN\n");
		else printf("UP\n");
	}
	return 0;
}