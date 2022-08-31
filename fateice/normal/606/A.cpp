#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int a,b,c,x,y,z,p;
int main()
{
    scanf("%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z);
    if(a>=x)
      p+=(a-x)/2;
    else
      p-=(x-a);
    if(b>=y)
      p+=(b-y)/2;
    else
      p-=(y-b);
    if(c>=z)
      p+=(c-z)/2;
    else
      p-=(z-c);
    if(p>=0)
      printf("Yes\n");
    else
      printf("No\n");
    return 0;
}