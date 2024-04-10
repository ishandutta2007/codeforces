#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m;
char s[100010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i='a';i<='z';i++)
	  {
	   s[m++]=i;
	   for(j=1;j<=n;j++)
	     {
		  n-=j;
		  s[m++]=i;
		 }
	  }
	printf("%s\n",s);
	return 0;
}