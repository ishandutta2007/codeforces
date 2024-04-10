#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int x,y,z;
    Int x1,y1,z1;
    Int a[7];
    Int i;
    Int sum=0;
    
    scanf("%I64d %I64d %I64d",&x,&y,&z);
    scanf("%I64d %I64d %I64d",&x1,&y1,&z1);
    
    for (i=1;i<=6;i++)
    {
        scanf("%I64d",&a[i]);
    }
    
    if (z>z1)
    sum=sum+a[4];
    if (z<0)
    sum=sum+a[3];
    if (x>x1)
    sum=sum+a[6];
    if (x<0)
    sum=sum+a[5];
    if (y>y1)
    sum=sum+a[2];
    if (y<0)
    sum=sum+a[1];
    
    printf("%I64d\n",sum);
    return 0;
}