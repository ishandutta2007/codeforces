#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    double max=0;
    int a[1005],i,l,n;
    scanf("%d %d",&n,&l);
    for(i=0;i<n;i++)
    {
                    scanf("%d",&a[i]);
    }
    sort(a,a+n);
    max = a[0]*2;
    if(max < 2*(l-a[n-1])) max = 2*(l-a[n-1]);
    for(i=n-1;i>0;i--)
    {
                      if(max < a[i]-a[i-1]) max = a[i]-a[i-1];
    }
    printf("%.9f\n",max/2);
    return 0;
}