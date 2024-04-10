#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[10];

int main()
{
	scanf("%d%d%d",&a[1],&a[2],&a[3]);
	sort(a+1,a+3+1);
	int ans = a[2] - a[1] + a[3] - a[2];
	printf("%d\n",ans);
	return 0;
}