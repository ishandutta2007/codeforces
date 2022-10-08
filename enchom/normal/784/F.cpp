#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int arr[111];
int a[1000111];

int main()
{
    int i,j;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for (i=1;i<=3000;i++)
    {
        for (j=1;j<=1000000;j++)
        {
            a[j]++;
        }
    }

    sort(arr+1,arr+1+n);

    for (i=1;i<=n;i++)
    {
        printf("%d",arr[i]);

        if (i!=n)
        printf(" ");
    }
    printf("\n");
}
/// /// ///