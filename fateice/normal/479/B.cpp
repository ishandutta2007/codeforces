#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;
int n,m,a[101],b[1001],c[1001];
int main()
{
    int i,j,k,l;
    cin>>n>>m;
    for(i=1;i<=n;i++)
      cin>>a[i];
    for(i=1;i<=m;i++)
      {
       for(j=2,k=l=1;j<=n;j++)
         if(a[j]>a[k])
           k=j;
         else
           if(a[j]<a[l])
             l=j;
       if(a[k]-a[l]<2)
         break;
       a[k]--;
       a[l]++;
       b[i]=k;
       c[i]=l;
      }
    for(j=2,k=l=1;j<=n;j++)
         if(a[j]>a[k])
           k=j;
         else
           if(a[j]<a[l])
             l=j;
    cout<<a[k]-a[l]<<" "<<i-1<<"\n";
    for(j=1;j<i;j++)
      cout<<b[j]<<" "<<c[j]<<"\n";
    return 0;
}