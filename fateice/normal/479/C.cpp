#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;
int n,a[5001],b[5001],p;
int main()
{
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
      cin>>a[i]>>b[i];
    for(i=1;i<=n;i++)
      for(j=i+1;j<=n;j++)
        if(a[j]<a[i] || (a[j]==a[i] && b[j]<b[i]))
          swap(a[i],a[j]),swap(b[i],b[j]);
    for(i=1;i<=n;i++)
      if(b[i]>a[i] || b[i]<p)
        p=a[i];
      else
        p=b[i];
    printf("%d\n",p);
    return 0;
}