#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,a[100001],x[100001],p;
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      {
       scanf("%d",&a[i]);
       x[a[i]]=i;
      }
    for(i=1,j=0;i<=n;i++)
      {
       if(x[i]>x[i-1])
         j++;
       else
         j=1;
       if(j>p)
         p=j;
      }
    printf("%d\n",n-p);
    return 0;
}