#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int a[10],x,y;
inline void js(int &x)
{
	if(x>a[1] && x<=a[2])
	  x=1;
	else if(x>a[2] && x<=a[3])
	  x=2;
	else
	  x=3;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d%d%d%d%d",&a[1],&a[2],&a[3],&x,&y);
	a[2]/=5;
	a[3]/=5;
	sort(a+1,a+3+1);
	js(x);
	js(y);
	if(x==y)
	  printf("YES\n");
	else
	  printf("NO\n");
	return 0;
}