#include<bits/stdc++.h>
using namespace std;
int a[1505];
int main()
{
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	a[x]++,a[y]++,a[z]++;
	if(a[1])
		puts("YES");
	else if(a[2]>=2)
		puts("YES");
	else if(a[3]>=3)
		puts("YES");
	else if(a[2]&&a[4]>=2)
		puts("YES");
	else
		puts("NO");
	return 0;
}