#include <iostream>
#include <stdio.h>
using namespace std;

int arr[100001];
int multi[100001];
int powerof2[25];

int main()
{
    int n;
    int i,j,in;
    int total=0;
    
    scanf("%d",&n);
    
    powerof2[0]=1;
    for (i=1;i<=24;i++)
    powerof2[i]=powerof2[i-1]*2;
    
    for (i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for (i=1;i<=n-1;i++)
    {
        total=0;
        
        for (j=1;j<=n;j++)
        multi[j]=999999999;
        
        for (j=n;j>=i+1;j--)
        {
            multi[j]=0;
        }
        for (j=i;j>=1;j--)
        {
            for (in=24;in>=0;in--)
            {
                if (j+powerof2[in]<=n)
                {
                    if (multi[j]>multi[j+powerof2[in]]+1)
                    {
                        multi[j]=multi[j+powerof2[in]]+1;
                    }
                }
            }
            total=total+arr[j]*multi[j];
        }
        printf("%d\n",total);
    }
    return 0;
}