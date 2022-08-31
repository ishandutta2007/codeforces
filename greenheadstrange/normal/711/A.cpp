#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#define maxn 10005
using namespace std;
int n;
char a[maxn][4];
bool flag=false;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		getchar();
		scanf("%c%c",&a[i][0],&a[i][1]);
		if(a[i][0]=='O' && a[i][1]=='O' && !flag)
		{
			flag=true;
			a[i][0]='+';
			a[i][1]='+';
		}
		char now;
		scanf("%c",&now);
		scanf("%c%c",&a[i][2],&a[i][3]);
		if(a[i][2]=='O' && a[i][3]=='O' && !flag)
		{
			flag=true;
			a[i][3]='+';
			a[i][2]='+';
		}
	}
	if(!flag) printf("NO\n");
	else 
	{
		printf("YES\n");
		for(int i=0;i<n;i++)
		{
			printf("%c%c|%c%c",a[i][0],a[i][1],a[i][2],a[i][3]);
			printf("\n");
		}
	}
	return 0;
}