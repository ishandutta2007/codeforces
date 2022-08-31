#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,l,r,p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d%d%d%d",&i,&l,&r,&n);
	while(n--)
	  {
       scanf("%d",&i);
       if(l<i && i<r)
         p++;
      }
    printf("%d\n",p);
	return 0;
}