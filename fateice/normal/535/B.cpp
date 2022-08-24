#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
int main()
{
    long long i,j,k;
    scanf("%d",&n);
    for(i=1,k=0;i<=n;i*=10,k++);
    k=(1<<k)-2;
    for(j=i/10,i=0;j>0;j/=10)
        i+=j*4;
    for(;i<=n;k++)
    {
        for(j=1;j<=i;j*=10)
            if((i%(j*10))/j==4)
            {
                i+=3*j;
                for(j/=10;j>0;j/=10)
                    if((i%(j*10))/j==7)
                        i-=3*j;
                break;
            }
        if(j>i)
            for(i=0;j>0;j/=10)
                i+=4*j;
    }
    printf("%d\n",k);
    return 0;
}