#include <iostream>
#include <stdio.h>
using namespace std;

int P[100001];
int a[100001];
int b[100001];

int main()
{
    int i;
    int n;
    
    cin>>n;
    
    for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for (i=1;i<=n;i++)
    scanf("%d",&b[i]);
    
    for (i=1;i<=n;i++)
    {
        P[ a[i] ]=b[i];
    }
    for (i=1;i<=n;i++)
    {
        printf("%d",P[i]);
        if (i==n)
        printf("\n");
        else
        printf(" ");
    }
    return 0;
}