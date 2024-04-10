#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#define maxn 105
using namespace std; 
int cnt=0;
int a[maxn];
int b[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++)
	{
		char a;
		scanf("%c",&a);
		if(a=='B') b[i]=1;
		else b[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(b[i]!=1) continue;
		if(i!=0)
		{
			if(b[i-1]==1) a[cnt]++;
			else a[++cnt]=1;
		}
		else a[++cnt]=1;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++) printf("%d ",a[i]);
	return 0;
}